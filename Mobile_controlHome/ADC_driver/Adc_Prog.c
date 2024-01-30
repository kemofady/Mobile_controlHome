

#include"STD_TYPES.h"
#include"Bit_Math.h"


#include"Adc_Reg.h"
#include"Adc_Interface.h"
#include"Adc_Cfg .h"
#include"Adc_Private.h"

void(*callback)(void);
u8 *adcvalue;


void Adc_voidInit(){
	//SELECT VCC as max volt
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	//TO work with 8bit mode
	SET_BIT(ADMUX,5);

	SET_BIT(ADCSRA,7); //ENABLE ADC
	CLR_BIT(ADCSRA,5); //Disable auto trigger
	CLR_BIT(ADCSRA,3);  //disable interrupt

	/* select prescaller(freq) */
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);


}

u8 ADC_u8readvalueAsynch(u8 cpy_u8channel,u8 *adc_read,void(*func)(void))
{

	/*select channel */
	ADMUX &=0b11100000;  //clear frist 5 bits
	ADMUX |=cpy_u8channel;

	//start channel
	SET_BIT(ADCSRA,6);

	adcvalue=adc_read;
	callback=func;

	SET_BIT(SREG,7);
	SET_BIT(ADCSRA,3);

	return adcvalue;

}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	*adcvalue=ADCH;
	callback();

}



u8 ADC_u8readvalue(u8 cpy_u8channel)
{
	/*select channel */
	ADMUX &=0b11100000;  //clear frist 5 bits
	ADMUX |=cpy_u8channel;

	//start channel
	SET_BIT(ADCSRA,6);

	/* wait till finish */
	while(GET_BIT(ADCSRA,4)==0){}

	/*  STOP ,CLEAR FLAG*/
	CLR_BIT(ADCSRA,6);
	SET_BIT(ADCSRA,4);

	return ADCH;
}
