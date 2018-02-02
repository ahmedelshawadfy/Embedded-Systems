

/**
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ADC_seq_init.h"
#include "port_init.h"

uint32_t result = 0;

int main(void)
{
    led_init();
    module_init();
    ADC_seq_init();
   // ADC0_PSSI_R |= ADC_PSSI_SS3;
    while(1)
    {
        if(result>0)
            GPIO_PORTF_DATA_R |= (1<<1);//red led on
        else
            GPIO_PORTF_DATA_R &= ~(1<<1);//red led off

    }
	return 0;
}
void ADCSS3Handler(void)
{
    result = ADC0_SSFIFO3_R; //read conversion result
    ADC0_ISC_R = 0x8;//clear interrupt flag
}
