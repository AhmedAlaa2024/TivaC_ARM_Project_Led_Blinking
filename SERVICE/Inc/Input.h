/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Input.h
 *  Module:  	  Input
 *  Description:  Header file for Input Service
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
#ifndef Input_H_
#define Input_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Service_Types.h"
#include "Button.h"
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Input_GetNumOfPresses
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): MasterDeviceChannel - The device which will start listening to the input pulses
*				   MasterStatusChannel - The device will make a slight response for the master to give the app some interactivity
*				   SlaveDeviceChannel - The device which will trigger the input pulses
*				   SlaveStatusChannel - The device will make a slight response for the slave to give the app some interactivity
* 				   ButtonAttach  - Identification for the connection type (PULL_UP or PULL_DOWN)
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected devices and get the number of pulses as input
*******************************************************************************/
uint8 Input_GetNumOfPresses(Service_DeviceChannel MasterDeviceChannel, Service_DeviceChannel MasterStatusChannel,\
							Service_DeviceChannel SlaveDeviceChannel, Service_DeviceChannel SlaveStatusChannel,\
							Button_ButtonAttachType ButtonAttach);
 
#endif /* Input_H_ */
/**********************************************************************************************************************
*  END OF FILE: Input.h
*********************************************************************************************************************/