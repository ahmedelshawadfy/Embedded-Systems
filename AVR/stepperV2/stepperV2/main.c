/*
 * stepperV2.c
 *
 * Created: 20-Oct-17 10:20:41 PM
 *  Author: HP
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	for(uint16_t i=0;i<24*85;i++)
	{
		StepperStepCW();     //Step Clock wise

		_delay_loop_2(10000);
	}

	for(uint16_t i=0;i<24*85;i++)
	{
		StepperStepCCW();    //Step Counter Clock wise

		_delay_loop_2(10000);
	}
}