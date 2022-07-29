/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio_Types.h
 *  Module:  	  Dio_Types
 *
 *  Description:  Header file for Dio Module's Types
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  20/07/2022
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PinType used by the DIO APIs */
typedef Port_PinType Dio_PinType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef Port_PortType Dio_PortType;

/* Type definition for Dio_ChannelConfigType used by the DIO APIs */
typedef struct
{
	Dio_PortType portId;
	Dio_PinType pinId;
} Dio_ChannelConfigType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef enum
{
	DIO_LEVEL_ERROR = -1,
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH = 1
} Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

#endif  /* DIO_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
