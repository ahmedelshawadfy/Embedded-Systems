
/**
* @file UART.h
*/



#ifndef UART_H_
#define UART_H_

#include "registers_config.h"
#include "std_types.h"

/**
* @brief UART initialization : \n
* Tiva c has 8 channels for uart so the variable uart_num is the channel number
*
*/
/**
* @code 
*     if(uart_num == 0)
{
	volatile uint32 delay;
	/* Assumes a 16 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART0_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTA_AFSEL_R |= 0x03 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | (0x00000011) ;



	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART0_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART0_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART0_LCRH_R |= 0x00000060;

	/* enable UART */
	UART0_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTA_DEN_R |= 0X03;

	/* disable analog on pins */
	GPIO_PORTA_AMSEL_R &= ~(0x03);
}

else if(uart_num == 1)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART1_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alt funct */
	GPIO_PORTB_AFSEL_R |= 0x03 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTB_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | (0x00000011) ;



	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART1_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART1_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART1_LCRH_R |= 0x00000060;

	/* enable UART */
	UART1_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTB_DEN_R |= 0X03;

	/* disable analog on pins */
	GPIO_PORTB_AMSEL_R &= ~(0x03);

}
else if(uart_num == 2)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART2_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTD_AFSEL_R |= 0xC0 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTD_PCTL_R = (GPIO_PORTA_PCTL_R & 0x00FFFFFF) | (0x11000000) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART2_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART2_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART2_LCRH_R |= 0x00000060;

	/* enable UART */
	UART2_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTD_DEN_R |= 0XC0;

	/* disable analog on pins */
	GPIO_PORTD_AMSEL_R &= ~(0xC0);

}

else if(uart_num == 3)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART3_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTC_AFSEL_R |= 0xC0 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTC_PCTL_R = (GPIO_PORTA_PCTL_R & 0x00FFFFFF) | (0x11000000) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART3_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART3_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART3_LCRH_R |= 0x00000060;

	/* enable UART */
	UART3_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTC_DEN_R |= 0XC0;

	/* disable analog on pins */
	GPIO_PORTC_AMSEL_R &= ~(0xC0);

}

else if(uart_num == 4)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;


	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART4_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTC_AFSEL_R |= 0x30 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTC_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFF00FFFF) | (0x00110000) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART4_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART4_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART4_LCRH_R |= 0x00000060;

	/* enable UART */
	UART4_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTC_DEN_R |= 0X30;

	/* disable analog on pins */
	GPIO_PORTC_AMSEL_R &= ~(0x30);

}

else if(uart_num == 5)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;


	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART5_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTE_AFSEL_R |= 0x03 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTE_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | (0x00000011) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART5_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART5_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART5_LCRH_R |= 0x00000060;

	/* enable UART */
	UART5_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTE_DEN_R |= 0X03;

	/* disable analog on pins */
	GPIO_PORTE_AMSEL_R &= ~(0x03);

}

else if(uart_num == 6)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART6_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTD_AFSEL_R |= 0x30 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTD_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFF00FFFF) | (0x00110000) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART6_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART6_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART6_LCRH_R |= 0x00000060;

	/* enable UART */
	UART6_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTD_DEN_R |= 0X30;

	/* disable analog on pins */
	GPIO_PORTD_AMSEL_R &= ~(0x30);

}

