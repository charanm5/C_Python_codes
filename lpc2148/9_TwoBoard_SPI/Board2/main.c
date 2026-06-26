#include <LPC213x.h>
#include "spi.h"
#include "uart.h"

int main()
{
    char data;

    VPBDIV = 0x01;
	SPI_Init_Slave();
	  uart_init();

	while(1) {

       data = SPI_Read();
		S0SPDR = 'S';
        uart_send_char(data);
		uart_send("\r\n");
	}

}
