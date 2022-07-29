/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_regs.h
 *  Module:  	  Port_regs
 *
 *  Description:  Header file for Port Module's registers map
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef PORT_REGS_H_
#define PORT_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint32 R0		:1;
	uint32 R1		:1;
	uint32 R2		:1;
	uint32 R3		:1;
	uint32 R4		:1;
	uint32 R5		:1;
	uint32			:24;
} SYSCTL_SCGCTIMER_BF;

typedef struct
{
	uint32 TAMR		:2;
	uint32 TACMR	:1;
	uint32 TAAMS	:1;
	uint32 TACDIR	:1;
	uint32 TAMIE	:1;
	uint32 TAWOT	:1;
	uint32 TASNAPS	:1;
	uint32 TAILD	:1;
	uint32 TAPWMIE	:1;
	uint32 TAMRSU	:1;
	uint32 TAPLO	:1;
	uint32 			:20;
} GPT_GPTMTAMR_BF;

typedef struct
{
	uint32 TBMR		:2;
	uint32 TBCMR	:1;
	uint32 TBAMS	:1;
	uint32 TBCDIR	:1;
	uint32 TBMIE	:1;
	uint32 TBWOT	:1;
	uint32 TBSNAPS	:1;
	uint32 TBILD	:1;
	uint32 TBPWMIE	:1;
	uint32 TBMRSU	:1;
	uint32 TBPLO	:1;
	uint32 			:20;
} GPT_GPTMTBMR_BF;

typedef struct
{
	uint32 TAEN		:1;
	uint32 TASTALL	:1;
	uint32 TAEVENT	:2;
	uint32 RTCEN	:1;
	uint32 TAOTE	:1;
	uint32 TAPWML	:1;
	uint32 			:1;
	uint32 TBEN		:1;
	uint32 TBSTALL	:1;
	uint32 TBEVENT	:2;
	uint32 			:1;
	uint32 TBOTE	:1;
	uint32 TBPWML	:1;
	uint32 			:17;
} GPT_GPTMCTL_BF;

typedef struct
{
	uint32 TATOIM	:1;
	uint32 CAMIM	:1;
	uint32 CAEIM	:1;
	uint32 RTCIM	:1;
	uint32 TAMIM	:1;
	uint32 			:3;
	uint32 TBTOIM	:1;
	uint32 CBMIM	:1;
	uint32 CBEIM	:1;
	uint32 TBMIM	:1;
	uint32 			:4;
	uint32 WUEIM	:1;
	uint32 			:15;
} GPT_GPTMIMR_BF;

typedef struct
{
	uint32 TATORIS	:1;
	uint32 CAMRIS	:1;
	uint32 CAERIS	:1;
	uint32 RTCRIS	:1;
	uint32 TAMRIS	:1;
	uint32			:3;
	uint32 TBTORIS	:1;
	uint32 CBMRIS	:1;
	uint32 CBERIS	:1;
	uint32 TBMRIS	:1;
	uint32			:4;
	uint32 WUERIS	:1;
} GPT_GPTMRIS_BF;

typedef struct
{
	uint32 TATOCINT	:1;
	uint32 CAMCINT	:1;
	uint32 CAECINT	:1;
	uint32 RTCCINT	:1;
	uint32 TAMCINT	:1;
	uint32 			:3;
	uint32 TBTOCINT	:1;
	uint32 CBMCINT	:1;
	uint32 CBECINT	:1;
	uint32 TBMCINT	:1;
	uint32 			:4;
	uint32 WUECINT	:1;
	uint32 			:15;
} GPT_GPTMICR_BF;

typedef struct
{
	uint32 TAPSR	:8;
	uint32 TAPSRH	:8;
	uint32			:16;
} GPT_GPTMTAPR_BF;

typedef struct
{
	uint32 TBPSR	:8;
	uint32 TBPSRH	:8;
	uint32			:16;
} GPT_GPTMTBPR_BF;
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define	GPT_16BIT_TIMER0_BASE_ADDRESS						0x40030000
#define	GPT_16BIT_TIMER1_BASE_ADDRESS						0x40031000
#define	GPT_16BIT_TIMER2_BASE_ADDRESS						0x40032000
#define	GPT_16BIT_TIMER3_BASE_ADDRESS						0x40033000
#define	GPT_16BIT_TIMER4_BASE_ADDRESS						0x40034000
#define	GPT_16BIT_TIMER5_BASE_ADDRESS						0x40035000

#define GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS					0x40036000
#define GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS					0x40037000
#define GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS					0x4004C000
#define GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS					0x4004D000
#define GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS					0x4004E000
#define GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS					0x4004F000

#define GPT_GPTMCFG(BASE)									(*((volatile uint32*)(BASE)))

#define GPT_GPTMTAMR(BASE)									(*((volatile GPT_GPTMTAMR_BF*)(BASE+0x004)))
#define GPT_GPTMTBMR(BASE)									(*((volatile GPT_GPTMTBMR_BF*)(BASE+0x008)))
#define GPT_GPTMCTL(BASE)									(*((volatile GPT_GPTMCTL_BF*)(BASE+0x00C)))
#define GPT_GPTMIMR(BASE)									(*((volatile GPT_GPTMIMR_BF*)(BASE+0x018)))
#define GPT_GPTMRIS(BASE)									(*((volatile GPT_GPTMRIS_BF*)(BASE+0x01C)))
#define GPT_GPTMICR(BASE)									(*((volatile GPT_GPTMICR_BF*)(BASE+0x024)))
#define GPT_GPTMTAILR(BASE)									(*((volatile uint32*)(BASE+0x028)))
#define GPT_GPTMTBILR(BASE)									(*((volatile uint32*)(BASE+0x02C)))
#define GPT_GPTMTAPR(BASE)									(*((volatile uint32*)(BASE+0x038)))
#define GPT_GPTMTBPR(BASE)									(*((volatile uint32*)(BASE+0x03C)))
#define GPT_GPTMTAV(BASE)									(*((volatile uint32*)(BASE+0x050)))
#define GPT_GPTMTBV(BASE)									(*((volatile uint32*)(BASE+0x054)))

#define SYSCTL_BASE_ADDRESS									0x400FE000

#define SYSCTL_RCGCTIMER									(*((volatile SYSCTL_SCGCTIMER_BF*)(SYSCTL_BASE_ADDRESS+0x604)))
#define SYSCTL_RCGCWTIMER									(*((volatile SYSCTL_SCGCTIMER_BF*)(SYSCTL_BASE_ADDRESS+0x65C)))


#endif  /* PORT_REGS_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port_regs.h
 *********************************************************************************************************************/
