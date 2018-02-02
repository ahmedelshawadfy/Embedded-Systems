#include "tm4c123gh6pm.h"
#include <stdint.h>

void led_init()
{
    uint32_t delay;
    //enable clock for port f
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
    delay = SYSCTL_RCGC2_R;// give it some time to make sure that is enabled
    GPIO_PORTF_DEN_R |= 0x01;// select the digital I/O function
    GPIO_PORTF_AFSEL_R |= 0x00; //disable the analog function
    GPIO_PORTF_AMSEL_R |= 0x00;
    GPIO_PORTF_DIR_R |= 0xff; // set the pins as output
    GPIO_PORTF_DATA_R |= 0x01; //set the pins as HIGH
}

