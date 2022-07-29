/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Blink.c
 *  Module:  	  Blink
 *  Description:  Source file for Blink Service
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "Blink.h"
#include "Gpt.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  STATIC GLOBAL DATA
 *********************************************************************************************************************/
static Service_TimerChannelType timerChannle;
static Service_DeviceChannel deviceChannel;
static uint8 flag = 0;

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void Blinking_CallBack(void)
{
	Led_Toggle(deviceChannel);
	flag = 1;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Blink_Start(Service_TimerChannelType TimerChannle, Service_DeviceChannel DeviceChannel, Service_TimeType Time, Service_HighPeriodType HighPeriod, Service_LowPeriodType LowPeriod)
{
	/* Led Initialization */
	Led_Init();
	Dio_WriteChannel(DeviceChannel, DIO_LEVEL_HIGH);
	
	/* Blink Init by initializing one of GPTM */
	timerChannle = TimerChannle;
	
	Gpt_Config.channels[TimerChannle].isEnabled = ENABLED;
	Gpt_Config.channels[TimerChannle].mode = GPT_CHANNEL_MODE_ONESHOT;
	Gpt_Config.channels[TimerChannle].notification = Blinking_CallBack;
	
	Gpt_Init(&Gpt_Config.channels[TimerChannle]);
	
	Service_TimeType period = 0;
	
	while (Time > 0)
	{
		/* Delay for  HighPeriod */
		period = HighPeriod;
		
		if (period > Time)
			period = Time;
		
		if (period > 0)
		{
			Gpt_StartTimer(TimerChannle, SECONDS(period));
		
			/* Don't advance */
			while(flag != 1);
			flag = 0;
			Time -= period;
		}
		
		if (Time < 1)
			break;
		
		/* Delay for  LowPeriod */
		period = LowPeriod;
		
		if (period > Time)
			period = Time;

		Gpt_StartTimer(TimerChannle, SECONDS(period));
	
		/* Don't advance */
		while(flag != 1);
		flag = 0;
		Time -= period;
	}
}
 
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
void Blink_Stop(Service_DeviceChannel DeviceChannel)
{
	/* Stop the assosiated */
	Gpt_StopTimer(timerChannle);
	
	/* Turn off the led to stop blinking */
	Led_TurnOff(DeviceChannel);
}

 /**********************************************************************************************************************
 *  END OF FILE: Blink.c
 *********************************************************************************************************************/