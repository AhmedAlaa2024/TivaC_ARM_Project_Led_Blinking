/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl_Types.h
 *  Module:  	  IntCtrl_Types
 *
 *  Description:  Header file for TM4C123GH6PM MCU - NVIC Module's Types
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H_
#define INTCTRL_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef uint8 IntCtrl_PriorityLevel;

typedef enum
{
	RESET = 0,
	NMI = 1,
	HARD_FAULT = 2,
	MEMORY_MANAGE_FAULT = 3,
	BUS_FAULT = 4,
	USAGE_FAULT = 5,
	SVCALL = 6,
	DEBUG_MONITOR = 7,
	PENDSV = 8,
	SYSTICK = 9
} IntCtrl_ExceptionType;

typedef enum
{
	/*** 16/32-Bit Timers ***/
	TIMER_16_32_BIT_0A = 19,
	TIMER_16_32_BIT_0B = 20,
	TIMER_16_32_BIT_1A = 21,
	TIMER_16_32_BIT_1B = 22,
	TIMER_16_32_BIT_2A = 23,
	TIMER_16_32_BIT_2B = 24,
	TIMER_16_32_BIT_3A = 35,
	TIMER_16_32_BIT_3B = 36,
	TIMER_16_32_BIT_4A = 70,
	TIMER_16_32_BIT_4B = 71,
	TIMER_16_32_BIT_5A = 92,
	TIMER_16_32_BIT_5B = 93,
	
	/*** 32/64-Bit Timers ***/
	TIMER_32_64_BIT_0A = 94,
	TIMER_32_64_BIT_0B = 95,
	TIMER_32_64_BIT_1A = 96,
	TIMER_32_64_BIT_1B = 97,
	TIMER_32_64_BIT_2A = 98,
	TIMER_32_64_BIT_2B = 99,
	TIMER_32_64_BIT_3A = 100,
	TIMER_32_64_BIT_3B = 101,
	TIMER_32_64_BIT_4A = 102,
	TIMER_32_64_BIT_4B = 103,
	TIMER_32_64_BIT_5A = 104,
	TIMER_32_64_BIT_5B = 105
} IntCtrl_InterruptType;

typedef enum
{
	EXC_DISABLED = 0,
	EXC_ENABLED  = 1
} IntCtrl_ExceptionModeType;

typedef enum
{
	INT_DISABLED = 0,
	INT_ENABLED  = 1
} IntCtrl_InterruptModeType;

typedef struct
{
	IntCtrl_ExceptionType exceptionId;
	IntCtrl_ExceptionModeType mode;
	IntCtrl_PriorityLevel priority;
} IntCtrl_ExceptionConfigType;

typedef struct
{
	IntCtrl_InterruptType interruptId;
	IntCtrl_InterruptModeType mode;
	IntCtrl_PriorityLevel priority;
} IntCtrl_InterruptConfigType;
 
#endif  /* INTCTRL_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
