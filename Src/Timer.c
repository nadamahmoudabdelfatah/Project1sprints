#include "Timer.h"
static void (*SysTick_Notification_Ptr)(void) = NULL_PTR;
void SysTick_Init(uint32 ReloadValue)
{
    SYSTICK_CTRL_REG    = 0;                        
    SYSTICK_RELOAD_REG  = ReloadValue ;                           
    SYSTICK_CTRL_REG   |= 0x07;
}

void SysTick_Notification(void(*Ptr2Func)(void))
{
    SysTick_Notification_Ptr = Ptr2Func;
}

void SysTick_Handler(void)
{

    if(SysTick_Notification_Ptr != NULL_PTR)
    {
        (*SysTick_Notification_Ptr)();
    }
   
}