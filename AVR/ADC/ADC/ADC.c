/*
 * ADC.c
 *
 * Created: 04-Aug-17 3:19:33 AM
 *  Author: HP
 */ 

#include <avr/io.h>
 void ADC_INIT();
 uint16_t ADC_CONV(uint8_t channel);
 
 void ADC_INIT()
 {
	 ADMUX |= (1<<REFS0) ; // set reference and channel
	 ADCSRA |= (1<<ADIE) | (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2); // enable ADC module and select prescaler
 }
 
 uint16_t ADC_CONV(uint8_t channel)
 {
	 channel &= 0x07; // anding with 7 will always keep the value between 0 and 7
	 
	 ADMUX = (ADMUX & 0xF8)|channel; // clear last three bits and select desired channel 
	 
	 ADCSRA |= (1<<ADSC); // start conversion1
	 
	 // wait till conversion completes and ADSC becomes 0
	 while(ADCSRA & (1<<ADSC))
	 ;
	 return ADC ;
 }