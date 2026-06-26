#include<LPC213x.h>
#include<stdint.h>

/*UART1 pins*/
//P0.0 -> Txd
//P0.1 -> Rxd

uint8_t num = 0;

void gpio_init()
{
	IODIR0 |= (1 << 2);
}

void led_on()
{
	IOSET0 = (1 << 2);  
}

void led_off()
{
	IOCLR0 = (1 << 2);  
}

void uart_init()
{
		PINSEL0 |= 0x00000005;
	
	U0LCR = 0x83; // 8N1, enable access to divisor latches
	
	U0DLL = 0x86;
	U0DLM = 0x01;  // 9600 baud rate , PCLK = 60MHZ
	
	U0LCR = 0x03; // disable access to divisor latches
}

void uart_send(char *str)
{
	while(*str)
	{
		while(!(U0LSR & (1<<5)));
		U0THR = *str;
		str++;
	}
}

uint8_t uart_recv()
{
	while(!(U0LSR & 0x01));
	return U0RBR;

}

int main()
{
	uint8_t choice;
	VPBDIV = 0x01;
	gpio_init();
	uart_init();
	while(1)
	{
		uart_send("Select option:\r\n");
		uart_send("1. Turn ON LED\r\n");
		uart_send("2. Turn OFF LED\r\n");
		choice = uart_recv();
		switch(choice)
		{
			case '1':
				uart_send("ON\r\n");
				led_on();
				break;
			case '2':
				uart_send("OFF\r\n");
				led_off();
				break;
		}
	}
}
