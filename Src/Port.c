/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Nada Mahmoud
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"


#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
		|| (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
		|| (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif




static uint8 Port_Status = PORT_NOT_INITIALIZED;
static const Port_ConfigChannel * Port_PortChannels = NULL_PTR;

/************************************************************************************
 *Local fuctions declarations
 ************************************************************************************/
static void Port_Setpin(Port_PinType Pin, Port_PinType *Port_PinNum);
static void Port_Setport(Port_PinType Pin,  volatile uint32 ** Port_GpioPtr);
static void Port_Initdirection(Port_PinType Pin, Port_PinType Port_PinNum, volatile uint32 ** Port_GpioPtr);
static void Port_Setmode(Port_PinType Pin, Port_PinType Port_PinNum, Port_PinModeType Mode);

/************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the Port module.
 ************************************************************************************/


void Port_Init(const Port_ConfigType* ConfigPtr)
{
	volatile uint32 * Port_GpioPtr = NULL_PTR;
	Port_PinType Port_Pinindex=0;
	volatile uint32 delay = 0;
	Port_PinType Port_PinNum;

	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_INIT_FAILED);
	}
	else

{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Port_Status       = PORT_INITIALIZED;
		Port_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
		for(Port_Pinindex=0;Port_Pinindex<PORT_CONFIGURED_CHANNLES;Port_Pinindex++)
		{
			Port_Setport(Port_PortChannels[Port_Pinindex].Port_PinId, &Port_GpioPtr);
			/* Enable clock for PORT and allow time for clock to start*/
			SYSCTL_REGCGC2_REG |= (1<<Port_PortChannels[Port_Pinindex].port_num);
			delay = SYSCTL_REGCGC2_REG;
			Port_Setpin(Port_PortChannels[Port_Pinindex].Port_PinId, &Port_PinNum);
			if( ((Port_PortChannels[Port_Pinindex].port_num == 3) && (Port_PinNum == 7)) || ((Port_PortChannels[Port_Pinindex].port_num == 5) && (Port_PinNum == 0)) ) /* PD7 or PF0 */
			{
				*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_COMMIT_REG_OFFSET) , Port_PinNum);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
			}
			else if( (Port_PortChannels[Port_Pinindex].port_num == 2) && (Port_PinNum <=3) ) /* PC0 to PC3 */
			{
				/* Do Nothing ...  this is the JTAG pins */
				continue;
			}
			else
			{
				/* Do Nothing ... No need to unlock the commit register for this pin */
			}
			Port_Setmode(Port_PortChannels[Port_Pinindex].Port_PinId, Port_PinNum, Port_PortChannels[Port_Pinindex].Port_PinInitialMode);
			Port_Initdirection(Port_PortChannels[Port_Pinindex].Port_PinId, Port_PinNum, &Port_GpioPtr);
		}

}
}

/************************************************************************************
 * Service Name: Port_SetPinDirection
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port Pin ID number , Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Sets the port pin direction.
 ************************************************************************************/


void Port_SetPinDirection( Port_PinType Pin, Port_PinDirection Direction )
{
	Port_PinType Port_PinNum;
	volatile uint32 * Port_GpioPtr = NULL_PTR;


	if(Port_PortChannels[Pin].PortPinDirectionChangeable == STD_OFF)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_DIRECTION_UNCHANGEABLE);
	}
	else
	{
		/*Nothing to do*/
	}
	if(Port_Status != PORT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_UNINIT);
	}
	else
	{
		/*Nothing to do*/
	}
	if(Pin >= PORT_CONFIGURED_CHANNLES)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_PARAM_PIN);
	}
	else

	{
		Port_Setpin(Pin, &Port_PinNum);
		Port_Setport(Pin , &Port_GpioPtr);
		if(Direction == PORT_PIN_OUT)
		{
			
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_DIR_REG_OFFSET) , Port_PinNum);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

		}
		else if(Direction == PORT_PIN_IN)
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_DIR_REG_OFFSET) , Port_PinNum);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
		}
	}
}


/************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Sets the port pin direction.
 ************************************************************************************/

