#ifndef DIO_CFG_H
#define DIO_CFG_H

#define DIO_CONFIGURED_CHANNLES      (1U)
#define DIO_CONFIGURED_PORTS         (5U)

#define A0  (Dio_ChannelType)0 /*00-Pin 0 in PORTA*/
#define A1  (Dio_ChannelType)1 /*01-Pin 1 in PORTA*/
#define A2  (Dio_ChannelType)2 /*02-Pin 2 in PORTA*/
#define A3  (Dio_ChannelType)3 /*03-Pin 3 in PORTA*/
#define A4  (Dio_ChannelType)4 /*04-Pin 4 in PORTA*/
#define A5  (Dio_ChannelType)5 /*05-Pin 5 in PORTA*/
#define A6  (Dio_ChannelType)6 /*06-Pin 6 in PORTA*/
#define A7  (Dio_ChannelType)7 /*07-Pin 7 in PORTA*/ 
#define B0  (Dio_ChannelType)8 /*08-Pin 0 in PORTB*/
#define B1  (Dio_ChannelType)9 /*09-Pin 1 in PORTB*/
#define B2  (Dio_ChannelType)10/*10-Pin 2 in PORTB*/
#define B3  (Dio_ChannelType)11/*11-Pin 3 in PORTB*/
#define B4  (Dio_ChannelType)12/*12-Pin 4 in PORTB*/
#define B5  (Dio_ChannelType)13/*13-Pin 5 in PORTB*/
#define B6  (Dio_ChannelType)14/*14-Pin 6 in PORTB*/
#define B7  (Dio_ChannelType)15/*15-Pin 7 in PORTB*/
#define C0  (Dio_ChannelType)16/*16-Pin 0 in PORTC*/
#define C1  (Dio_ChannelType)17/*17-Pin 1 in PORTC*/
#define C2  (Dio_ChannelType)18/*18-Pin 2 in PORTC*/
#define C3  (Dio_ChannelType)19/*19-Pin 3 in PORTC*/
#define C4  (Dio_ChannelType)20/*20-Pin 4 in PORTC*/
#define C5  (Dio_ChannelType)21/*21-Pin 5 in PORTC*/
#define C6  (Dio_ChannelType)22/*22-Pin 6 in PORTC*/
#define C7  (Dio_ChannelType)22/*23-Pin 7 in PORTC*/
#define D0  (Dio_ChannelType)24/*24-Pin 0 in PORTD*/
#define D1  (Dio_ChannelType)25/*25-Pin 1 in PORTD*/
#define D2  (Dio_ChannelType)26/*26-Pin 2 in PORTD*/
#define D3  (Dio_ChannelType)27/*27-Pin 3 in PORTD*/
#define D4  (Dio_ChannelType)28/*28-Pin 4 in PORTD*/
#define D5  (Dio_ChannelType)29/*29-Pin 5 in PORTD*/
#define D6  (Dio_ChannelType)30/*30-Pin 6 in PORTD*/
#define D7  (Dio_ChannelType)31/*31-Pin 7 in PORTD*/
#define E0  (Dio_ChannelType)32/*32-Pin 0 in PORTE*/
#define E1  (Dio_ChannelType)33/*33-Pin 1 in PORTE*/
#define E2  (Dio_ChannelType)34/*34-Pin 2 in PORTE*/
#define E3  (Dio_ChannelType)35/*35-Pin 3 in PORTE*/
#define E4  (Dio_ChannelType)36/*36-Pin 4 in PORTE*/
#define E5  (Dio_ChannelType)37/*37-Pin 5 in PORTE*/
#define F0  (Dio_ChannelType)38/*38-Pin 0 in PORTF*/
#define F1  (Dio_ChannelType)39/*39-Pin 1 in PORTF*/
#define F2  (Dio_ChannelType)40/*40-Pin 2 in PORTF*/
#define F3  (Dio_ChannelType)41/*41-Pin 3 in PORTF*/
#define F4  (Dio_ChannelType)42/*42-Pin 3 in PORTF*/

/* DIO Configured Ports */
#define DioConf_PORTA                (Dio_PortType)0 /* PORTA */
#define DioConf_PORTB                (Dio_PortType)1 /* PORTB */
#define DioConf_PORTC                (Dio_PortType)2 /* PORTC */
#define DioConf_PORTD                (Dio_PortType)3 /* PORTD */
#define DioConf_PORTE                (Dio_PortType)4 /* PORTE */
#define DioConf_PORTF                (Dio_PortType)5 /* PORTF */
/* DIO Configured Channel ID's */
#define DioConf_CHANNEL_NUM          (Dio_ChannelType)1 /* Pin 1 */
#endif