#include<LPC213x.h>
#include<stdint.h>
#include "uart.h"

int main()
{
	char data;
	VPBDIV = 0x01;
	uart_init();
	while(1)
	{
		if(U0LSR & 0x01) {
			data = uart_recv();
			data++;
			uart_send(&data);
		}
	}
}
