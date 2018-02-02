/*
 * stepper.c
 *
 * Created: 24-Nov-17 1:48:28 PM
 *  Author: HP
 */ 
// defines pins numbers

#include <avr/io.h>
#include <stdint.h>
#include "UART.h"
uint32_t duty ;

void stepper(){

	char incomingByte1[2];
	for (uint8_t i = 0; i<2; i++)
	{
		incomingByte1[i] = USART_Receive();
	}
	
	if(incomingByte1[1] != '-')    //if sent value larger than 0 means move motor in the positive direction
	{
		//memorize the last value as refrence
		if(incomingByte1[0] >= reference)//check if the last value larger than the refrence, if so move motor in the positive direction
		{
			set_Bit(PORTD,PD3);//digitalWrite(x_dirPin,HIGH);
			for(uint8_t x = 0; x < incomingByte1[0]; x++)
			{
				stepper_pwm(duty);
			}
			reference = incomingByte1[0];//store the last value as reference
		}
		else
		{
			
			clear_Bit(PORTD,PD3);//digitalWrite(x_dirPin,LOW);
			for(uint8_t x = incomingByte1[0]; x < 0; x--)
			{
				stepper_pwm(duty);
			}
			reference = incomingByte1[0];
		}
	}
	else//if sent value is smaller than 0 means move motor in the negative direction
	{
		if(incomingByte1[0] <= reference)
		{
			clear_Bit(PORTD,PD3);//digitalWrite(x_dirPin,LOW);
			for(uint8_t x = incomingByte1[0]; x <= 0; x--)
			{
				stepper_pwm(duty);
			}
		reference = incomingByte1[0];}
		else{
			set_Bit(PORTD,PD3);//digitalWrite(x_dirPin,HIGH);
			for(uint8_t x = incomingByte1[0]; x <= 0; x--)
			{
				stepper_pwm(duty);
			}
			reference = incomingByte1[0];
		}
	}
}

void stepper_pwm(uint32_t duty)
{
	OCR1A = duty;
}
