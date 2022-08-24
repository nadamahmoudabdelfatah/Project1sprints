#include"Dio.h"
#include"Dio_Regs.h"
#include"Common_Macros.h"
Dio_PortType getPortType(Dio_ChannelType ChannelId)
{
    Dio_PortType returnPort = DioConf_PORTA;

    if(ChannelId >= A0 && ChannelId <= A7)
    {
        returnPort = DioConf_PORTA;
    }
    else if(ChannelId >= B0 && ChannelId <= B7)
    {
        returnPort = DioConf_PORTB;
    }
    else if(ChannelId >= C0 && ChannelId <= C7)
    {
        returnPort = DioConf_PORTC;
    }
    else if(ChannelId >= D0 && ChannelId <= D7)
    {
        returnPort = DioConf_PORTD;
    }
    else if(ChannelId >= E0 && ChannelId <= E5)
    {
        returnPort = DioConf_PORTE;
    }
    else if(ChannelId >= F0 && ChannelId <= F4)
    {
        returnPort = DioConf_PORTF;
    } 
    else
    {
        /*Nothing to do*/
    }  
    return returnPort;
    
}
Dio_ChannelType getChannelType(Dio_ChannelType ChannelId)
{
    Dio_ChannelType returnChannel = A0;

    if((ChannelId == A0) || (ChannelId == B0) || (ChannelId == C0) || (ChannelId == D0) || (ChannelId == E0) || (ChannelId == F0))
    {
            returnChannel = (Dio_ChannelType)0;
    }
    else if((ChannelId == A1) || (ChannelId == B1) || (ChannelId == C1) || (ChannelId == D1) || (ChannelId == E1) || (ChannelId == F1))
    {
            returnChannel = (Dio_ChannelType)1;
    }
    else if((ChannelId == A2) || (ChannelId == B2) || (ChannelId == C2) || (ChannelId == D2) || (ChannelId == E2) || (ChannelId == F2))
    {
            returnChannel = (Dio_ChannelType)2;
    }
    else if((ChannelId == A3) || (ChannelId == B3) || (ChannelId == C3) || (ChannelId == D3) || (ChannelId == E3) || (ChannelId == F3))
    {
            returnChannel = (Dio_ChannelType)3;
    }
    else if((ChannelId == A4) || (ChannelId == B4) || (ChannelId == C4) || (ChannelId == D4) || (ChannelId == E4) || (ChannelId == F4))
    {
            returnChannel = (Dio_ChannelType)4;

    }
    else if((ChannelId == A5) || (ChannelId == B5) || (ChannelId == C5) || (ChannelId == D5) || (ChannelId == E5))
    {
            returnChannel = (Dio_ChannelType)5;
        
    }
    else if((ChannelId == A4) || (ChannelId == B6) || (ChannelId == C6) || (ChannelId == D6))
    {
            returnChannel = (Dio_ChannelType)6;

    }
    else if((ChannelId == A5) || (ChannelId == B7) || (ChannelId == C7) || (ChannelId == D7))
    {
            returnChannel = (Dio_ChannelType)7;       
    }
    else
    {
        /*Nothing to do*/
    }
    return returnChannel;
    
}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    volatile uint32 * Port_Ptr = NULL_PTR;
    Dio_PortType portTypeinst = (Dio_PortType)0 ;
    Dio_ChannelType channelTypeinst = (Dio_ChannelType)0;
    Dio_LevelType levelReturn = (Dio_LevelType)0;
    portTypeinst = getPortType(ChannelId);
    channelTypeinst = getChannelType(ChannelId);
    if(DioConf_PORTA == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTA_DATA_REG;
    }
    else if(DioConf_PORTB == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTB_DATA_REG;
    }
    else if(DioConf_PORTC == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTC_DATA_REG;
    }
    else if(DioConf_PORTD == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTD_DATA_REG;
    }
    else if(DioConf_PORTE == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTE_DATA_REG;
    }
    else if(DioConf_PORTF == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTF_DATA_REG;
    } 
    else
    {
        /*Nothing to do*/
    }   
    if(BIT_IS_SET(*Port_Ptr,channelTypeinst))
	{
	    levelReturn = STD_HIGH;
	}
    else if(!(BIT_IS_SET(*Port_Ptr,channelTypeinst)))
    {
	    levelReturn = STD_LOW;        
    }
    else
    {
        /*Nothing to do*/
    }
    return levelReturn;
}
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    volatile uint32 * Port_Ptr = NULL_PTR;
    Dio_PortType portTypeinst = (Dio_PortType)0 ;
    Dio_ChannelType channelTypeinst = (Dio_ChannelType)0;
    portTypeinst = getPortType(ChannelId);
    channelTypeinst = getChannelType(ChannelId);
    if(DioConf_PORTA == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTA_DATA_REG;
    }
    else if(DioConf_PORTB == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTB_DATA_REG;
    }
    else if(DioConf_PORTC == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTC_DATA_REG;
    }
    else if(DioConf_PORTD == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTD_DATA_REG;
    }
    else if(DioConf_PORTE == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTE_DATA_REG;
    }
    else if(DioConf_PORTF == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTF_DATA_REG;
    } 
    else
    {
        /*Nothing to do*/
    }   
    if(STD_HIGH == Level)
    {
        SET_BIT(*Port_Ptr,channelTypeinst);
    }
    else if(STD_LOW == Level)
    {
        CLEAR_BIT(*Port_Ptr,channelTypeinst);
    }
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType levelReturn = (Dio_PortLevelType)0;
    volatile uint32 * Port_Ptr = NULL_PTR;
    if(DioConf_PORTA == PortId)
    {
        Port_Ptr = &GPIO_PORTA_DATA_REG;
    }
    else if(DioConf_PORTB == PortId)
    {
        Port_Ptr = &GPIO_PORTB_DATA_REG;
    }
    else if(DioConf_PORTC == PortId)
    {
        Port_Ptr = &GPIO_PORTC_DATA_REG;
    }
    else if(DioConf_PORTD == PortId)
    {
        Port_Ptr = &GPIO_PORTD_DATA_REG;
    }
    else if(DioConf_PORTE == PortId)
    {
        Port_Ptr = &GPIO_PORTE_DATA_REG;
    }
    else if(DioConf_PORTF == PortId)
    {
        Port_Ptr = &GPIO_PORTF_DATA_REG;
    } 
    else
    {
        /*Nothing to do*/
    } 
    levelReturn = *Port_Ptr;
    return levelReturn;  
}
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
    volatile uint32 * Port_Ptr = NULL_PTR;
    if(DioConf_PORTA == PortId)
    {
        Port_Ptr = &GPIO_PORTA_DATA_REG;
    }
    else if(DioConf_PORTB == PortId)
    {
        Port_Ptr = &GPIO_PORTB_DATA_REG;
    }
    else if(DioConf_PORTC == PortId)
    {
        Port_Ptr = &GPIO_PORTC_DATA_REG;
    }
    else if(DioConf_PORTD == PortId)
    {
        Port_Ptr = &GPIO_PORTD_DATA_REG;
    }
    else if(DioConf_PORTE == PortId)
    {
        Port_Ptr = &GPIO_PORTE_DATA_REG;
    }
    else if(DioConf_PORTF == PortId)
    {
        Port_Ptr = &GPIO_PORTF_DATA_REG;
    } 
    else
    {
        /*Nothing to do*/
    } 
    *Port_Ptr = Level; 
}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    volatile uint32 * Port_Ptr = NULL_PTR;
    Dio_PortType portTypeinst = (Dio_PortType)0 ;
    Dio_ChannelType channelTypeinst = (Dio_ChannelType)0;
    Dio_LevelType levelReturn = (Dio_LevelType)0;
    portTypeinst = getPortType(ChannelId);
    channelTypeinst = getChannelType(ChannelId);
    if(DioConf_PORTA == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTA_DATA_REG;
    }
    else if(DioConf_PORTB == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTB_DATA_REG;
    }
    else if(DioConf_PORTC == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTC_DATA_REG;
    }
    else if(DioConf_PORTD == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTD_DATA_REG;
    }
    else if(DioConf_PORTE == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTE_DATA_REG;
    }
    else if(DioConf_PORTF == portTypeinst)
    {
        Port_Ptr = &GPIO_PORTF_DATA_REG;
    } 
    else
    {
        /*Nothing to do*/
    } 
    TOGGLE_BIT(*Port_Ptr,channelTypeinst);
    if(BIT_IS_SET(*Port_Ptr,channelTypeinst))
	{
	    levelReturn = STD_HIGH;
	}
    else if(!(BIT_IS_SET(*Port_Ptr,channelTypeinst)))
    {
	    levelReturn = STD_LOW;        
    }
    else
    {
        /*Nothing to do*/
    }
    return levelReturn;
}