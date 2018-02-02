/*
 * lcd.c
 *
 * Created: 07-Dec-17 5:59:55 PM
 *  Author: HP
 */ 
#include <avr/io.h>
#include <util/delay.h>
#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif





void lcd_display(uint8_t *data)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	Lcd4_Init();
	Lcd4_Clear();
	Lcd4_Set_Cursor(0,0);
	Lcd4_Write_String(data);
}
