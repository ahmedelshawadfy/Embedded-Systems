/*
 * DC_motor.h
 *
 *  Created on: Nov 25, 2017
 *      Author: embedded
 */


/**
* @file DC_motor.h
*/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include<avr/io.h>

#define CCW 0
#define CW  1




void TIMER0_PWM(char dutyCycle);
void motor_dir(char dir);

#endif /* DC_MOTOR_H_ */
