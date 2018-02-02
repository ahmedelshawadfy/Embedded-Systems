/*
 * UART.c
 *
 * Created: 27-Oct-17 9:56:30 AM
 *  Author: HP
 */ 

#include "UART.h"
#include "macros.h"
#define BAUD  9600

int main(void)
{
    while(1)
    {
		uint8_t ch;
        //TODO:: Please write your application code
		USART_Init(BAUDRATE);
		ch = USART_Receive();
		if (ch == 'a')
		{
			set_Bit(DDRC,PC5);
			set_Bit(PORTC,PC5);
		}
		 
    }
}