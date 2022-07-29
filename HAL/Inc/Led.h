/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Led.h
 *  Module:  	  Led
 *  Description:  Header file for Led driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
 
/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef Dio_ChannelType Led_LedChannelType;
 
 /**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
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
 void Led_Init(void);
 
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
 void Led_TurnOn(Led_LedChannelType LedChannel);
 
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
 void Led_TurnOff(Led_LedChannelType LedChannel);
 
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
void Led_Toggle(Led_LedChannelType LedChannel);

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
void Led_RefreshOutput(Led_LedChannelType LedChannel);
 
 #endif /* LED_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/