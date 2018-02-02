
#include "Stepper.h"

int main(void){
	
	while(1)
	{
		stepper_CW(&DDRC,&PORTC,0x00);
		PORTC |= 0x00;              
	}
}