/*
 * timer.c
 *
 * Created: 06-Dec-17 11:29:35 PM
 *  Author: HP
 */ 
#include "timer.h"

void timer1_init()
{
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	
	// initialize counter
	TCNT1 = 0;
	
	// initialize compare value
	OCR1A = 31250;
	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);
    sei();
}
