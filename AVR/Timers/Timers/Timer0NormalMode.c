/*
 * Timer0NormalMode.c
 * 
 * Created: 14-Aug-17 4:51:56 PM
 *  Author: HP
 */ 
#include <avr/io.h>
void Timer0_Init(void)
{
	//set clock source to enable timer(internal clock...with 1024 prescaler)
	  TCCR1B |= (1<<CS00);
	//select mode(Normal Mode set by default..toggle the OC0)
	  TCCR0 |= (1<<COM00);
}
//load timer register with value(10ms)
void Timer0_start()
{
	OCR0 |= 157;
}