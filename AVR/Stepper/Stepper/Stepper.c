/*
 * Stepper.c
 *
 * Created: 20-Oct-17 6:17:20 PM
 *  Author: HP
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "Stepper.h"
#define F_CPU 16000000UL



void stepper_CW(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 200
	for(int x = 0; x < 1; x++){	
	*ddr = 0x0f;
	*port = pins;    //Enable output on all of the B pins 
	*port = BLUE;   //1st coil
	 _delay_ms(DELAY);    //delay
	*port = BLACK;  //2nd coil
	 _delay_ms(DELAY);    //delay
	*port = RED;    //3rd coil
	 _delay_ms(DELAY);     //delay
	*port = YELLOW; //4th coil
	 _delay_ms(DELAY);     //delay
	}
	*port = pins;
}

void stepper_CCW(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 200
	*ddr = pins;    /* Enable output on all of the B pins */
	*port = YELLOW;
	_delay_ms(DELAY);
	*port = RED;
	_delay_ms(DELAY);
	*port = BLACK;
	_delay_ms(DELAY);
	*port = BLUE;
	_delay_ms(DELAY);
}

void speed1(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 250
	*ddr = pins;    //Enable output on all of the B pins
	*port = BLUE;   //1st coil
	_delay_ms(DELAY);    //delay
	*port = BLACK;  //2nd coil
	_delay_ms(DELAY);    //delay
	*port = RED;    //3rd coil
	_delay_ms(DELAY);     //delay
	*port = YELLOW; //4th coil
	_delay_ms(DELAY);     //delay
}

void speed2(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 280
	*ddr = pins;    //Enable output on all of the B pins
	*port = BLUE;   //1st coil
	_delay_ms(DELAY);    //delay
	*port = BLACK;  //2nd coil
	_delay_ms(DELAY);    //delay
	*port = RED;    //3rd coil
	_delay_ms(DELAY);     //delay
	*port = YELLOW; //4th coil
	_delay_ms(DELAY);     //delay
}
void speed3(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 300
	*ddr = pins;    //Enable output on all of the B pins
	*port = BLUE;   //1st coil
	_delay_ms(DELAY);    //delay
	*port = BLACK;  //2nd coil
	_delay_ms(DELAY);    //delay
	*port = RED;    //3rd coil
	_delay_ms(DELAY);     //delay
	*port = YELLOW; //4th coil
	_delay_ms(DELAY);     //delay
}
void speed4(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins)
{
	#define DELAY 350
	*ddr = pins;    //Enable output on all of the B pins
	*port = BLUE;   //1st coil
	_delay_ms(DELAY);    //delay
	*port = BLACK;  //2nd coil
	_delay_ms(DELAY);    //delay
	*port = RED;    //3rd coil
	_delay_ms(DELAY);     //delay
	*port = YELLOW; //4th coil
	_delay_ms(DELAY);     //delay
}