/*
 * UART.h
 *
 *  Created on: ??�/??�/????
 *      Author: Abdalrahman Alhasn
 */

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "tm4c123gh6pm.h"
void uart_init(uint8 uart_num);
void uart_send_byte(uint8 uart_num,uint8 data);
uint8 uart_recieve_byte(uint8 uart_num);


#endif /* UART_H_ */
