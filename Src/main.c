

#include "Dio.h"
#include "Port.h"
#include "IntCtrl.h"
#include "Timer.h"



/************************************************************************************
* Service Name: SysTick_Handler
* Description: SysTick Timer ISR
************************************************************************************/




static uint8 time_on = 1;
static uint8 time_off = 1;
void Toggle_Led(void)
{
    static uint8 ticks_total = 0;
    static uint8 tick_count = 0;
    ticks_total = time_on + time_off;
    tick_count++;
    if(tick_count == time_on)
    {
        Dio_WriteChannel(F3,STD_OFF);
    }
    else if(tick_count == ticks_total)
    {
        Dio_WriteChannel(F3,STD_ON);
    }
    if(tick_count == ticks_total)
    {
        tick_count = 0;
    }
}
int main(void)
{
    SYSCTL_REGCGC2_REG |= 0x00000020;

    

    Port_Init(&Port_Configuration);
    IntCtrl_init(&Container);
    IntCtrl_SetExtInterrupt(&Ext_Container);
    SysTick_Init(15999999);
    while(1)
    {
        SysTick_Notification(Toggle_Led);

    }
}