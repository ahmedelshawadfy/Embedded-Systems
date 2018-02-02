/*
 * uart.c
 *
 *  Created on: Oct 19, 2017
 *      Author: HP
 */
// Assumes a 80 MHz bus clock, creates 115200 baud rate

#include<tm4c123gh6pm.h>


void UART_Init(unsigned char channelNumber,
               unsigned char pinNumber){ // should be called only once
switch(channelNumber)
{
case 0:
    SYSCTL_RCGC1_R |= 0x00000001; // activate UART4
    SYSCTL_RCGC2_R |= 0x00000004; // activate port C
    UART4_CTL_R &= ~0x00000001; // disable UART
    UART4_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART4_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART4_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART4_CTL_R |= 0x00000301;// enable UART
       if(pinNumber == 0x30){
             GPIO_PORTC_AFSEL_R |= 0x30; // enable alt funct on PC5-4
             GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1
             GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000;
       }
       GPIO_PORTC_AMSEL_R &= ~0x30; // disable analog on PC5-4
    break;
case 1:
    SYSCTL_RCGC1_R |= 0x00000002; // activate UART1
    SYSCTL_RCGC2_R |= 0x00000004; // activate port C
    UART1_CTL_R &= ~0x00000001; // disable UART
    UART1_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART1_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART1_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART1_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0x30)
    {
          GPIO_PORTC_AFSEL_R |= 0x30; // enable alt funct on PC5-4
          GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1
          GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00220000;
    }
    if(pinNumber == 0x03)
    {
          SYSCTL_RCGC1_R |= 0x00000002; // activate UART1
          SYSCTL_RCGC2_R |= 0x00000002; // activate port B
          UART1_CTL_R &= ~0x00000001; // disable UART
          UART1_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
          UART1_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
          UART1_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
          UART1_CTL_R |= 0x00000301;// enable UART
          GPIO_PORTB_AFSEL_R |= 0x03; // enable alt funct on PC5-4
          GPIO_PORTB_DEN_R |= 0x03; // configure PC5-4 as UART1
          GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTB_AMSEL_R &= ~0x03; // disable analog on PC5-4
break;
case 2 :
    //PORT D
    SYSCTL_RCGC1_R |= 0x00000002; // activate UART2
    SYSCTL_RCGC2_R |= 0x00000008; // activate port D
    UART2_CTL_R &= ~0x00000001; // disable UART
    UART2_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART2_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART2_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART2_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0xC0)
    {
       GPIO_PORTD_AFSEL_R |= 0xC0; // enable alt funct on PD7-6
       GPIO_PORTD_DEN_R |= 0xC0; // configure PD7-6 as UART2
       GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTD_AMSEL_R &= ~0xC0; // disable analog on PD7-6
    break;
case 3:
    //Port C
    SYSCTL_RCGC1_R |= 0x00000004; // activate UART3
    SYSCTL_RCGC2_R |= 0x00000004; // activate port C
    UART3_CTL_R &= ~0x00000001; // disable UART
    UART3_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART3_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART3_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART3_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0xC0)
    {
        GPIO_PORTC_AFSEL_R |= 0xC0; // enable alt funct on PC7-6
        GPIO_PORTC_DEN_R |= 0xC0; // configure PC7-6 as UART3
        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTC_AMSEL_R &= ~0xC0; // disable analog on PC7-6
    break;
case 4:
    //Port C
    SYSCTL_RCGC1_R |= 0x00000010; // activate UART4
    SYSCTL_RCGC2_R |= 0x00000004; // activate port C
    UART4_CTL_R &= ~0x00000001; // disable UART
    UART4_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART4_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART4_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART4_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0x30)
    {
        GPIO_PORTC_AFSEL_R |= 0x30; // enable alt funct on PC5-4
        GPIO_PORTC_DEN_R |= 0x30; // configure PC5-4 as UART1
        GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTC_AMSEL_R &= ~0x30; // disable analog on PC5-4
    break;
case 5 :
    //Port E
    SYSCTL_RCGC1_R |= 0x00000020; // activate UART5
    SYSCTL_RCGC2_R |= 0x00000010; // activate port E
    UART5_CTL_R &= ~0x00000001; // disable UART
    UART5_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART5_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART5_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART5_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0x30)
    {
       GPIO_PORTE_AFSEL_R |= 0x30; // enable alt funct on PE5-4
       GPIO_PORTE_DEN_R |= 0x30; // configure PE5-4 as UART5
       GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTE_AMSEL_R &= ~0x30; // disable analog on PE5-4
    break;
case 6 :
    //PORT D
    SYSCTL_RCGC1_R |= 0x00000040; // activate UART6
    SYSCTL_RCGC2_R |= 0x00000008; // activate port D
    UART2_CTL_R &= ~0x00000001; // disable UART
    UART6_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART6_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART6_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART6_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0x30)
    {
        GPIO_PORTD_AFSEL_R |= 0x30; // enable alt funct on PD5-4
        GPIO_PORTD_DEN_R |= 0x30; // configure PD5-4 as UART2
        GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTD_AMSEL_R &= ~0xC0; // disable analog on PD5-4
    break;
case 7:
    //Port E
    SYSCTL_RCGC1_R |= 0x00000020; // activate UART5
    SYSCTL_RCGC2_R |= 0x00000010; // activate port E
    UART5_CTL_R &= ~0x00000001; // disable UART
    UART5_IBRD_R = 43; // IBRD = int(80,000,000/(16*115,200)) =int(43.40278)
    UART5_FBRD_R = 26; // FBRD = round(0.40278 * 64) = 26
    UART5_LCRH_R = 0x00000070; // 8 bit, no parity bits, one stop, FIFOs
    UART5_CTL_R |= 0x00000301;// enable UART
    if(pinNumber == 0x30)
    {
        GPIO_PORTE_AFSEL_R |= 0x03; // enable alt funct on PE1-0
        GPIO_PORTE_DEN_R |= 0x03; // configure PE1-0 as UART7
        GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000;
    }
    GPIO_PORTE_AMSEL_R &= ~0x03; // disable analog on PE1-0
    break;

default :

}

}



