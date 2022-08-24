#include"IntCtrl_Cfg.h"
#include"IntCtrl.h"
IntCtrl_ConfigType Container =
                                        {
																		
EN1,PRI3,SYSTICK_INT		,SYSTICK_INTERRUPT_PRIORITY	,	STD_ON , SYSTICK_PRIORITY_MASK , SYSTICK_PRIORITY_BITS_POS 	                                   
                                        };
/*******************************************************/
IntCtrl_ExtPortConfigContainer Ext_Container = 
{
IntConf_PortF,4,STD_OFF,STD_OFF,STD_OFF,STD_ON,STD_ON
};