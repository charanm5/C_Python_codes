#include "uart.h"

void UART0_Init(void)
{
    PINSEL0 |= 0x00000005;

    U0LCR = 0x83;      // 8-bit, enable divisor latch

    U0DLL = 97;        // 9600 baud for 15MHz PCLK
    U0DLM = 0;

    U0LCR = 0x03;      // Disable divisor latch
}

void UART0_TxChar(char ch)
{
    while(!(U0LSR & 0x20));

    U0THR = ch;
}

void UART0_TxString(char *str)
{
    while(*str)
    {
        UART0_TxChar(*str++);
    }
}

char UART0_RxChar(void)
{
    while(!(U0LSR & 0x01));

    return U0RBR;
}
