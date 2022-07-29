/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Button.h
 *  Module:  	  Button
 *  Description:  Header file for Button driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
 #ifndef BUTTON_H_
 #define BUTTON_H_
 
/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Dio.h"

/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef Dio_ChannelType Button_ButtonChannelType;
typedef Port_PinInternalAttachType Button_ButtonAttachType;

typedef enum
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED = 1
} Button_State;

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/
/*******************************************************************************
* Service Name: Button_Init
* Service ID[hex]: 0x00
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
void Button_Init(void);
 
/*******************************************************************************
* Service Name: Button_GetState
* Service ID[hex]: 0x01
* Sync/Async: Asynchronous
* Reentrancy: Reentrant
* Parameters (in): ButtonChannel - An identifier for the dedicated Button
* 				   ButtonAttach  - Identification for the connection type (PULL_UP or PULL_DOWN)
* Parameters (inout): None
* Parameters (out): None
* Return value: Button_State
* Description: Function to get the state of the Button using Dio MCAL
*******************************************************************************/
Button_State Button_GetState(Button_ButtonChannelType ButtonChannel, Button_ButtonAttachType ButtonAttach);

 #endif /* BUTTON_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Button.h
 *********************************************************************************************************************/