void Port_RefreshPortDirection( void )
{
	volatile uint32 * Port_GpioPtr = NULL_PTR;
	Port_PinType Port_Pinindex=0;
	Port_PinType Port_PinNum;
	for(Port_Pinindex=0;Port_Pinindex<PORT_CONFIGURED_CHANNLES;Port_Pinindex++)
	{

		if(Port_Status != PORT_INITIALIZED)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
					PORT_E_UNINIT);
		}
		else
              

                    {
		Port_Setpin(Port_PortChannels[Port_Pinindex].Port_PinId, &Port_PinNum);
		Port_Setport(Port_Pinindex, &Port_GpioPtr);
if (Port_PortChannels[Port_Pinindex].direction == STD_OFF)
{
                if(Port_PortChannels[Port_Pinindex].direction == PORT_PIN_OUT)
		{
			
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_DIR_REG_OFFSET) , Port_PinNum);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

		}
		else if(Port_PortChannels[Port_Pinindex].direction == PORT_PIN_IN)
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_DIR_REG_OFFSET) , Port_PinNum);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
		}
                else
                {
                  /*do nothing*/
                }

	}
                    }

        }
        
}

/************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): Pointer to where to store the version information of this module
 * Return value: None
 * Description: Function to Sets the port pin direction.
 ************************************************************************************/


void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{

	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else

	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}


/************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port Pin ID number, New Port Pin mode to be set on port pin
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Sets the port pin direction.
 ************************************************************************************/


void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

	if (PORT_CONFIGURED_CHANNLES <= Pin)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
	}
	else
	{
		/* No Action Required */
	}
	if (PORT_CONFIG_MODE_NUM <= Mode)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
	}
	else
	{
		/*Nothing to do*/
	}
	if(Port_Status != PORT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
				PORT_E_UNINIT);
	}
	else
	{
		/*Nothing to do*/
	}
	/* Report error if the pin mode is not changeable */
	if (Port_PortChannels[Pin].PortPinDirectionChangeable == STD_OFF)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
	}
	else


	{
		Port_PinType Port_PinNum;
		Port_Setpin(Pin, &Port_PinNum);
		Port_Setmode(Pin,Port_PinNum, Mode);
	}
}


/************************************************************************************
 * Service Name: Port_Setpin
 * Parameters (in): Pin number
 * Parameters (inout): None
 * Parameters (out): Pointer to pin index in the port
 * Return value: None
 * Description: Function to Setup the pin index in port for bit shifting
 ************************************************************************************/
static void Port_Setpin(Port_PinType Pin, Port_PinType* Port_PinNum)
{

	if(Pin == PA0 || Pin == PB0 || Pin == PC0 || Pin == PD0 || Pin == PE0 || Pin == PF0)
	{
		*Port_PinNum = 0;
	}
	else if(Pin == PA1 || Pin == PB1 || Pin == PC1 || Pin == PD1 || Pin == PE1 || Pin == PF1)
	{
		*Port_PinNum = 1;
	}
	else if(Pin == PA2 || Pin == PB2 || Pin == PC2 || Pin == PD2 || Pin == PE2 || Pin == PF2)
	{
		*Port_PinNum = 2;
	}
	else if(Pin == PA3 || Pin == PB3 || Pin == PC3 || Pin == PD3 || Pin == PE3 || Pin == PF3)
	{
		*Port_PinNum = 3;
	}
	else if(Pin == PA4 || Pin == PB4 || Pin == PC4 || Pin == PD4 || Pin == PE4 || Pin == PF4)
	{
		*Port_PinNum = 4;
	}
	else if(Pin == PA5 || Pin == PB5 || Pin == PC5 || Pin == PD5 || Pin == PE5)
	{
		*Port_PinNum = 5;
	}
	else if(Pin == PA6 || Pin == PB6 || Pin == PC6 || Pin == PD6)
	{
		*Port_PinNum = 6;
	}
	else if(Pin == PA7 || Pin == PB7 || Pin == PC7 || Pin == PD7)
	{
		*Port_PinNum = 7;
	}
}

/************************************************************************************
 * Service Name: Port_Setport
 * Parameters (in): Pin number
 * Parameters (inout): None
 * Parameters (out): Pointer to port
 * Return value: None
 * Description: Function to Setup the port for bit shifting
 ************************************************************************************/

