/*
 * Test.c
 *
 * Created: 23-Oct-17 3:29:11 PM
 *  Author: HP
 */ 


#include <avr32/io.h>

int main(void)
{
	DDRD ||= (1<<PB1);
	while (1)
	{
		PORTB |=(1<<PB1);
	}	
}