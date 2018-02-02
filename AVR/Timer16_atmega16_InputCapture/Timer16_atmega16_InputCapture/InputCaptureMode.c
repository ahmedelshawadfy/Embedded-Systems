/*
 * InputCaptureMode.c
 *
 * Created: 19-Oct-17 12:52:06 PM
 *  Author: HP
 */ 

#include <avr/io.h>

void Input_Capture_Init()
{
	//set clock source to enable timer(internal clock...with no prescaler)
	//select Input Caputre mode by default and select falling edge as trigger
	TCCR1B |= (1<<CS10);	
	//enable interrupt for ICP1 pin(PD6)
	TIMSK |=(1<<TICIE1);	
}

uint16_t Read_Input_Pulse()
{
	uint16_t signal;
	//read first 8_bit
	signal = ICR1L;
	//read second 8_bit
	signal = (ICR1H<<8);
	return signal;
}
