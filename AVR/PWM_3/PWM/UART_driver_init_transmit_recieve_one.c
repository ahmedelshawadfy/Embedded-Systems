/*
 * CFile1.c
 *
 * Created: 5/10/2014 1:53:15 PM
 *  Author: Elshawadfy
 */ 


//#include<../service_layer/uart/UART_driver.h>

// define some macros
#define BAUD 9600                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR
	
	// function to initialize UART
void UART_transmit(uint_8 data);
{
		UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
		UBRRL = BAUDRATE;                           // set baud rate
		UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
		UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format
}

void UART_transmit(uint_8 data)
{
	// function to send data

		while (!( UCSRA & (1<<UDRE)));                // wait while register is free
		UDR = data;                                   // load data in the register
	
}


uint_8 UART_recieve (void)
{
	//wait for data to be received
	
	// function to receive data
		while(!(UCSRA) & (1<<RXC));                   // wait while data is being received
		return UDR;                                   // return 8-bit data
	}
}

