

/**
 * main.c
 */

#define PF4 (*((volatile unsigned long *)0x40025040))
#define PF3 (*((volatile unsigned long *)0x40025020))
#define PF2 (*((volatile unsigned long *)0x40025010))
#define PF1 (*((volatile unsigned long *)0x40025008))
#define PF0 (*((volatile unsigned long *)0x40025004))

#include "tm4c123gh6pm.h"
#include <stdint.h>

volatile int temperature = 0;
uint32_t delay = 0;

void portF_init()
{
    //enable clock for port f
        SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
        delay = SYSCTL_RCGC2_R;// give it some time to make sure that is enabled
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        GPIO_PORTF_CR_R =0x1F;
        GPIO_PORTF_AMSEL_R |= 0x00;
        GPIO_PORTF_PCTL_R = 0x00000000;
        GPIO_PORTF_DIR_R |= 0x0E;
        GPIO_PORTF_AFSEL_R |= 0x00;
        GPIO_PORTF_DEN_R |= 0x1F;
}

void wTimer0_init(int timer_number)
{
    SYSCTL_RCGCWTIMER_R |= 1;
    WTIMER0_CTL_R = 0;
    WTIMER0_CFG_R = 0X04;
    WTIMER0_TAMR_R = 0x02;
    WTIMER0_TAILR_R = timer_number;
    WTIMER0_CTL_R = 0x20;
    WTIMER0_CTL_R = 0x01;
}

void PLL_init(int divid_num)
{
    SYSCTL_RCC2_R |= 0x80000000;
    SYSCTL_RCC2_R |= 0x00000800;
    SYSCTL_RCC_R   = (SYSCTL_RCC_R & ~0x000007C0)+0x00000540;
    SYSCTL_RCC2_R &= ~0x00000070;
    SYSCTL_RCC2_R &= ~0x00020000;
    SYSCTL_RCC2_R |= 0x40000000;
    SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (divid_num<<22);
    while((SYSCTL_RIS_R & 0x00000040) == 0){};
    SYSCTL_RCC2_R &= ~0x00000000;
}

void adc_init()
{
            uint32_t delay;
            //Enable the ADC clock using the RCGCADC register
            //SYSCTL_RCGC0_R |= SYSCTL_RCGC0_ADC0;//This bit controls the clock gating for ADC module 0
            SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;//ADC Module 0 Run Mode Clock Gating Control
            delay = SYSCTL_RCGCADC_R;
            delay = SYSCTL_RCGCADC_R;
            delay = SYSCTL_RCGCADC_R;
            //Ensure that the sample sequencer is disabled
            ADC0_ACTSS_R &= ~0x8;
            //Configure the trigger event
            ADC0_EMUX_R |= ADC_EMUX_EM3_ALWAYS ;// continuous sampling
            //configure the corresponding input source
            ADC0_EMUX_R |= 0x5000;
            ADC0_SSMUX3_R |= 0;//AIN2
            //For each sample in the sample sequence, configure the sample control bits
            //enable interrupt and select just one sample and and read from temp. sensor
            ADC0_SSCTL3_R |= 0x0E;
            //fire the interrupt at the end of conversion
            ADC0_IM_R |= ADC_IM_MASK3;// enable interrupt for seq.3
            //Enable the sample sequencer logic
            //enable interrupt module
            NVIC_EN0_R |= (1<<17);
            ADC0_ACTSS_R |= 0x8;
}
int main(void)
{
    PLL_init(79);
    portF_init();
    wTimer0_init(4000000);
    adc_init();
    while(1)
    {
        if(PF0 == 0x0 && !(PF4 == 0))
        {
            PLL_init(4);
            wTimer0_init(80000000);
        }
        if(PF4 == 0 && !(PF0 == 0))
        {
            PLL_init(79);
            wTimer0_init(40000000);
        }
    }
	return 0;
}

void adc()
{

    temperature = (147.5 - (247.5 * ADC0_SSFIFO3_R)/4096.0);
    if(temperature >= 0 && temperature < 40)
        GPIO_PORTF_DATA_R = 0b0010;
    ADC0_ISC_R = 8;
}
