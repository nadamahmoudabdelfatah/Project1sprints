#ifndef STD_TYPES_H 
#define STD_TYPES_H 

#include "Compiler.h"
#include "Platform_Types.h"

/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (3U)
typedef uint8 Std_ReturnType; 

typedef struct 
{ 
 uint16 vendorID; 
 uint16 moduleID; 
 uint8 instanceID; 
 uint8 sw_major_version; 
 uint8 sw_minor_version; 
 uint8 sw_patch_version; 
} Std_VersionInfoType; 

#define E_OK  ((Std_ReturnType)0x00U)
#define E_NOT_OK ((Std_ReturnType)0x00U)

#define STD_HIGH ((Std_ReturnType)0x01U) /* Physical state 5V or 3.3V */ 
#define STD_LOW ((Std_ReturnType)0x00U) /* Physical state 0V */

#define STD_ON  ((Std_ReturnType)0x01U)
#define STD_OFF ((Std_ReturnType)0x00U)

#endif /* STD_TYPES_H */