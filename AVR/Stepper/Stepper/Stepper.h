/*
 * Stepper.h
 *
 * Created: 20-Oct-17 6:17:56 PM
 *  Author: HP
 */ 



#ifndef STEPPER_H_
#define STEPPER_H_

#include <avr/io.h>

#ifndef BLUE
#define BLUE _BV(PC0)
#endif

#ifndef BLACK 
#define BLACK _BV(PC1)
#endif

#ifndef RED
#define RED _BV(PC2)
#endif

#ifndef YELLOW
#define YELLOW _BV(PC3)
#endif

void stepper_CW(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);
void stepper_CCW(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);
void speed1(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);
void speed2(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);
void speed3(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);
void speed4(uint8_t volatile *ddr, uint8_t volatile *port, uint8_t pins);




#endif /* STEPPER_H_ */