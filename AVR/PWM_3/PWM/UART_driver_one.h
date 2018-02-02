
#ifndef _UART_ONE_H_ 
#define _UART_ONE_H_


//#include <../hal/mc_headerfile.h>
//#include <../compiler/types.h>
//#include <../compiler/utils.h>
//#include <../ecual/UART_assignment_one/ecual_one.h>

#define BAUD_RATE 6

void hardware_init(void);

void UART_init(uint_16 baud_rate);
 
void UART_transmit(uint_8 data);
 
uint8_t UART_recieve (void);
 
 
 #endif