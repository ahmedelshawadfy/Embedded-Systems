

/**
* 
* @file main.c
* @author Hardware SubGroup
* @date 1 Dec 2017
* @brief This is the main file of the project
*
* 
* \mainpage Description
*  This is our ZuCar Software drivers for Tiva C (ARM-based microcontroller 32-bit) and AVR32 8-bit

*  \section AVR_Drivers AVR Drivers
*  \subsection for_AVR Ultrasonic, Servo, stepper and DC motor
*   we use AVR to drive all actuatuors we use in this project like stepper and sensors like ultrasonics
*   .
*
*  \section Tiva_C_Drivers Tiva C Drivers
*  \subsection Tiva Serial Communication 
*  We use Tiva C as our main microcontroller that communicaties with other microcontrollers like AVR. \n
*  We developed a library for uart to control serial communication between tiva and other microcontrollers in the system.
*
*
*
*
*/
#include <avr/io.h>
#include "UART.h"
#include "DC_motor.h"
#include "Servo.h"


int main(void)
{
		servo_Init();
		servo_STEP(uint8 angle);
    return 0;
}

