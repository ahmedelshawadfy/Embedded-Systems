// #ifndef F_CPU
// #define F_CPU 16000000UL // 16 MHz clock speed
// #endif

#include "lcd.h"
#include "adc.h"
#include "timer.h"
#include "pwm.h"

uint8_t temperature = 0;
uint8_t ref = 18;//adc reference voltage
uint8_t error = 0;
float lasterror = 0;
float errorsum = 0;
uint8_t kp = 5;
uint8_t ki = 1;
uint8_t kd = 1;
float T = 0.1;
volatile float u = 0;
volatile char buffer[10] ;

int main(void)
{
	DDRD |= 0xFF;
	uint8_t data[15] = {"Temperature : "};
	adc_init();//select PC0 as analog input
	timer1_init();//set timer to take sample every 1s
	pwm_init();
	lcd_display(data);// display temperature

	while(1)
	{
		/* u = (kp*error + ki*errorsum + kd*(error-lasterror/T)*/
		temperature = (temperature*150*5)/(1023*1.5);
		error = ref - temperature;
		errorsum = errorsum + error;
		u=(kp*error + ki*errorsum + kd*(error - lasterror));
		lasterror = error;
		pwm_output((uint8_t)u/4);
		_delay_ms(1000);		
		

 		Lcd4_Set_Cursor(2,0);
 		itoa(temperature, buffer, 10);
 		Lcd4_Write_String(buffer);
 		

	}
}

ISR(TIMER1_COMPA_vect)
{
	temperature = adc_read(0);//read adc data register after 1s
	
}