


#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


int main(void)
{
	uint8_t data[15] = {"FUCK "};
    lcd_display(data);
    while(1);
}