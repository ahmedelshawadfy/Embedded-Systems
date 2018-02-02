//#define TARGET_IS_TM4C123_RA1

#include "driverlib/pin_map.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

void delayMS(int ms) {
    SysCtlDelay( (SysCtlClockGet()/(3*1000))*ms ) ;
}

int
main(void)
{
    //ROM_GPIOADCTriggerEnable(GPIO_PORTB_BASE, GPIO_PIN_6);
    //Set the clock
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

   // Enable the peripherals used by this program.
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
    //SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);

    //Configure PF1,PF2,PF3 Pins as PWM
    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    GPIOPinConfigure(GPIO_PF2_M1PWM6);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);

    //Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7 See page 207 4/11/13 DriverLib doc
   /\PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
   // PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_6);
    //Set the Period (expressed in clock ticks)
   // PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, 320);
   // PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 320);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 320);

    //Set PWM duty-50% (Period /2)
    /*PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,100);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,100);*/
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,100);

    // Enable the PWM generator
   /* PWMGenEnable(PWM1_BASE, PWM_GEN_2);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);*/
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);

    // Turn on the Output pins
   // PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, true);
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT , true);
    //Fade
    bool fadeUp = true;
    unsigned long increment = 10;
    unsigned long pwmNow = 100;
    while(1)
    {
        delayMS(20);
        if (fadeUp) {
            pwmNow += increment;
            if (pwmNow >= 320) { fadeUp = false; }
        }
        else {
            pwmNow -= increment;
            if (pwmNow <= 10) { fadeUp = true; }
        }
        PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,pwmNow);
      /*  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,pwmNow);
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);
        PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,pwmNow);*/
    }

}
