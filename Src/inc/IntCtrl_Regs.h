#ifndef INT_REG_H
#define INT_REG_H
/*Interrupt priority Registers*/                                             /*Bit 5-7      13-15             21-23         29-31            */
#define NVIC_PRI0_REG             (*((volatile unsigned long *)0xE000E400))  /*GPIO_INTA    GPIO_INTB         GPIO_INTC     GPIO_INTD        */
#define NVIC_PRI1_REG             (*((volatile unsigned long *)0xE000E404))  /*GPIO_INTE    UART0_INT         UART1_INT     SSI0_INT         */
#define NVIC_PRI2_REG             (*((volatile unsigned long *)0xE000E408))  /*I2C0_INT     PWMFAULT_INT      PWMGEN0_INT   PWMGEN1_INT      */
#define NVIC_PRI3_REG             (*((volatile unsigned long *)0xE000E40C))  /*PWMGEN2_INT  QUADENCODER_INT   ADCSEQ0_INT   ADCSEQ1_INT      */
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))  /*ADCSEQ2_INT  ADCSEQ3_INT       WDT_INT       TMR0A_INT        */
#define NVIC_PRI5_REG             (*((volatile unsigned long *)0xE000E414))  /*TMR0B_INT    TMR1A_INT         TMR1B_INT     TMR2A_INT        */
#define NVIC_PRI6_REG             (*((volatile unsigned long *)0xE000E418))  /*TMR2B_INT    CMP0_INT          CMP1_INT      CMP2_INT         */
#define NVIC_PRI7_REG             (*((volatile unsigned long *)0xE000E41C))  /*SSI0_INT               */
#define NVIC_PRI8_REG             (*((volatile unsigned long *)0xE000E420))  /*I2C0_INT               */
#define NVIC_PRI9_REG             (*((volatile unsigned long *)0xE000E424))  /*PWMFAULT_INT           */
#define NVIC_PRI10_REG            (*((volatile unsigned long *)0xE000E428))  /*PWMGEN0_INT            */
#define NVIC_PRI11_REG            (*((volatile unsigned long *)0xE000E42C))  /*PWMGEN1_INT            */
#define NVIC_PRI12_REG            (*((volatile unsigned long *)0xE000E430))  /*PWMGEN2_INT            */
#define NVIC_PRI13_REG            (*((volatile unsigned long *)0xE000E434))  /*QUADENCODER_INT        */
#define NVIC_PRI14_REG            (*((volatile unsigned long *)0xE000E438))  /*ADCSEQ0_INT            */
#define NVIC_PRI15_REG            (*((volatile unsigned long *)0xE000E43C))  /*ADCSEQ1_INT            */
#define NVIC_PRI16_REG            (*((volatile unsigned long *)0xE000E440))  /*ADCSEQ2_INT            */
#define NVIC_PRI17_REG            (*((volatile unsigned long *)0xE000E444))  /*ADCSEQ3_INT            */
#define NVIC_PRI18_REG            (*((volatile unsigned long *)0xE000E448))  /*WDT_INT                */
#define NVIC_PRI19_REG            (*((volatile unsigned long *)0xE000E44C))  /*TMR0A_INT              */
#define NVIC_PRI20_REG            (*((volatile unsigned long *)0xE000E450))  /*TMR0B_INT              */
#define NVIC_PRI21_REG            (*((volatile unsigned long *)0xE000E454))  /*TMR1A_INT              */
#define NVIC_PRI22_REG            (*((volatile unsigned long *)0xE000E458))  /*TMR1B_INT              */
#define NVIC_PRI23_REG            (*((volatile unsigned long *)0xE000E45C))  /*TMR2A_INT              */
#define NVIC_PRI24_REG            (*((volatile unsigned long *)0xE000E460))  /*TMR2B_INT              */
#define NVIC_PRI25_REG            (*((volatile unsigned long *)0xE000E464))  /*CMP0_INT               */
#define NVIC_PRI26_REG            (*((volatile unsigned long *)0xE000E468))  /*CMP1_INT               */
#define NVIC_PRI27_REG            (*((volatile unsigned long *)0xE000E46C))  /*CMP2_INT               */
#define NVIC_PRI28_REG            (*((volatile unsigned long *)0xE000E470))  /*SYSCTRL_INT            */
#define NVIC_PRI29_REG            (*((volatile unsigned long *)0xE000E474))  /*FLASHCTRL_INT          */
#define NVIC_PRI30_REG            (*((volatile unsigned long *)0xE000E478))  /*GPIO_INTF              */
#define NVIC_PRI31_REG            (*((volatile unsigned long *)0xE000E47C))  /*GPIO_INTG              */
#define NVIC_PRI32_REG            (*((volatile unsigned long *)0xE000E480))  /*GPIO_INTH              */
#define NVIC_PRI33_REG            (*((volatile unsigned long *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile unsigned long *)0xE000E488))
/*Interrupts enable register*/
#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile unsigned long *)0xE000E110))
/*Interrupts disable register*/
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile unsigned long *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile unsigned long *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile unsigned long *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile unsigned long *)0xE000E190))
/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile unsigned long *)0x4000441C))
/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile unsigned long *)0x4000541C))
/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile unsigned long *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile unsigned long *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile unsigned long *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile unsigned long *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile unsigned long *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile unsigned long *)0x4000641C))
/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile unsigned long *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile unsigned long *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile unsigned long *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile unsigned long *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile unsigned long *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile unsigned long *)0x4000741C))
/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile unsigned long *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile unsigned long *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile unsigned long *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile unsigned long *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile unsigned long *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile unsigned long *)0x4002441C))
/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile unsigned long *)0x4002541C))
#endif