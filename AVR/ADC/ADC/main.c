#include <avr/io.h>
#define PORT_ON(port,pin) port |= (1<<pin)
#define PORT_OFF(port,pin) port &= ~(1<<pin)
int main(void)
{
	unsigned int adc_value; // Variable to hold ADC result
	DDRC=0xff; // Set Port D as Output
	PORTC = 0x00;
	
	ADC_INIT();
	
	while (1)
	{
		adc_value = ADC_CONV(0); // Start conversion
		//adc_value = ADC; //Store ADC value
		if (adc_value < 512)
		{
			PORT_OFF(PORTC,7); // Toggle LEDs
			PORT_ON (PORTC,6);
		}
		else
		{
			PORT_ON(PORTC,7); // Toggle LEDs
			PORT_OFF (PORTC,6);
		}
	}
}