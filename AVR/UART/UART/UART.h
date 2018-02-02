/*
 * UART.h
 *
 * Created: 27-Oct-17 12:38:31 PM
 *  Author: HP
 */ 


#ifndef UART_H_
#define UART_H_

#include<avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL
#define BAUDRATE  ((F_CPU)/(BAUD*16UL)-1)

void USART_Init( unsigned int ubrr);
void USART_Transmit( unsigned char data );
unsigned char USART_Receive( void );

#endif /* UART_H_ */