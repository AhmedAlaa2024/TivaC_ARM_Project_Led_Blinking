/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Led.c
 *  Module:  	  Led
 *  Description:  Source file for Led driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Port.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Led_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
void Led_Init(void)
{
	Port_Init(&Port_ConfigType);
}
 
/*******************************************************************************
* Service Name: Led_TurnOn
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn on the Led using Dio MCAL
*******************************************************************************/
void Led_TurnOn(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, DIO_LEVEL_HIGH);
}
 
/*******************************************************************************
* Service Name: Led_TurnOff
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn off the Led using Dio MCAL
*******************************************************************************/
void Led_TurnOff(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, DIO_LEVEL_LOW);
}

/*******************************************************************************
* Service Name: Led_Toggle
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to toggle the Led using Dio MCAL
*******************************************************************************/
void Led_Toggle(Led_LedChannelType LedChannel)
{
	Dio_FlipChannel(LedChannel);
}

/*******************************************************************************
* Service Name: Led_RefreshOutput
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to refresh the Led's state using Dio MCAL
*******************************************************************************/
void Led_RefreshOutput(Led_LedChannelType LedChannel)
{
	/* Read the current state */
    Dio_LevelType state = Dio_ReadChannel(LedChannel);
	
	/* Re-write the same state */
    Dio_WriteChannel(LedChannel, state);
}
 /**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/