/*
 * GPIO_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdalrahman Alhasn
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#define output 1
#define input 0

#include "tm4c123gh6pm.h"
#include <stdint.h>

void pinAmode(char direction,char pin_numper);
void pinBmode(char direction,char pin_numper);
void pinCmode(char direction,char pin_numper);
void pinDmode(char direction,char pin_numper);
void pinEmode(char direction,char pin_numper);
void pinFmode(char direction,char pin_numper);
void ports_clock_EN();

#endif /* GPIO_CONFIG_H_ */
