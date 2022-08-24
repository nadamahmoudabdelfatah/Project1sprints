#ifndef INT_CFG_H
#define INT_CFG_H
#include"IntCtrl_Regs.h"
#include"IntCtrl_Types.h"
/*Configurations for PORTF*/
#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2

#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_INTERRUPT_PRIORITY  2
#define SYSTICK_PRIORITY_BITS_POS   29
/* Port Configured Port ID's  */
#define IntConf_PortA                (IntCtrl_PortType)0 /* PORTA */
#define IntConf_PortB                (IntCtrl_PortType)1 /* PORTB */
#define IntConf_PortC                (IntCtrl_PortType)2 /* PORTC */
#define IntConf_PortD                (IntCtrl_PortType)3 /* PORTD */
#define IntConf_PortE                (IntCtrl_PortType)4 /* PORTE */
#define IntConf_PortF                (IntCtrl_PortType)5 /* PORTF */

/*Interrupt number */
#define GPIO_INTA                (IntCtrl_InterruptType)0
#define GPIO_INTB                (IntCtrl_InterruptType)1
#define GPIO_INTC                (IntCtrl_InterruptType)2
#define GPIO_INTD                (IntCtrl_InterruptType)3
#define GPIO_INTE                (IntCtrl_InterruptType)4
#define UART0_INT                (IntCtrl_InterruptType)5
#define UART1_INT                (IntCtrl_InterruptType)6
#define SSI0_INT                 (IntCtrl_InterruptType)7
#define I2C0_INT                 (IntCtrl_InterruptType)8
#define PWMFAULT_INT             (IntCtrl_InterruptType)9
#define PWMGEN0_INT              (IntCtrl_InterruptType)10
#define PWMGEN1_INT              (IntCtrl_InterruptType)11
#define PWMGEN2_INT              (IntCtrl_InterruptType)12
#define QUADENCODER_INT          (IntCtrl_InterruptType)13
#define ADCSEQ0_INT              (IntCtrl_InterruptType)14
#define ADCSEQ1_INT              (IntCtrl_InterruptType)15
#define ADCSEQ2_INT              (IntCtrl_InterruptType)16
#define ADCSEQ3_INT              (IntCtrl_InterruptType)17
#define WDT_INT                  (IntCtrl_InterruptType)18
#define TMR0A_INT                (IntCtrl_InterruptType)19
#define TMR0B_INT                (IntCtrl_InterruptType)20
#define TMR1A_INT                (IntCtrl_InterruptType)21
#define TMR1B_INT                (IntCtrl_InterruptType)22
#define TMR2A_INT                (IntCtrl_InterruptType)23
#define TMR2B_INT                (IntCtrl_InterruptType)24
#define CMP0_INT                 (IntCtrl_InterruptType)25
#define CMP1_INT                 (IntCtrl_InterruptType)26
#define CMP2_INT                 (IntCtrl_InterruptType)27
#define SYSCTRL_INT              (IntCtrl_InterruptType)28
#define FLASHCTRL_INT            (IntCtrl_InterruptType)29
#define GPIO_INTF                (IntCtrl_InterruptType)30
#define GPIO_INTG                (IntCtrl_InterruptType)31
#define GPIO_INTH                (IntCtrl_InterruptType)32
#define UART2_INT                (IntCtrl_InterruptType)33
#define SSI2_INT                 (IntCtrl_InterruptType)34
#define TMR3A_INT                (IntCtrl_InterruptType)35
#define TMR3B_INT                (IntCtrl_InterruptType)36
#define I2C1_INT                 (IntCtrl_InterruptType)37
#define QUADENCODER1_INT         (IntCtrl_InterruptType)38
#define CAN0_INT                 (IntCtrl_InterruptType)39
#define CAN1_INT                 (IntCtrl_InterruptType)40
#define CAN2_INT                 (IntCtrl_InterruptType)41
#define ETHERNET_INTH            (IntCtrl_InterruptType)42
#define HIBERNATE_INT            (IntCtrl_InterruptType)43
#define USB0_INT                 (IntCtrl_InterruptType)44
#define PWMGEN3_INT              (IntCtrl_InterruptType)45
#define DMASOFT_INT              (IntCtrl_InterruptType)46
#define DMAERROR_INT             (IntCtrl_InterruptType)47
#define DEBUG_INT                (IntCtrl_InterruptType)48
#define RESERVED                 (IntCtrl_InterruptType)49
#define PENDSV_INT               (IntCtrl_InterruptType)50
#define SYSTICK_INT              (IntCtrl_InterruptType)15 /*Need to be checked*/

/*pri */
#define PRI0                (IntCtrl_PriTtype)0
#define PRI1                (IntCtrl_PriTtype)1
#define PRI2                (IntCtrl_PriTtype)2
#define PRI3                (IntCtrl_PriTtype)3
#define PRI4                (IntCtrl_PriTtype)4
#define PRI5                (IntCtrl_PriTtype)5
#define PRI6                (IntCtrl_PriTtype)6
#define PRI7                (IntCtrl_PriTtype)7
#define PRI8                (IntCtrl_PriTtype)8
#define PRI9                (IntCtrl_PriTtype)9
#define PRI10               (IntCtrl_PriTtype)10
#define PRI11               (IntCtrl_PriTtype)11
#define PRI12               (IntCtrl_PriTtype)12
#define PRI13               (IntCtrl_PriTtype)13
#define PRI14               (IntCtrl_PriTtype)14
#define PRI15               (IntCtrl_PriTtype)15
#define PRI16               (IntCtrl_PriTtype)16
#define PRI17               (IntCtrl_PriTtype)17
#define PRI18               (IntCtrl_PriTtype)18
#define PRI19               (IntCtrl_PriTtype)19
#define PRI20               (IntCtrl_PriTtype)20
#define PRI21               (IntCtrl_PriTtype)21
#define PRI22               (IntCtrl_PriTtype)22
#define PRI23               (IntCtrl_PriTtype)23
#define PRI24               (IntCtrl_PriTtype)24
#define PRI25               (IntCtrl_PriTtype)25
#define PRI26               (IntCtrl_PriTtype)26
#define PRI27               (IntCtrl_PriTtype)27
#define PRI28               (IntCtrl_PriTtype)28
#define PRI29               (IntCtrl_PriTtype)29
#define PRI30               (IntCtrl_PriTtype)30
#define PRI31               (IntCtrl_PriTtype)31
#define PRI32               (IntCtrl_PriTtype)32
#define PRI33               (IntCtrl_PriTtype)33
#define PRI34               (IntCtrl_PriTtype)34


/*Interrupts Enable Config*/
#define EN0                             (IntCtrl_EnableType)0
#define EN1                             (IntCtrl_EnableType)1
#define EN2                             (IntCtrl_EnableType)2
#define EN3                             (IntCtrl_EnableType)3
#define EN4                             (IntCtrl_EnableType)4

#define NUMBER_OF_CONFIGURED_INTERRUPTS                    (IntCtrl_InterruptType)52
#define NUMBER_OF_CONFIGURED_EXT_INTERRUPTS                (IntCtrl_InterruptType)1
/*Configurations for every configured Interrupt*/



#endif