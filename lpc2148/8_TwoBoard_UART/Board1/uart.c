#include<LPC213x.h>
#include<stdint.h>

/*UART1 pins*/
//P0.0 -> Txd
//P0.1 -> Rxd

void uart0_init()
{
		PINSEL0 |= 0x00000005;
	
	U0LCR = 0x83; // 8N1, enable access to divisor latches
	
	U0DLL = 0x86;
	U0DLM = 0x01;  // 9600 baud rate , PCLK = 60MHZ
	
	U0LCR = 0x03; // disable access to divisor latches
}

void uart1_init()
{
		PINSEL0 |= 0x00050000;
	
	U1LCR = 0x83; // 8N1, enable access to divisor latches
	
	U1DLL = 0x86;
	U1DLM = 0x01;  // 9600 baud rate , PCLK = 60MHZ
	
	U1LCR = 0x03; // disable access to divisor latches
}

void uart0_send(char *str)
{
	while(*str)
	{
		while(!(U0LSR & (1<<5)));
		U0THR = *str;
		str++;
	}
}

void uart1_send(char *str)
{
	while(*str)
	{
		while(!(U1LSR & (1<<5)));
		U1THR = *str;
		str++;
	}
}

uint8_t uart0_recv()
{
	while(!(U0LSR & 0x01));
	return U0RBR;

}

uint8_t uart1_recv()
{
	while(!(U1LSR & 0x01));
	return U1RBR;

}
