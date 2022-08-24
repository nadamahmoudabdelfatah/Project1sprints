#ifndef TIMER_H
#define TIMER_H
#include"Timer_Reg.h"
#include"Std_Types.h"
void SysTick_Init();
void SysTick_Notification(void(*Ptr2Func)(void));
#endif