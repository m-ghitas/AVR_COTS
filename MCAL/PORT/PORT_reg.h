#ifndef PORT_REG_H
#define PORT_REG_H

/********PORTA if Existed******************
#define  PORTA		*((volatile uint8*)0x3B)
#define  DDRA		*((volatile uint8*)0x3A)
*******************************************/


#define PORTB  		*((volatile uint8*)0x25)
#define DDRB   		*((volatile uint8*)0x24)

#define PORTC  		*((volatile uint8*)0x28)
#define DDRC   		*((volatile uint8*)0x27)

#define PORTD  		*((volatile uint8*)0x2B)
#define DDRD   		*((volatile uint8*)0x2A)

#endif
