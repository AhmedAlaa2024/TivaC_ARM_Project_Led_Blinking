/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl_Lcfg.c
 *  Module:  	  IntCtrl_Lcfg
 *  Description:  Source file for IntCtrl Module's user configurations at linking stage
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
IntCtrl_ConfigType IntCtrl_Config = 
{
	/**************************** EXCEPTIONS ****************************/
	RESET, EXC_ENABLED, -3,
	NMI, EXC_ENABLED, -2,
	HARD_FAULT, EXC_ENABLED, -1,
	MEMORY_MANAGE_FAULT, EXC_ENABLED, 0,
	BUS_FAULT, EXC_ENABLED, 0,
	USAGE_FAULT, EXC_ENABLED, 0,
	SVCALL, EXC_ENABLED, 6,
	DEBUG_MONITOR, EXC_ENABLED, 1,
	PENDSV, EXC_ENABLED, 6,
	SYSTICK, EXC_ENABLED, 6,
	
	/******************************** IRQ ********************************/
	TIMER_16_32_BIT_0A, INT_DISABLED, 0,
	TIMER_16_32_BIT_0B, INT_DISABLED, 0,
	TIMER_16_32_BIT_1A, INT_DISABLED, 0,
	TIMER_16_32_BIT_1B, INT_DISABLED, 0,
	TIMER_16_32_BIT_2A, INT_DISABLED, 0,
	TIMER_16_32_BIT_2B, INT_DISABLED, 0,
	TIMER_16_32_BIT_3A, INT_DISABLED, 0,
	TIMER_16_32_BIT_3B, INT_DISABLED, 0,
	TIMER_16_32_BIT_4A, INT_DISABLED, 0,
	TIMER_16_32_BIT_4B, INT_DISABLED, 0,
	TIMER_16_32_BIT_5A, INT_DISABLED, 0,
	TIMER_16_32_BIT_5B, INT_DISABLED, 0,
	TIMER_32_64_BIT_0A, INT_DISABLED, 0,
	TIMER_32_64_BIT_0B, INT_DISABLED, 0,
	TIMER_32_64_BIT_1A, INT_DISABLED, 0,
	TIMER_32_64_BIT_1B, INT_DISABLED, 0,
	TIMER_32_64_BIT_2A, INT_DISABLED, 0,
	TIMER_32_64_BIT_2B, INT_DISABLED, 0,
	TIMER_32_64_BIT_3A, INT_DISABLED, 0,
	TIMER_32_64_BIT_3B, INT_DISABLED, 0,
	TIMER_32_64_BIT_4A, INT_DISABLED, 0,
	TIMER_32_64_BIT_4B, INT_DISABLED, 0,
	TIMER_32_64_BIT_5A, INT_DISABLED, 0,
	TIMER_32_64_BIT_5B, INT_DISABLED, 0
};

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
