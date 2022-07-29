/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio.c
 *  Module:  	  Dio
 *  Description:  Source file for Dio Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  20/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Dio_regs.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/*******************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function for DIO read Channel API
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return DIO_LEVEL_ERROR;
	
	switch (configList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
				return DIO_LEVEL_HIGH;
			else
				return DIO_LEVEL_LOW;
			break;	/* Unreachable */
			
		default:
			return DIO_LEVEL_ERROR;
			break; /* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType, Level - Dio_LevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Channel API
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return;
	
	switch (configList.channels[ChannelId].portId)
	{
		case PORTA:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTB:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTC:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTD:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTE:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
			
		case PORTF:
			if (Level == DIO_LEVEL_HIGH)
				SET_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId);
			break;	/* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function for DIO flip Channel, then read Channel API
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	/* Index Error */
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
		return DIO_LEVEL_ERROR;
	
	switch (configList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTA_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTB_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTC_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTD_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTE_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId) == DIO_LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTF_GPIODATA, configList.channels[ChannelId].pinId);
				return DIO_LEVEL_HIGH;
			}
			break;	/* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - Dio_PortType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function for DIO read Port API
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{	
	switch (configList.channels[PortId].portId)
	{
		case PORTA:
			return (Dio_PortLevelType)GPIO_PORTA_GPIODATA;
			break;	/* Unreachable */
			
		case PORTB:
			return (Dio_PortLevelType)GPIO_PORTB_GPIODATA;
			break;	/* Unreachable */
			
		case PORTC:
			return (Dio_PortLevelType)GPIO_PORTC_GPIODATA;
			break;	/* Unreachable */
			
		case PORTD:
			return (Dio_PortLevelType)GPIO_PORTD_GPIODATA;
			break;	/* Unreachable */
			
		case PORTE:
			return (Dio_PortLevelType)GPIO_PORTE_GPIODATA;
			break;	/* Unreachable */
			
		case PORTF:
			return (Dio_PortLevelType)GPIO_PORTF_GPIODATA;
			break;	/* Unreachable */
	}
}

/*******************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - Dio_PortType, Level - Dio_PortLevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Port API
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{	
	switch (configList.channels[PortId].portId)
	{
		case PORTA:
			GPIO_PORTA_GPIODATA = Level;
			break;	/* Unreachable */
			
		case PORTB:
			GPIO_PORTB_GPIODATA = Level;
			break;	/* Unreachable */
			
		case PORTC:
			GPIO_PORTC_GPIODATA = Level;
			break;	/* Unreachable */
			
		case PORTD:
			GPIO_PORTD_GPIODATA = Level;
			break;	/* Unreachable */
			
		case PORTE:
			GPIO_PORTE_GPIODATA = Level;
			break;	/* Unreachable */
			
		case PORTF:
			GPIO_PORTF_GPIODATA = Level;
			break;	/* Unreachable */
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/