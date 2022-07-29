/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Input.c
 *  Module:  	  Input
 *  Description:  Source file for Input Service
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "Input.h"
#include "Led.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  STATIC GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
uint8 Input_GetNumOfPresses(Service_DeviceChannel MasterDeviceChannel, Service_DeviceChannel MasterStatusChannel, Service_DeviceChannel SlaveDeviceChannel, Service_DeviceChannel SlaveStatusChannel, Button_ButtonAttachType ButtonAttach)
{
	/* Initialize all the devices */
	Led_Init();
	Button_Init();
	
	uint8 pulses = 0;
	
	/* Don't advance until the user give an acka that he will enter an input */
	while (Button_GetState(MasterDeviceChannel, ButtonAttach) == BUTTON_RELEASED);
	
	/* Let the user now, we were listening to him */
	Led_TurnOn(MasterStatusChannel);
	
	/* wait a little bit */
	for(int i = 0; i < 1000000; i++);
	
	/* Revert all changes */
	Led_TurnOff(MasterStatusChannel);
	
	for(;;)
	{
		if (Button_GetState(MasterDeviceChannel, ButtonAttach) == BUTTON_PRESSED)
		{
			/* Let the user now, we were listening to him */
			Led_TurnOn(MasterStatusChannel);
			
			/* wait a little bit */
			for(int i = 0; i < 1000000; i++);
			
			/* Revert all changes */
			Led_TurnOff(MasterStatusChannel);
			
			break;
		}
		else if (Button_GetState(SlaveDeviceChannel, ButtonAttach) == BUTTON_PRESSED)
		{
			/* Let the user now, we are listening to him */
			Led_TurnOn(SlaveStatusChannel);
			
			/* wait a little bit */
			for(int i = 0; i < 1000000; i++);
			
			/* Revert all changes */
			Led_TurnOff(SlaveStatusChannel);
			
			/* Accumulate the number of pulses */
			pulses++;
		}
	}
	
	/* wait a little bit */
	for(int i = 0; i < 1000000; i++);
	
	/* Pass the number of pulses */
	return pulses;
}

 /**********************************************************************************************************************
 *  END OF FILE: Input.c
 *********************************************************************************************************************/