#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void UART_init();
void UART_Transmit(unsigned char Data);

int main()
{
	 DDRD  &= ~(1<<PD4 );
	 UART_init();
while(1)
{
	 if(PIND & (1<<PD4))
		 UART_Transmit(1);
	 else
		 UART_Transmit('b');
}
	 return 0;
}
