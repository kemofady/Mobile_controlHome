

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define ADMUX	(*((volatile u8 *)0x27))
#define ADCSRA	(*((volatile u8 *)0x26))
#define ADCH	(*((volatile u8 *)0x25))
#define ADCL	(*((volatile u8 *)0x24))

#define SREG    (*((volatile u8 *)0x5F))

#endif
