/*
 * pwm.c
 *
 * Created: 24-Nov-17 12:09:41 AM
 *  Author: Ahmed El Shawadfy
 */ 
#include <avr/io.h>
#include <stdint.h>
#include "macros.h"

void pwm_init()
{
	/* set the wave generation mode as fast pwm */
	TCCR1B |= 0x19;  //set the clock source
	TCCR1A |= 0x53;  //set the output compare mode as toggle the OC1A
	
	set_Direction_output(DDRB,PB1); // set PB1 as Output compare pin "OC1A"
}