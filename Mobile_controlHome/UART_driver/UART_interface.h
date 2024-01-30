#ifndef	UARTINTERFACE_H_
#define	UART_INTERFACE_H_

void UART_init();
void UART_voidSend(u8 cpy_u8data);
u8 UART_u8Recive();


void UART_voidSendString(u8 *str);
void UART_ReceiveString(u8 *str);
u8 UART_u8RecAsynch (void (*func)(void), u8 *Cpy_DataPtr);
void UART_voidSendStringAsyhc(u8 *str);
#endif
