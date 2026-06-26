#include<LPC213x.h>
#include "uart.h"
#include "spi.h"
#include "delay.h"

int main()
{
	char rx;
	VPBDIV = 0x01;
	uart_init();
  SPI_Init_Master();

    while(1)
    {
        rx = SPI_Transfer('M');
			 
			  uart_send(&rx);
			uart_send("\r\n");
			
        delay_ms(100);
    }
}
