#include"IntCtrl.h"
#include"Common_Macros.h"


IntCtrl_Configuredperint * IntCtrl_Config = NULL_PTR;
/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")

void IntCtrl_init(IntCtrl_ConfigType * Container)
{
    volatile uint32 * EN_Ptr = NULL_PTR;
    volatile uint32 *PRI_PTR =NULL_PTR;
    IntCtrl_InterruptType interrupt_index = (IntCtrl_InterruptType)0;

    IntCtrl_Config = Container ->Intinst;
    for(interrupt_index = 0 ; interrupt_index < NUMBER_OF_CONFIGURED_INTERRUPTS ; interrupt_index++)
    {
        if(IntCtrl_Config[interrupt_index].EnableType == EN0)
        {
           EN_Ptr = & NVIC_EN0_REG;
        }
        else if(IntCtrl_Config[interrupt_index].EnableType == EN1)
        {
           EN_Ptr = & NVIC_EN1_REG;
        }
        else if(IntCtrl_Config[interrupt_index].EnableType == EN2)
        {
           EN_Ptr = & NVIC_EN2_REG; 
        }
        else if(IntCtrl_Config[interrupt_index].EnableType == EN3)
        {
           EN_Ptr = & NVIC_EN3_REG;   
        }
        else if(IntCtrl_Config[interrupt_index].EnableType == EN4)
        {
           EN_Ptr = & NVIC_EN4_REG;
        }
        else
        {
            /*Nothing to do*/
        }
        /**********************************************************/
        switch(IntCtrl_Config[interrupt_index].PriType)
        {
            case PRI0:
             {
                 PRI_PTR = &NVIC_PRI0_REG;
                 break;
             }
            case PRI1:
             {
                 PRI_PTR = &NVIC_PRI1_REG;
                 break;
             }
            case PRI2:
             {
                 PRI_PTR = &NVIC_PRI2_REG;
                 break;
             }
            case PRI3:
             {
                 PRI_PTR = &NVIC_PRI3_REG;
                 break;
             }
            case PRI4:
             {
                 PRI_PTR = &NVIC_PRI4_REG;
                 break;
             }
            case PRI5:
             {
                 PRI_PTR = &NVIC_PRI5_REG;
                 break;
             }
            case PRI6:
             {
                 PRI_PTR = &NVIC_PRI6_REG;
                 break;
             }
            case PRI7:
             {
                 PRI_PTR = &NVIC_PRI7_REG;
                 break;
             }
            case PRI8:
             {
                 PRI_PTR = &NVIC_PRI8_REG;
                 break;
             }
            case PRI9:
             {
                 PRI_PTR = &NVIC_PRI9_REG;
                 break;
             }
            case PRI10:
             {
                 PRI_PTR = &NVIC_PRI10_REG;
                 break;
             }
            case PRI11:
             {
                 PRI_PTR = &NVIC_PRI11_REG;
                 break;
             }
            case PRI12:
             {
                 PRI_PTR = &NVIC_PRI12_REG;
                 break;
             }
            case PRI13:
             {
                 PRI_PTR = &NVIC_PRI13_REG;
                 break;
             }
            case PRI14:
             {
                 PRI_PTR = &NVIC_PRI14_REG;
                 break;
             }
            case PRI15:
             {
                 PRI_PTR = &NVIC_PRI15_REG;
                 break;
             }
            case PRI16:
             {
                 PRI_PTR = &NVIC_PRI16_REG;
                 break;
             }
            case PRI17:
             {
                 PRI_PTR = &NVIC_PRI17_REG;
                 break;
             }
            case PRI18:
             {
                 PRI_PTR = &NVIC_PRI18_REG;
                 break;
             }
            case PRI19:
             {
                 PRI_PTR = &NVIC_PRI19_REG;
                 break;
             }
            case PRI20:
             {
                 PRI_PTR = &NVIC_PRI20_REG;
                 break;
             }
            case PRI21:
             {
                 PRI_PTR = &NVIC_PRI21_REG;
                 break;
             } 
             case PRI22:
             {
                 PRI_PTR = &NVIC_PRI22_REG;
                 break;
             }
            case PRI23:
             {
                 PRI_PTR = &NVIC_PRI23_REG;
                 break;
             }
            case PRI24:
             {
                 PRI_PTR = &NVIC_PRI24_REG;
                 break;
             }
            case PRI25:
             {
                 PRI_PTR = &NVIC_PRI25_REG;
                 break;
             }
            case PRI26:
             {
                 PRI_PTR = &NVIC_PRI26_REG;
                 break;
             }
            case PRI27:
             {
                 PRI_PTR = &NVIC_PRI27_REG;
                 break;
             }
            case PRI28:
             {
                 PRI_PTR = &NVIC_PRI28_REG;
                 break;
             }
            case PRI29:
             {
                 PRI_PTR = &NVIC_PRI29_REG;
                 break;
             }
            case PRI30:
             {
                 PRI_PTR = &NVIC_PRI30_REG;
                 break;
             }
            case PRI31:
             {
                 PRI_PTR = &NVIC_PRI31_REG;
                 break;
             }
            case PRI32:
             {
                 PRI_PTR = &NVIC_PRI32_REG;
                 break;
             }
            case PRI33:
             {
                 PRI_PTR = &NVIC_PRI33_REG;
                 break;
             }
            case PRI34:
             {
                 PRI_PTR = &NVIC_PRI34_REG;
                 break;
             } 
             default:
             {
                 break;
             } 
        }
             /**************************************/
             if(IntCtrl_Config[interrupt_index].Enable == STD_ON)
             {
                 SET_BIT(*EN_Ptr,IntCtrl_Config[interrupt_index].IntType);
             }
             else if(IntCtrl_Config[interrupt_index].Enable == STD_OFF)
             {
                 CLEAR_BIT(*EN_Ptr,IntCtrl_Config[interrupt_index].IntType);
             }                                     
             /**************************************/
             *PRI_PTR = *PRI_PTR | (IntCtrl_Config[interrupt_index].Pri << IntCtrl_Config[interrupt_index].PriBitsPosition);

        
    }
    Enable_Interrupts();
}

