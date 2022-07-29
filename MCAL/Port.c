/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.c
 *  Module:  	  Port
 *  Description:  Source file for Port Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_regs.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Set the passed initial values for the GPIO pin
*              - Setup the mode of the GPIO pin
*              - Setup the internal resistor for i/p pin
*              - Setup the output current in case of output pin
*******************************************************************************/
void Port_Init(const Port_configType* ConfigPtr)
{
	/* Check that ConfigPtr is not pointing to NULL */
	if (ConfigPtr == NULL_PTR)
	{
		/* TODO: Report the error using Det_ReportError */
		return;
	}
	
	volatile uint32* Portptr = NULL_PTR; /* Used to traverse on all ports */
	
	uint8 pin = 0;
	for (pin = 0; pin < TOTAL_PORT_NUMBER_OF_PINS; pin++)
	{
		/* To not configure all the channels by the default, otherwise it is requested */
		if (ConfigPtr->pinConfigType[pin].isEnabled == CHANNEL_DISABLED)
			continue;
		
		/* Enable the clock for the dedicated port */
		switch (ConfigPtr->pinConfigType[pin].portType)
		{
			case PORTA:
				Portptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOA = 1;
				break;
			case PORTB:
				Portptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOB = 1;
				break;
			case PORTC:
				Portptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOC = 1;
				break;
			case PORTD:
				Portptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOD = 1;
				break;
			case PORTE:
				Portptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOE = 1;
				break;
			case PORTF:
				Portptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOF = 1;
				break;
		}
	
		/* Special manipulation, in case of PD7, PF0 */
		if ( \
			((ConfigPtr->pinConfigType[pin].portType == PORTD) && (ConfigPtr->pinConfigType[pin].pinType == PIN7)) \
			|| ((ConfigPtr->pinConfigType[pin].portType == PORTF) && (ConfigPtr->pinConfigType[pin].pinType == PIN0)) \
		)
		{
			/* Unlock the GPIOCR register */
			*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOLOCK_OFFSET) = 0x4C4F434B;
			
			/* Configure GPIOCR bits to allow changes on the dedicated pin */
			SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOCR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
		}
		/* Special manipulation, in case of PC0 to PC3 (JTAG/SWD) */
		else if (((ConfigPtr->pinConfigType[pin].portType == PORTC) && (ConfigPtr->pinConfigType[pin].pinType < PIN4)))
		{
			/* [WARNING]
			 * Do nothing!! Because any changing of PC0->PC3 configurations will disable JTAG/SWD
			 * So, we will not be able to flash or debug the code anymore!
			 */
			 continue;
		}
		else
		{
			/* Do Nothing!! */
			/* All the other pins don't require any unlockig or committing any registers */
		}
		
		switch (ConfigPtr->pinConfigType[pin].pinModeType)
		{
			case DIO_MODE:
				/* Clear the corresponding bit to the dedicated pin in GPIOAMSEL */
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAMSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				/* Clear the corresponding bit to the dedicated pin in GPIOAFSEL */
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAFSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				/* Clear the PMCx bits for the dedicated pin */
				*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPCTL_OFFSET) &= ~(0x0000000F << (ConfigPtr->pinConfigType[pin].pinType * 4));
				
				/* Set the corresponding bit of the dedicated pin in GPIODEN register to enable the digital functionality to this pin */
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODEN_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				break;
			case ICU_MODE:
				/* [TODO] Setup the configurations for ICU_MODE */
				break;
			case ADC_MODE:
				/* [TODO] Setup the configurations for ADC_MODE */
				break;
			default: /* Default is DIO_MODE */
				/* Clear the corresponding bit to the dedicated pin in GPIOAMSEL */
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAMSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				/* Clear the corresponding bit to the dedicated pin in GPIOAFSEL */
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAFSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				/* Clear the PMCx bits for the dedicated pin */
				*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPCTL_OFFSET) &= ~(0x0000000F << (ConfigPtr->pinConfigType[pin].pinType * 4));
				
				/* Set the corresponding bit of the dedicated pin in GPIODEN register to enable the digital functionality to this pin */
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODEN_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				break;
		}
		
		if (ConfigPtr->pinConfigType[pin].pinDirectionType == OUTPUT)
		{
			/* Set the corresponding bit of the dedicated pin in GPIODIR */
			SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODIR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			
			switch (ConfigPtr->pinConfigType[pin].pinOutputCurrentType)
			{
				case DRIVE_2mA:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case DRIVE_4mA:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case DRIVE_8mA:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				default:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
			}
			
			if (ConfigPtr->pinConfigType[pin].pinLevelType == PIN_LEVEL_HIGH)
			{
				/* Set the corresponding bit of the dedicated pin in GPIODATA */
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODATA_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			}
			else
			{
				/* Clear the corresponding bit of the dedicated pin in GPIODATA */
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODATA_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			}
		}
		else if (ConfigPtr->pinConfigType[pin].pinDirectionType == INPUT)
		{
			/* Set the corresponding bit of the dedicated pin in GPIODIR */
			CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODIR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
		
			switch (ConfigPtr->pinConfigType[pin].pinInternalAttachType)
			{
				case PULL_UP:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case PULL_DOWN:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case OPEN_DRAIN:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case SLEW_RATE:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				default: /* Default is PULL_UP */
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
			}
		}
		else
		{
			/* TODO: Report the error using Det_ReportError */
			return;
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/