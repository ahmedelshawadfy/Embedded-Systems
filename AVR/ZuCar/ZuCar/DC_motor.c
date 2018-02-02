/*
 * DC_motor.c
 *
 *  Created on: Nov 25, 2017
 *      Author: embedded
 */

/**
* @file DC_motor.h
*/
#include "DC_motor.h"

void TIMER0_PWM(char dutyCycle){
	DDRB  |=(1<<3);
	OCR0   = dutyCycle;
	TCCR0  = 0x73; // phase correct - no prescaler

}

void motor_dir(char dir){
	if(dir==0){
		PORTD |=(1<<0);
		PORTD &= ~(1<<1);

	}
	else {
		PORTD |=(1<<1);
		PORTD &= ~(1<<0);

	}

}
