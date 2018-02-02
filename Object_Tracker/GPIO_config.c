/*
 * GPIO_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdalrahman Alhasn
 */


#include "GPIO_config.h"

void pinAmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
     * takes two inputs   */

    /* enable clock on port A */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTA_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTA_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTA_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTA_DEN_R |= (1<<pin_numper);


}


void pinBmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
         * takes two inputs   */

    /* enable clock on port B */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTB_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTB_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTB_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTB_DEN_R |= (1<<pin_numper);


}

void pinCmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
         * takes two inputs   */

    /* enable clock on port A */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTC_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTC_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTC_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTC_DEN_R |= (1<<pin_numper);


}

void pinDmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
         * takes two inputs   */

    /* enable clock on port A */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTD_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTD_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTD_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTD_DEN_R |= (1<<pin_numper);


}

void pinEmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
         * takes two inputs   */

    /* enable clock on port A */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTE_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTE_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTE_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTE_DEN_R |= (1<<pin_numper);


}

void pinFmode(char direction ,char pin_numper)
{
    /* void function to initialize the pin as i/o digital pin
         * takes two inputs   */

    /* enable clock on port A */
    SYSCTL_RCGCGPIO_R |= (1<<0);

    /* set direction of pin 1 for output and 0 for input */
    if(direction == output)
    {
        GPIO_PORTF_DIR_R |= (1<<pin_numper);
    }

    else if(direction == input)
    {
        GPIO_PORTF_DIR_R &= (~(1<<pin_numper));

    }

    /* disable alternative function on pin */
    GPIO_PORTF_AFSEL_R &= (~(1<<pin_numper));

    /* enable digital GPIO on pin */
    GPIO_PORTF_DEN_R |= (1<<pin_numper);


}

void ports_clock_EN()
{
    SYSCTL_RCGCGPIO_R |= 0x00001F;

}
