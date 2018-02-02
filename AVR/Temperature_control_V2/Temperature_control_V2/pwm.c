
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL


void pwm_init()
{
	DDRB |=  (1<<1);//set OC1A as output PORTB1 pin15
	// use 8-bit mode PWM by setting the WGM10 and the WGM12 bits
	TCCR1A |= (1<<COM1A1) | (1<<WGM10);
	TCCR1B |= (1<<WGM12) | (1<<CS11);         //set clock / 8 prescaler0b00001010;

}

void pwm_output(uint8_t duty)
{
	OCR1A = duty;
	//_delay_ms(100);
}