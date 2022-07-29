/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  App.h
 *  Module:  	  App
 *  Description:  Header file for the app's configurations
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/
 #ifndef APP_H_
 #define APP_H_
 
 /**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Button.h"
 
/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
#define 	LED_1			DIO_CONFIG_LED1_CHANNEL_ID
#define 	LED_2			DIO_CONFIG_LED2_CHANNEL_ID
#define 	LED_3			DIO_CONFIG_LED3_CHANNEL_ID
#define 	BUTTON_1		DIO_CONFIG_SWITCH1_CHANNEL_ID
#define 	BUTTON_2		DIO_CONFIG_SWITCH2_CHANNEL_ID

#define		BLINKING_GPTM	TIMER0_16BIT
 
/**********************************************************************************************************************
*  GLOBAL FUNCTIONS PROTOTYPES
*********************************************************************************************************************/

 
 #endif /* APP_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: App.h
 *********************************************************************************************************************/