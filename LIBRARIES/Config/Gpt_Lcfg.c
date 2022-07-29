/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Lcfg.c
 *  Module:  	  Gpt_Lcfg
 *  Description:  Source file for TM4C123GH6PM MCU - Gpt Module's user configurations at linking stage
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  24/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_regs.h"
#include "Gpt.h"
#include "Dio.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Notification_0(void);
void Gpt_Notification_1(void);
void Gpt_Notification_2(void);
void Gpt_Notification_3(void);
void Gpt_Notification_4(void);
void Gpt_Notification_5(void);
void Gpt_Notification_6(void);
void Gpt_Notification_7(void);
void Gpt_Notification_8(void);
void Gpt_Notification_9(void);
void Gpt_Notification_10(void);
void Gpt_Notification_11(void);

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
int Timer0_Counter = 0;

Gpt_ConfigType Gpt_Config = 
{
	TIMER0_16BIT, DISABLED,  UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_0, 0,
	TIMER1_16BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_1, 0,
	TIMER2_16BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_2, 0,
	TIMER3_16BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_3, 0,
	TIMER4_16BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_4, 0,
	TIMER5_16BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_5, 0,
	TIMER0_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_6, 0,
	TIMER1_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_7, 0,
	TIMER2_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_8, 0,
	TIMER3_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_9, 0,
	TIMER4_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_10, 0,
	TIMER5_32BIT, DISABLED, UP, 16000000, GPT_CHANNEL_MODE_CONTINOUS, Gpt_Notification_11, 0,
};

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Gpt_Notification_0
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_0(void)
{
	// Dio_WriteChannel(DIO_CONFIG_LED1_CHANNEL_ID, DIO_LEVEL_HIGH);
	// Dio_WriteChannel(DIO_CONFIG_LED2_CHANNEL_ID, DIO_LEVEL_LOW);
	Dio_FlipChannel(DIO_CONFIG_LED1_CHANNEL_ID);
	// Gpt_StartTimer(TIMER1_16BIT, SECONDS(1));
	Timer0_Counter++;
}

/*******************************************************************************
* Service Name: Gpt_Notification_1
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_1(void)
{
	// Dio_WriteChannel(DIO_CONFIG_LED1_CHANNEL_ID, DIO_LEVEL_LOW);
	// Dio_WriteChannel(DIO_CONFIG_LED2_CHANNEL_ID, DIO_LEVEL_HIGH);
	Dio_FlipChannel(DIO_CONFIG_LED2_CHANNEL_ID);
	// Gpt_StartTimer(0, SECONDS(2));
	Timer0_Counter++;
}

/*******************************************************************************
* Service Name: Gpt_Notification_2
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_2(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_3
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_3(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_4
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_4(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_5
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_5(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_6
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_6(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_7
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_7(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_8
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_8(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_9
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_9(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_10
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_10(void)
{
	/* Do something! */
}

/*******************************************************************************
* Service Name: Gpt_Notification_11
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Callback Notification Gpt_Notification_<Channel> shall be configurable
				as pointer to user defined functions within the configrations structure.
*******************************************************************************/
void Gpt_Notification_11(void)
{
	/* Do something! */
}

/**********************************************************************************************************************
 *  TIMERS ISR
 *********************************************************************************************************************/
void TIMER0A_Handler(void)
{
	/* Clear Interrupt bit for Timer 0A */
	GPT_GPTMICR(GPT_16BIT_TIMER0_BASE_ADDRESS).TATOCINT = 1;
	
	/* Function Callback */
	if(Gpt_Config.channels[0].notification != NULL_PTR)
	{
		Gpt_Config.channels[0].notification();
	}
}

void TIMER1A_Handler(void)
{
	/* Clear Interrupt bit for Timer 0B */
	GPT_GPTMICR(GPT_16BIT_TIMER1_BASE_ADDRESS).TATOCINT = 1;
	
	/* Function Callback */
	if(Gpt_Config.channels[1].notification != NULL_PTR)
	{
		Gpt_Config.channels[1].notification();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