static void Port_Setport(Port_PinType Pin,  volatile uint32 ** Port_GpioPtr)
{
	if(Pin == PA0 || Pin == PA1 || Pin == PA2 || Pin == PA3 || Pin == PA4 || Pin == PA5 || Pin == PA6 || Pin == PA7)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTA_REG_BASE_ADDRESS ;
	}
	else if(Pin == PB0 || Pin == PB1 || Pin == PB2 || Pin == PB3 || Pin == PB4 || Pin == PB5 || Pin == PB6 || Pin == PB7)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTB_REG_BASE_ADDRESS ;
	}
	else if(Pin == PC0 || Pin == PC1 || Pin == PC2 || Pin == PC3 || Pin == PC4 || Pin == PC5 || Pin == PC6 || Pin == PC7)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTC_REG_BASE_ADDRESS ;
	}
	else if(Pin == PD0 || Pin == PD1 || Pin == PD2 || Pin == PD3 || Pin == PD4 || Pin == PD5 || Pin == PD6 || Pin == PD7)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTD_REG_BASE_ADDRESS ;
	}
	else if(Pin == PE0 || Pin == PE1 || Pin == PE2 || Pin == PE3 || Pin == PE4 || Pin == PE5)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTE_REG_BASE_ADDRESS ;
	}
	else if(Pin == PF0 || Pin == PF1 || Pin == PF2 || Pin == PF3 || Pin == PF4)
	{
		*Port_GpioPtr = (volatile uint32 *)GPIO_PORTF_REG_BASE_ADDRESS ;
	}
}
/************************************************************************************
 * Service Name: Port_Setmode
 * Parameters (in): Pin number - Pin index - Mode
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the mode of a pin
 ************************************************************************************/

static void Port_Setmode(Port_PinType Pin, Port_PinType Port_PinNum, Port_PinModeType Mode)
{
	volatile uint32 * Port_GpioPtr = NULL_PTR;
	Port_Setport(Pin, &Port_GpioPtr );
	switch (Mode)
	{
	case PORT_PIN_MODE_DIO:
		SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PinNum);      /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PinNum);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_ALT_FUNC_REG_OFFSET) , Port_PinNum);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
		*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) &= ~(DIO_PMCx_BITS << (Port_PinNum * 4));     /* Clear the PMCx bits for this pin */
		break;
	case  PORT_PIN_MODE_ADC:

			PORT_RCGC0_REG = PORT_RCGC0_REG & ADC_CLOCK_ENABLE;
		
		break;
	case  PORT_PIN_MODE_PWM:

			PORT_RCGC0_REG = PORT_RCGC0_REG & PWM_CLOCK_ENABLE;
			*(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) =  *(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) & (PWM_PMCx_BITS << (Port_PinNum * 4));
		
                break;
        case  PORT_PIN_MODE_CAN:

                  PORT_RCGC0_REG = PORT_RCGC0_REG & CAN_CLOCK_ENABLE;

         break;
        case  PORT_PIN_MODE_WDT:
                  PORT_RCGC0_REG = PORT_RCGC0_REG & WDT_CLOCK_ENABLE;		 
              break;
        case  PORT_PIN_MODE_SPI:

            *(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) =  *(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) & (SPI_PMCx_BITS << (Port_PinNum * 4));

          
          break;
          case  PORT_PIN_MODE_GPT:

                          *(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) =  *(volatile uint32 *)((volatile uint8 *)Port_GpioPtr + PORT_CTL_REG_OFFSET) & (GPT_PMCx_BITS << (Port_PinNum * 4));
                     
              break;
               
	}
}
/************************************************************************************
 * Service Name: Port_Initdirection
 * Parameters (in): Pin number - Pin index - Pointer to configuration
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the direction of the pin - (input or output)
 ************************************************************************************/
static void Port_Initdirection(Port_PinType Pin, Port_PinType Port_PinNum, volatile uint32 ** Port_GpioPtr)
{

	if(Port_PortChannels[Pin].direction == PORT_PIN_OUT)
	{
		SET_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_DIR_REG_OFFSET) , Port_PinNum);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

		if(Port_PortChannels[Pin].initial_value == PORT_PIN_LEVEL_HIGH)
		{
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_DATA_REG_OFFSET) , Port_PinNum);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
		}
		else
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_DATA_REG_OFFSET) , Port_PinNum);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
		}
	}
	else if(Port_PortChannels[Pin].direction == PORT_PIN_IN)
	{
		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_DIR_REG_OFFSET) , Port_PinNum);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

		if(Port_PortChannels[Pin].resistor == PULL_UP)
		{
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_PULL_UP_REG_OFFSET) , Port_PinNum);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
		}
		else if(Port_PortChannels[Pin].resistor == PULL_DOWN)
		{
			SET_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_PULL_DOWN_REG_OFFSET) , Port_PinNum);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
		}
		else
		{
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_PULL_UP_REG_OFFSET) , Port_PinNum);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
			CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)(*Port_GpioPtr) + PORT_PULL_DOWN_REG_OFFSET) , Port_PinNum);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
		}
	}
	else
	{
		/* Do Nothing */
	}
}
