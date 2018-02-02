/*
 * stepper.c
 *
 * Created: 27-Oct-17 9:41:03 AM
 *  Author: HP
 */ 


#include <avr/io.h>
#include "macros.h"

int main(void)
{
    while(1)
    {
        //Initialize pins as input or output 
		set_Direction_output(DDRD,PD5);// X_step pin
		set_Direction_output(DDRD,PD3);// X_dir pin
		set_Direction_output(DDRD,PD6);// X_enable 
		set_Direction_output(DDRB,PB3);// y_step pin
		set_Direction_output(DDRB,PB2);// y_dir pin
		set_Direction_output(DDRB,PB4);// y_enable pin
		//Intialize pins HIGH or LOW
		clear_Bit(PORTD,PD6);// set X_enable as low
		clear_Bit(PORTB,PB4);// set y_enable as low
		
    }
}