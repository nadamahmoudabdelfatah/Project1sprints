#ifndef INT_H
#define INT_H
#include"Std_Types.h"
#include"IntCtrl_Cfg.h"
#include"IntCtrl_Types.h"
#include"IntCtrl_Regs.h"

typedef struct IntCtrl_ExtPortConfigContainer
{
    IntCtrl_PortType PortId;
    IntCtrl_PinType  PinId;
    uint8            IS_value;
    uint8            IBE_value;
    uint8            IEV_Value;
    uint8            ICR_value;
    uint8            IM_Value;
} IntCtrl_ExtPortConfigContainer;

typedef struct IntCtrl_ConfigContainer
{ 
   IntCtrl_InterruptType IntType;     /*Interrupt configured number*/
   IntCtrl_Pri           Pri;         /*Interrupt Priority configured number*/
   IntCtrl_Enable        Enable;      /*Interrupt is disabled or enabled*/
}IntCtrl_ConfigContainer;


typedef struct IntCtrl_Configuredperint
{
    IntCtrl_EnableType    EnableType;
    IntCtrl_PriTtype      PriType;
    IntCtrl_InterruptType IntType;     /*Interrupt configured number*/
    IntCtrl_Pri           Pri;         /*Interrupt Priority configured number*/
    IntCtrl_Enable        Enable;      /*Interrupt is disabled or enabled*/
    uint32                PriMask;
    uint32                PriBitsPosition;
}IntCtrl_Configuredperint;

typedef struct IntCtrl_ConfigType
{
   IntCtrl_Configuredperint Intinst[NUMBER_OF_CONFIGURED_INTERRUPTS];
} IntCtrl_ConfigType;

void IntCtrl_init(IntCtrl_ConfigType * Container);
void IntCtrl_Enable_Interrupts(void);
void IntCtrl_SetExtInterrupt(IntCtrl_ExtPortConfigContainer *container);

/* Extern PB structures to be used by Port and other modules */
extern IntCtrl_ConfigType             Container;
extern IntCtrl_ExtPortConfigContainer Ext_Container;
#endif