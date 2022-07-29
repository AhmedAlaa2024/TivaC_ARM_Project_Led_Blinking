/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Blink.h
 *  Module:  	  Blink
 *  Description:  Header file for Blink Service
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
#ifndef BLINK_H_
#define BLINK_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Service_Types.h"
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Blink_Start
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): TimerChannle - The Timer used for blinking timing
*				   DeviceChannel - The device which will blink
*				   Time - How long the blinking should be,
*				   HighPeriod - How long to stay high
*				   LowPeriod - How long to stay low
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize and start blinking service
*******************************************************************************/
void Blink_Start(Service_TimerChannelType TimerChannle, Service_DeviceChannel DeviceChannel, Service_TimeType Time, Service_HighPeriodType HighPeriod, Service_LowPeriodType LowPeriod);
 
/*******************************************************************************
* Service Name: Blink_Stop
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): DeviceChannel - The device which is blinking
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to stop blinking
*******************************************************************************/
void Blink_Stop(Service_DeviceChannel DeviceChannel);
 
#endif /* LED_H_ */
/**********************************************************************************************************************
*  END OF FILE: Led.h
*********************************************************************************************************************/