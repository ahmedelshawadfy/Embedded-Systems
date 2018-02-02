/*
 * Tiva_i2c.h
 *
 *  Created on: Nov 27, 2017
 *      Author: HP
 */

#ifndef TIVA_I2C_H_
#define TIVA_I2C_H_
void initI2C0(void);
uint8_t readI2C0(uint16_t device_address, uint16_t device_register);
void writeI2C0(uint16_t device_address, uint16_t device_register, uint8_t device_data);




#endif /* TIVA_I2C_H_ */
