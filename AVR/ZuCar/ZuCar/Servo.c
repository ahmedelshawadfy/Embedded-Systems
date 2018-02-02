/*
* @file Servo.c
*
*/


#include "Servo.h"

/* void function to initialize PWM for servo motor  */

void servo_Init()
{
	/* fast pwm _ non inverting _mode 14 _ no prescaler  */
	TCCR1A = (1<<COM1A1) | (1<<WGM11);			 
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS10);
	
	
	TCNT1 = 0;			// start value of timer 
	ICR1 = 19999;      // top value of counter
	
	DDRD |= (1<<5);    // set pin 5 in port D as output 		
	
	
	
}


/* void function to rotate servo motor a specific angle  
	inputs : integer (one byte) take value of angle from 0 ----> 180
	*/

void servo_STEP(uint8 angle)
{
	
	
	uint16 counts;			// local variable for timer counts
	counts = 0;				// initial value 
	/*  calculate number of counts needed to determine duty cycle and rotate motor to desired angle */
	counts = (uint16)(530 + (10*angle) + 1 );		  
	
	OCR1A = counts;		// put counts in OCR1A register 
	
	
}