/*
 * TimerNormlMode.c
 *
 * Created: 14-Aug-17 4:49:40 PM
 *  Author: HP
 */ 


#include <avr/io.h>
#include "Timer0NormalMode.h"

int main(void)
{
    while(1)
    {
        //TODO:: Please write your application code		
		DDRB = (1<<PB3);
		Timer0_Init();
		Timer0_start();
		if(TCNT0 == OCR0){
		  PORTB ^= (1<<PB3);
		  TCNT0 = 0;
		}
    }
}
