/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.c
 *  Module:  	  IntCtrl
 *  Description:  Source file for NVIC Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: IntCrtl_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Initialize NVIC/SCB Module by parsing the configuration 
*			   into NVIC/SCB registers
*******************************************************************************/
void IntCrtl_Init(void)
{
	/* Create a pointer to the configuration structure */
	IntCtrl_ConfigType *ConfigPtr = &IntCtrl_Config;
	
	/* TODO	: Configure Grouping/SubGrouping System in APINT register in SCB */
    SCB_APINT = 0x05FA0000;		/* 8 Group Priority and 1 Sungroup */
    
    /* TODO : Assign Group/Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx registers */
	/* TODO : Enable/Disable based on user configurations in NVIC_ENx and SCB_SYSHNDCTRL registers */
	
	int exc = 0;
	IntCtrl_PriorityLevel priority;
	for (exc = 0; exc < PROCESSOR_EXCEPTIONS_NUM; exc++)
	{
		if (ConfigPtr->exceptions[exc].mode == EXC_DISABLED)
		{
			switch (ConfigPtr->exceptions[exc].exceptionId)
			{
				case RESET:
				case NMI:
				case HARD_FAULT:
					continue;
					break;
				case MEMORY_MANAGE_FAULT:
					SCB_SYSHNDCTRL.MEM = 0;
					break;
				case BUS_FAULT:
					SCB_SYSPRI1.BUS = priority;
					SCB_SYSHNDCTRL.BUS = 1;
					break;
				case USAGE_FAULT:
					SCB_SYSPRI1.USAGE = priority;
					SCB_SYSHNDCTRL.USAGE = 1;
					break;
				case SVCALL:
					SCB_SYSPRI2.SVC = priority;
					break;
				case DEBUG_MONITOR:
					SCB_SYSPRI3.DEBUG = priority;
					break;
				case PENDSV:
					SCB_SYSPRI3.PENDSV = priority;
					break;
				case SYSTICK:
					SCB_SYSPRI3.TICK = priority;
					SYSTICK_STCTRL.INTEN = 1;
					break;
			}
		}
		else if (ConfigPtr->exceptions[exc].mode == EXC_ENABLED)
		{
			priority = ConfigPtr->exceptions[exc].priority;
		
			switch (ConfigPtr->exceptions[exc].exceptionId)
			{
				case RESET:
				case NMI:
				case HARD_FAULT:
					continue;
					break;
				case MEMORY_MANAGE_FAULT:
					SCB_SYSPRI1.MEM = priority;
					SCB_SYSHNDCTRL.MEM = 1;
					break;
				case BUS_FAULT:
					SCB_SYSHNDCTRL.BUS = 0;
					break;
				case USAGE_FAULT:
					SCB_SYSHNDCTRL.USAGE = 0;
					break;
				case SVCALL:
					continue;
					break;
				case DEBUG_MONITOR:
					continue;
					break;
				case PENDSV:
					continue;
					break;
				case SYSTICK:
					SYSTICK_STCTRL.INTEN = 0;
					break;
			}
		}
	}
	
	uint8 irq = 0;
	uint8 irq_id = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		irq_id = ConfigPtr->interrupts[irq].interruptId;
		
		if (ConfigPtr->interrupts[irq].mode == INT_DISABLED)
		{
			/* Disable the interrupt, by setting the corresponding bit in DISx */
			if ((irq_id >= 0) && (irq_id > 32))
				SET_BIT(NVIC_DIS0, irq_id);
			else if ((irq_id > 31) && (irq_id < 64))
				SET_BIT(NVIC_DIS1, irq_id);
			else if ((irq_id > 63) && (irq_id < 96))
				SET_BIT(NVIC_DIS2, irq_id);
			else if ((irq_id > 95) && (irq_id < 128))
				SET_BIT(NVIC_DIS3, irq_id);
			else if ((irq_id > 127) && (irq_id < 139))
				SET_BIT(NVIC_DIS4, irq_id);
			else
				/* [TODO] Reprot the error, then return */
				return;
		}
		else if (ConfigPtr->interrupts[irq].mode == INT_ENABLED)
		{
			/* Assign the priority to every interrupt */
			irq_id = ConfigPtr->interrupts[irq].interruptId;
			uint8 PrixOffset = irq_id / 4;		/* integer value */
			uint8 Intx = irq_id % 4;	/* onteger value from 0 to 3 corresponding to INTA, INTB, INTC, and INTD */
			volatile NVIC_PRIn_BF* PRIx = (volatile NVIC_PRIn_BF*)((volatile uint8*)NVIC_PRIx_BASE + (PrixOffset*4));
			
			priority = ConfigPtr->interrupts[irq].priority;
			
			switch (Intx)
			{
				case 0:
					(*PRIx).INTA = priority;
					break;
				case 1:
					(*PRIx).INTB = priority;
					break;
				case 2:
					(*PRIx).INTC = priority;
					break;
				case 3:
					(*PRIx).INTD = priority;
					break;
			}
			
			/* Enable the interrupt, by setting the corresponding bit in ENx */
			if ((irq_id >= 0) && (irq_id > 32))
				SET_BIT(NVIC_EN0, irq_id);
			else if ((irq_id > 31) && (irq_id < 64))
				SET_BIT(NVIC_EN1, irq_id);
			else if ((irq_id > 63) && (irq_id < 96))
				SET_BIT(NVIC_EN2, irq_id);
			else if ((irq_id > 95) && (irq_id < 128))
				SET_BIT(NVIC_EN3, irq_id);
			else if ((irq_id > 127) && (irq_id < 139))
				SET_BIT(NVIC_EN4, irq_id);
			else
				/* [TODO] Reprot the error, then return */
				return;
		}
	}
}

