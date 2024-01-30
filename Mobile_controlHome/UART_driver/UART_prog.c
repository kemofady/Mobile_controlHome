 #include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"UART_interface.h"
#include"UART_reg.h"
#include"UART_confg.h"
#include"../GIE_driver/Gie_interface.h"

void (* UART_RecIntCallBack)(void) = '\0' ;
u8 *UART_DataPtr ;

void UART_init()
{

	/*DATA 8bit
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	/*parity mode disable
	CLR_BIT(UCSRC,4);
	CLR_BIT(UCSRC,5);
	/*stop 1 bit
	CLR_BIT(UCSRC,3);
 	 */
	/*We don't use set and clear bit because in MC has one address for two registers
	 *so bit7 should be always set  */
	UCSRC=0b10000110;
	/*enable */
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
	/*SPEED 9600*/
	UBRRL=51;

}

void UART_voidSend(u8 cpy_u8data)
{
	/* Data Register Empty flag*/
	while(GET_BIT(UCSRA,5)==0);

		UDR=cpy_u8data;

}

u8 UART_u8Recive(){
	/*Receive Complete flag*/
	while(GET_BIT(UCSRA,7)==0);

		return UDR;


}
void UART_voidSendString(u8 *str)
{
	u8 index;
	for (index=0 ; str[index]!='\0';index++) // '\0' It expresses to NULL the end of string
	{
		UART_voidSend(str[index]);
	}

}



void UART_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_u8Recive();
	/*will continue to receive until you send . */
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_u8Recive();
	}
	str[i] = '\0';
}

u8 i = 0; // to be seen in interrupt and function
u8 *global_u8userSend = 0; // to be seen in interrupt and function

void UART_voidSendStringAsyhc(u8 *str) {
  i = 0;
  global_u8userSend = str;

  /*Enable Tx INT*/
  GIE_voidEnable();

  /*Enable Data Register Empty INTI*/
  SET_BIT(UCSRB, 5);

  if (global_u8userSend[i] != '\0') {
    UDR = global_u8userSend[i];
    i++;
  }
}

u8 UART_u8RecAsynch (void (*func)(void), u8 *Cpy_DataPtr)
{
	u8 local_error = 1 ;
	if ((func != '\0') && (Cpy_DataPtr != '\0'))
	{
		UART_RecIntCallBack = func ;
		UART_DataPtr = Cpy_DataPtr;
	}
	else
	{
		local_error = 0;
	}

	/* Enable interrupt */
	SET_BIT(UCSRB ,7);
	return local_error ;
}

void __vector_13 (void) __attribute__((signal)) ;
void __vector_13 (void)
{
	if (UART_RecIntCallBack != '\0')
	{
		*UART_DataPtr = UDR ;
		UART_RecIntCallBack();
	}
}


/*Tx completed*/
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void){
  if (global_u8userSend[i] != '\0') {
    UDR = global_u8userSend[i];
    i++;
  }
}








