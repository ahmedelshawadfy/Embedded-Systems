#include "tm4c123gh6pm.h"
#include <stdint.h>


void module_init()
{
    uint32_t delay;
    //Enable the ADC clock using the RCGCADC register
    //SYSCTL_RCGC0_R |= SYSCTL_RCGC0_ADC0;//This bit controls the clock gating for ADC module 0
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;//ADC Module 0 Run Mode Clock Gating Control
    //Enable the clock to the appropriate GPIO modules
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE;;//enable clock for port E for potentiometer
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;//enable clock for port F for led
    delay = SYSCTL_RCGC2_R;
    delay = SYSCTL_RCGC2_R;
    //Set the GPIO AFSEL bits for the ADC input pins
    GPIO_PORTE_AFSEL_R |= (1<<1);
    //Configure the AINx signals to be analog inputs
    GPIO_PORTE_DEN_R &= ~(1<<1);
    //Disable the analog isolation circuit for all ADC input pins
    GPIO_PORTE_AMSEL_R |= (1<<1);
}

void ADC_seq_init()
{
    //Ensure that the sample sequencer is disabled
    ADC0_ACTSS_R &= ~0x8;
    //Configure the trigger event
    ADC0_EMUX_R |= ADC_EMUX_EM3_ALWAYS ;// continuous sampling
    //configure the corresponding input source
    //ADC0_SSMUX3_R |= 2;//AIN2
    //For each sample in the sample sequence, configure the sample control bits
    //enable interrupt and select just one sample and and read from temp. sensor
    ADC0_SSCTL3_R |= ADC_SSCTL3_TS0 | ADC_SSCTL3_END0 | ADC_SSCTL3_IE0;
    //fire the interrupt at the end of conversion
    ADC0_IM_R |= ADC_IM_MASK3;// enable interrupt for seq.3
    //Enable the sample sequencer logic
    ADC0_ACTSS_R |= 0x8;
    //enable interrupt module
    NVIC_EN0_R |= (1<<33);
}



