#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void Adc_voidInit(void);
u8 ADC_u8readvalueAsynch(u8 cpy_u8channel,u8 *adc_read,void(*func)(void));

u8 ADC_u8readvalue(u8 cpy_u8channel);


#endif