else if(uart_num == 7)
{
	volatile uint32 delay;
	/* Assumes a 80 MHz bus clock, creates 9600 baud rate */

	/* Enable and provide a clock to UART module in Run mode */
	SYSCTL_RCGC1_R |=(1<<uart_num);

	/* allow time to finish activating */
	delay = SYSCTL_RCGC2_R;

	/* SYSCTL_RCGCGPIO_R enabled by function ports_clock_EN() for all ports */

	/*  disable UART */
	UART7_CTL_R &= ~(0x00000001);

	/* Set the GPIO AFSEL bits to enable alternative function */
	GPIO_PORTE_AFSEL_R |= 0x03 ;

	/* Configure the PMCn fields in the GPIOPCTL register to assign the UART signals */
	GPIO_PORTE_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | (0x00000011) ;

	/* IBRD = int(16,000,000/(16*9600)) = int(104.1666667) */
	UART7_IBRD_R = 104;

	/* UARTFBRD[DIVFRAC] = integer(0.166666667 * 64 + 0.5) = int(11.1666) = 11 */
	UART7_FBRD_R = 11;

	/*  8 bit, no parity bits, one stop, disable FIFOs */
	UART7_LCRH_R |= 0x00000060;

	/* enable UART */
	UART7_CTL_R |= 0x00000301;

	/* The digital functions for the corresponding pin are enabled */
	GPIO_PORTE_DEN_R |= 0X03;

	/* disable analog on pins */
	GPIO_PORTE_AMSEL_R &= ~(0x03);

}


}

* @endcode
*/
void uart_init(uint8 uart_num);
/**
* @brief send a byte to other device : \n
* variable uart_num for channel number specified before \n
* variable data for the desired data to be sent \n
* 
*/
/**
* @code
* {
	/* void function to send byte takes data and uart number  */
	if(uart_num == 0)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART0_FR_R & 0x0020) != 0){}
		UART0_DR_R = data ;

	}

	else if(uart_num == 1)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART1_FR_R & 0x0020) != 0){}
		UART1_DR_R = data ;
	}

	else if(uart_num == 2)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART2_FR_R & 0x0020) != 0);
		UART2_DR_R = data ;
	}

	else if(uart_num == 3)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART3_FR_R & 0x0020) != 0);
		UART3_DR_R = data ;

	}

	else if(uart_num == 4)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART4_FR_R & 0x0020) != 0);
		UART4_DR_R = data ;
	}

	else if(uart_num == 5)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART5_FR_R & 0x0020) != 0);
		UART5_DR_R = data ;
	}

	else if(uart_num == 6)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART6_FR_R & 0x0020) != 0);
		UART6_DR_R = data ;
	}

	else if(uart_num == 7)
	{
		/* Wait for buffer to be not full ,TXFF to be clear */
		while((UART7_FR_R & 0x0020) != 0);
		UART7_DR_R = data ;
	}
}

* @endcode
*/
void uart_send_byte(uint8 uart_num,uint8 data);
/**
* @brief receive a byte from other device : \n
* variable uart_num is for the channel number specified before
*
*/
/**
*@code
*{
    /* function to recieve byte takes one input (uart number)
     * return recieved byte  */

    if(uart_num == 0)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART0_FR_R & 0x0010) != 0);
        return ((uint8)(UART0_DR_R & 0xFF)) ;

    }

    else if(uart_num == 1)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART1_FR_R & 0x0010) != 0){}
        return ((uint8)(UART1_DR_R & 0xFF)) ;
    }

    else if(uart_num == 2)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART2_FR_R & 0x0010) != 0);
        return ((uint8)(UART2_DR_R & 0xFF)) ;
    }

    else if(uart_num == 3)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART3_FR_R & 0x0010) != 0);
        return ((uint8)(UART3_DR_R & 0xFF)) ;
    }

    else if(uart_num == 4)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART4_FR_R & 0x0010) != 0);
        return ((uint8)(UART4_DR_R & 0xFF)) ;
    }

    else if(uart_num == 5)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART5_FR_R & 0x0010) != 0);
        return ((uint8)(UART5_DR_R & 0xFF)) ;
    }

    else if(uart_num == 6)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART6_FR_R & 0x0010) != 0);
        return ((uint8)(UART6_DR_R & 0xFF)) ;
    }

    else if(uart_num == 7)
    {
        /* Wait for new input ,wait until RXFE is 0 */
        while((UART7_FR_R & 0x0010) != 0);
        return ((uint8)(UART7_DR_R & 0xFF)) ;
    }


}
*@endcode
*/
uint8 uart_recieve_byte(uint8 uart_num);


#endif /* UART_H_ */
