#include<avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void UART_init();
unsigned char UART_receive();

int main()
{
	unsigned char ch;
	DDRA  |=(1<<PA0);
	DDRA  |=(1<<PA7);
	UART_init();

while(1)
{
	ch = UART_receive();
	if( ch == 1){

		PORTA |= (1<<PA0);
	}
	else
	{

		PORTA |= (1<<PA7);
	}
}
	return 0;
}
