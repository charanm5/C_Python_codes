#include <LPC213x.h>

void uart0_init(void)
{
    PINSEL0 |= 0x00000005;

    U0LCR = 0x83;

    U0DLL = 97;
    U0DLM = 0;

    U0LCR = 0x03;
}

void uart0_tx_char(char ch)
{
    while(!(U0LSR & 0x20));   // Wait for THR empty
    U0THR = ch;
}

void uart0_tx_string(char *ptr)
{
	while(*ptr != '\0')
	{
		while(!(U0LSR & 0x20));
		U0THR = *ptr;
		ptr++;
	}
}

void uart0_tx_integer(unsigned int num)
{
    char buf[10];
    int i = 0;

    if(num == 0)
    {
        uart0_tx_char('0');
        return;
    }

    while(num > 0)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while(i > 0)
    {
        uart0_tx_char(buf[--i]);
    }
}
