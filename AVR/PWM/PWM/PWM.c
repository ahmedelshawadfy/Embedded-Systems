#include <avr/io.h>
void PWM_init()
{
	/*// enable timer by selecting the clock source with no prescaler
	TCCR0 |= (1<<CS00);
	// select the mode(PWM mode...) and OC0 behavior (clear the bit on match)
	TCCR0 |= (1<<WGM00) |(1<<COM01);*/
	
	 TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
}
