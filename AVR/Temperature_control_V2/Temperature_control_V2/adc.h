
#ifndef ADC_H_
#define ADC_H_


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void adc_init();

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16_t adc_readchannel();

#endif /* TEMP_SENSOR_EXAMPLE_ADC_H_ */
