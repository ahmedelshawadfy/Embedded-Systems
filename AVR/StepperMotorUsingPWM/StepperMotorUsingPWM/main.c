/*
 * Control Stepper Motor Using PWM
 *
 * Created: 23-Nov-17 7:57:48 PM
 *  Author: Ahmed El Shawadfy
 */ 


#include <avr/io.h>
#include <util/delay_basic.h>
#include "macros.h"
#include "pwm.h"
#include "stepper.h"
#define F_CPU 16000000UL
uint8_t reference = 0;

int main(void)
{
	// 	const int x_stepPin = 5;
	// 	const int x_dirPin = 3;
	// 	const int x_enable =6;
    // 	Sets the two pins as Outputs
    // 	pinMode(x_stepPin,OUTPUT);
	// 	pinMode(x_dirPin,OUTPUT);
	// 	digitalWrite(x_enable,LOW);

	DDRD|=(1<<PD5)|(1<<PD3)|(1<<PD6);
	PORTD |= (1<<PD5)|(1<<PD3)|(0<<PD6);
	
	pwm_init();
	USART_Init();
    while(1)
    {
		//receive the value from the slider1
       
		unsigned char ch = USART_Receive();
		if (ch =='q')
		{
			duty = 16383;//.25 duty cycle
		}
		else if (ch =='h')
		{
			duty = 32767;//.5 duty cycle
		}
		else
		{
			duty = 49151;//.75 duty cycle
		}
		 
	    stepper();
		_delay_loop_2(3200);
    }
}