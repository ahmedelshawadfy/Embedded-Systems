#include "tm4c123gh6pm.h"

void portF_init(
     unsigned char pinnumber,
     unsigned char io,
     unsigned char unlock,
     volatile unsigned long delay)
{

    SYSCTL_RCGC2_R |= 0x00000020; // activate clock for Port F

    delay = SYSCTL_RCGC2_R; // allow time for clock to start

    if(unlock == 1)

       GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock GPIO Port F

   GPIO_PORTF_CR_R |= pinnumber; // allow changes to pin number

   // only PF0 needs to be unlocked, other bits can't be locked

    GPIO_PORTF_AMSEL_R = 0x00; // disable analog

    GPIO_PORTF_PCTL_R = 0x00000000; // PCTL GPIO

    GPIO_PORTF_DIR_R |= io; //

    GPIO_PORTF_AFSEL_R = 0x00; // disable alt funct

    GPIO_PORTF_PUR_R |= ~(1<<io);// enable pull-up for input pins only

    GPIO_PORTF_DEN_R |= pinnumber; // enable digital I/O on PF4-0

}
