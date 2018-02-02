#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART_driver_one.h"
void Wait()
{
	uint16_t i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}
}
int main()
{
	//FOR TIMER1
	int i;
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	ICR1=4999;  //fPWM=50Hz
	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Output
	while(1)
	{
		if(UART_recieve (void)=='l') //Turn left
		{ 
		for(i=316; i<=535; i++)
		{
			OCR1A=i;
			if(UART_recieve (void)) //receive 0 from GPU to stop moving
			break;
		}
		}
		Wait();
		if(UART_recieve (void)=='r') //Turn right
		{ 
		for(i=535; i>=97; i--)
		{
			OCR1A=i;
			if(UART_recieve (void)) //receive 0 from GPU to stop moving
			
		}
		Wait();
		}
		
	}
	return 0;
}