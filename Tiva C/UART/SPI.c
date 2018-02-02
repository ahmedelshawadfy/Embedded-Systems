/*
 * SPI.c
 *
 *  Created on: Oct 20, 2017
 *      Author: HP
 */

#include <tm4c123gh6pm.h>

void Nokia5110_Init(void){
  volatile unsigned long delay;
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_SSI0;  // activate SSI0
  delay = SYSCTL_RCGC2_R;               // allow time to finish activating
  GPIO_PORTA_AFSEL_R |= 0x3C;           // enable alt funct on PA2,3,4,5
  GPIO_PORTA_DEN_R |= 0x3C;             // enable digital I/O on PA2,3,4,5
                                        // configure PA2,3,4,5 as SSI
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFF0F00FF)+0x00222200;
  GPIO_PORTA_AMSEL_R &= ~0x3C;          // disable analog functionality on PA2,3,5,6,7
  SSI0_CR1_R &= ~SSI_CR1_SSE;           // disable SSI
  SSI0_CR1_R = SSI_CR1_MS;              // slave mode
                                        // configure for system clock/PLL baud clock source
  SSI0_CC_R = (SSI0_CC_R&~SSI_CC_CS_M)+SSI_CC_CS_SYSPLL;
                                        // clock divider for 3.125 MHz SSIClk (50 MHz PIOSC/16)
  SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CPSR_CPSDVSR_M)+16;
  SSI0_CR0_R &= ~(SSI_CR0_SCR_M |       // SCR = 0 (3.125 Mbps data rate)
                  SSI_CR0_SPH |         // SPH = 0
                  SSI_CR0_SPO);         // SPO = 0
                                        // FRF = Freescale format
  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
                                        // DSS = 8-bit data
  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
  SSI0_CR1_R |= SSI_CR1_SSE;            // enable SSI
}


