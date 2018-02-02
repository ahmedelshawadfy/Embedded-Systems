/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdalrahman Alhasn
 */

#ifndef UART_H_
#define UART_H_

#include "registers_config.h"
#include "std_types.h"
//#include "tm4c123gh6pm.h"
void uart_init(uint8 uart_num);
void uart_send_byte(uint8 uart_num,uint8 data);
uint8 uart_recieve_byte(uint8 uart_num);


#endif /* UART_H_ */
