#include<LPC213x.h>
#include "uart.h"

int main()
{
  char data;
	VPBDIV = 0x01;
	uart0_init();
	uart1_init();
	uart0_send("Hello");
	while(1)
	{
			if(U0LSR & 0x01) {
			data = uart0_recv();
			uart1_send(&data);
		}
	}
}
