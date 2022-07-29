 /**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Mcu_Hw.h
 *  Module:  	  Mcu_Hw
 *
 *  Description:  Header file for the microcontroller hardware specifications like registers' definitions
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  18/07/2022
 *********************************************************************************************************************/
#ifndef MCU_HW_H_
#define MCU_HW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 typedef struct
{
    uint32 B0			:1;
    uint32 B1			:1;
    uint32 B2			:1;
    uint32 B3			:1;
    uint32 B4			:1;
    uint32 B5			:1;
    uint32 B6			:1;
    uint32 B7			:1;
    uint32 B8			:1;
    uint32 B9			:1;
    uint32 B10			:1;
    uint32 B11			:1;
    uint32 B12			:1;
    uint32 B13			:1;
    uint32 B14			:1;
    uint32 B15			:1;
    uint32 B16			:1;
    uint32 B17			:1;
    uint32 B18			:1;
    uint32 B19			:1;
    uint32 B20			:1;
    uint32 B21			:1;
    uint32 B22			:1;
    uint32 B23			:1;
    uint32 B24			:1;
    uint32 B25			:1;
    uint32 B26			:1;
    uint32 B27			:1;
    uint32 B28			:1;
    uint32 B29			:1;
    uint32 B30			:1;
    uint32 B31			:1;
} Bit_Field_Type;

typedef struct
{
	uint32 VECACT		:8;
	uint32				:3;
	uint32 RETBASE		:1;
	uint32 VECPEND		:8;
	uint32				:2;
	uint32 ISRPEND		:1;
	uint32 ISRPRE		:1;
	uint32 				:1;
	uint32 PENDSTCLR	:1;
	uint32 PENDSTSET	:1;
	uint32 UNPENDSV		:1;
	uint32 PENDSV		:1;
	uint32				:2;
	uint32 NMISET		:1;
} SCB_INTCTRL_BF;	/* BF: Bit Field */

typedef union
{
	uint32			R;
	SCB_INTCTRL_BF	BF;
} SCB_INTCTRL_Tag;

typedef struct
{
	uint32				:5;
	uint32 INTA			:3;
	uint32				:5;
	uint32 INTB			:3;
	uint32				:5;
	uint32 INTC			:3;
	uint32				:5;
	uint32 INTD			:3;
} NVIC_PRIn_BF;

typedef struct
{
	uint32 				:5;
	uint32 MEM			:3;
	uint32				:5;
	uint32 BUS			:3;
	uint32				:5;
	uint32 USAGE		:3;
	uint32				:8;
} SCB_SYSPRI1_BF;	/* BF: Bit Field */

typedef struct
{
	uint32 				:29;
	uint32 SVC			:3;
} SCB_SYSPRI2_BF;	/* BF: Bit Field */

typedef struct
{
	uint32 				:5;
	uint32 DEBUG		:3;
	uint32				:13;
	uint32 PENDSV		:3;
	uint32				:5;
	uint32 TICK			:3;
} SCB_SYSPRI3_BF;	/* BF: Bit Field */

typedef struct
{
	uint32 MEMA			:1;
	uint32 BUSA			:1;
	uint32 				:1;
	uint32 USGA			:1;
	uint32 				:3;
	uint32 SVCA			:1;
	uint32 MON			:1;
	uint32 				:1;
	uint32 PNDSV		:1;
	uint32 TICK			:1;
	uint32 USAGEP		:1;
	uint32 MEMP			:1;
	uint32 BUSP			:1;
	uint32 SVC			:1;
	uint32 MEM			:1;
	uint32 BUS			:1;
	uint32 USAGE		:1;
	uint32 				:13;
} SCB_SYSHNDCTRL_BF;	/* BF: Bit Field */

typedef struct
{
	uint32 ENBLE		:1;
	uint32 INTEN		:1;
	uint32 CLK_SRC		:1;
	uint32 				:13;
	uint32 COUNT		:1;
	uint32 				:15;
} SYSTICK_STCTRL_BF;	/* BF: Bit Field */
 
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define F_CPU																		16U		/* In MHz */

#define	CORTEXM4_PERI_BASE_ADDRESS							0xE000E000
#define SCB_APINT											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
#define SCB_INTCTRL											(*((volatile SCB_INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
#define NVIC_EN0											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)))
#define NVIC_EN1											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104)))
#define NVIC_EN2											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108)))
#define NVIC_EN3											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C)))
#define NVIC_EN4											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110)))
#define NVIC_DIS0											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180)))
#define NVIC_DIS1											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184)))
#define NVIC_DIS2											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188)))
#define NVIC_DIS3											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C)))
#define NVIC_DIS4											(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190)))
#define NVIC_PRIx_BASE										0x400
#define SCB_SYSPRI1											(*((volatile SCB_SYSPRI1_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18)))
#define SCB_SYSPRI2											(*((volatile SCB_SYSPRI2_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C)))
#define SCB_SYSPRI3											(*((volatile SCB_SYSPRI3_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20)))
#define SCB_SYSHNDCTRL										(*((volatile SCB_SYSHNDCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)))

#define SYSTICK_STCTRL										(*((volatile SYSTICK_STCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* MCU_HW_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
