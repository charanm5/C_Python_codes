#include<LPC213x.h>
#define SI1 ((I2C1CONSET>>3)&1)

void I2C1_SlaveInit(void)
{
    PINSEL0 &= ~((3<<22) | (3<<28));
    PINSEL0 |=  ((3<<22) | (3<<28));

    I2C1ADR = (0x50<<1);

    I2C1CONSET = (1<<6);   // I2EN
    I2C1CONSET = (1<<2);   // AA
}

unsigned char I2C1_SlaveRead(void)
{
    while(I2C1STAT != 0x80);

    I2C1CONCLR = (1<<3);

    return I2C1DAT;
}

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

void uart0_tx_hex(unsigned char data)
{
    char hex[] = "0123456789ABCDEF";

    uart0_tx_char(hex[(data >> 4) & 0x0F]);
    uart0_tx_char(hex[data & 0x0F]);
}
