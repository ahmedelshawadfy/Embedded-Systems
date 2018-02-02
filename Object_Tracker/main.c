/*
 * main.c
 *
 * Created on: 23 NOV 2017
 *
 */

#include "UART.h"
#include "GPIO_config.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

int main(void)
{
    uint8_t byte ;
    ports_clock_EN();           // enable clk on all ports.
    uart_init(1);
    pinAmode(output,5);

    while (1)
    {
        uart_send_byte(1,'1');
        if(byte == 1)
            GPIO_PORTA_DATA_R = 0xFF;
        else
            GPIO_PORTA_DATA_R = 0x00;
        if(byte == '1')
            GPIO_PORTA_DATA_R = 0xFF;
        else
            GPIO_PORTA_DATA_R = 0x00;


    }
    return 0;
}