/*******************************************************************************
* Service Name: IntCtrl_EnableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): IntCtrl_InterruptType InterruptId, IntCtrl_PriorityLevel Priority
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Enable the passing interrupt and assign priority to it
*******************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptType InterruptId, IntCtrl_PriorityLevel Priority)
{
	/* Assign the priority to every interrupt */
	uint8 irq_id = InterruptId;
	uint8 PrixOffset = irq_id / 4;		/* integer value */
	uint8 Intx = irq_id % 4;	/* onteger value from 0 to 3 corresponding to INTA, INTB, INTC, and INTD */
	volatile NVIC_PRIn_BF* PRIx = (volatile NVIC_PRIn_BF*)(CORTEXM4_PERI_BASE_ADDRESS + (uint8*)NVIC_PRIx_BASE + (PrixOffset*4));
	
	
	switch (Intx)
	{
		case 0:
			(*PRIx).INTA = Priority;
			break;
		case 1:
			(*PRIx).INTB = Priority;
			break;
		case 2:
			(*PRIx).INTC = Priority;
			break;
		case 3:
			(*PRIx).INTD = Priority;
			break;
	}
	
	/* Enable the interrupt, by setting the corresponding bit in ENx */
	if ((irq_id >= 0) && (irq_id < 32))
		SET_BIT(NVIC_EN0, irq_id);
	else if ((irq_id > 31) && (irq_id < 64))
		SET_BIT(NVIC_EN1, irq_id);
	else if ((irq_id > 63) && (irq_id < 96))
		SET_BIT(NVIC_EN2, irq_id);
	else if ((irq_id > 95) && (irq_id < 128))
		SET_BIT(NVIC_EN3, irq_id);
	else if ((irq_id > 127) && (irq_id < 139))
		SET_BIT(NVIC_EN4, irq_id);
	else
		/* [TODO] Reprot the error, then return */
		return;
		
	/* Update the configuration structure */	
	uint8 irq = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		if(IntCtrl_Config.interrupts[irq].interruptId == InterruptId)
		{
			IntCtrl_Config.interrupts[irq].mode = INT_ENABLED;
			IntCtrl_Config.interrupts[irq].priority = Priority;
			break;
		}
	}
}

/*******************************************************************************
* Service Name: IntCtrl_DisableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): IntCtrl_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Disable the passing interrupt 
*******************************************************************************/
void IntCtrl_DisableInterrupt(IntCtrl_InterruptType InterruptId)
{
	/* Disable the interrupt, by setting the corresponding bit in DISx */
	if ((InterruptId >= 0) && (InterruptId > 32))
		SET_BIT(NVIC_DIS0, InterruptId);
	else if ((InterruptId > 31) && (InterruptId < 64))
		SET_BIT(NVIC_DIS1, InterruptId);
	else if ((InterruptId > 63) && (InterruptId < 96))
		SET_BIT(NVIC_DIS2, InterruptId);
	else if ((InterruptId > 95) && (InterruptId < 128))
		SET_BIT(NVIC_DIS3, InterruptId);
	else if ((InterruptId > 127) && (InterruptId < 139))
		SET_BIT(NVIC_DIS4, InterruptId);
	else
		/* [TODO] Reprot the error, then return */
		return;
		
	/* Update the configuration structure */	
	uint8 irq = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		if(IntCtrl_Config.interrupts[irq].interruptId == InterruptId)
			IntCtrl_Config.interrupts[irq].mode = INT_DISABLED;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