void IntCtrl_SetExtInterrupt(IntCtrl_ExtPortConfigContainer *container)
{
    if(container->PortId == IntConf_PortA)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTA_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTA_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTA_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTA_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTA_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTA_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTA_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTA_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTA_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTA_IM_REG,container->PinId);
      }
    }
    else if(container->PortId == IntConf_PortB)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTB_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTB_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTB_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTB_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTB_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTB_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTB_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTB_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTB_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTB_IM_REG,container->PinId);
      }
    }
    else if(container->PortId == IntConf_PortC)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTC_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTC_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTC_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTC_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTC_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTC_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTC_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTC_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTC_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTC_IM_REG,container->PinId);
      }
    }
    else if(container->PortId == IntConf_PortD)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTD_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTD_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTD_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTD_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTD_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTD_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTD_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTD_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTD_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTD_IM_REG,container->PinId);
      }
    }
    else if(container->PortId == IntConf_PortE)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTE_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTE_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTE_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTE_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTE_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTE_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTE_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTE_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTE_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTE_IM_REG,container->PinId);
      }
    }
    else if(container->PortId == IntConf_PortF)
    {
      if(container->IS_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTF_IS_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTF_IS_REG,container->PinId);
      }
      /////
      if(container->IBE_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTF_IBE_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTF_IBE_REG,container->PinId);
      }
      /////
      if(container->IEV_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTF_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTF_IEV_REG,container->PinId);
      }
      //////
      if(container->ICR_value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTF_IEV_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTF_IEV_REG,container->PinId);
      }
      /////
      if(container->IM_Value==STD_OFF)
      {
        CLEAR_BIT(GPIO_PORTF_IM_REG,container->PinId);
      }
      else
      {
        SET_BIT(GPIO_PORTF_IM_REG,container->PinId);
      }
    }
}

void IntCtrl_Enable_Interrupts(void)
{
    Enable_Interrupts();
}

void IntCtrl_Disable_Interrupts(void)
{
    Disable_Interrupts();
}