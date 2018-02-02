1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
/*
 * PWM.c
 *
 * Created: 3/20/2013 9:29:11 PM
 *  Author: SAM
 */
 
#define F_CPU   20000000
 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 
double dutyCycle = 0;
 
int main(void)
{   
    DDRD = (1 << PORTD6);
     
    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TIMSK0 = (1 << TOIE0);
     
    OCR0A = (dutyCycle/100.0)*255.0;
     
    sei();
     
    TCCR0B = (1 << CS00) | (1 << CS02);
     
    while(1)
    {
        //TODO:: Please write your application code
        _delay_ms(100);
         
        dutyCycle += 10;
         
        if(dutyCycle > 100)
        {
            dutyCycle = 0;
        }                       
    }
}
 
ISR(TIMER0_OVF_vect)
{
    OCR0A = (dutyCycle/100.0)*255;
}