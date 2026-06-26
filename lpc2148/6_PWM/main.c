#include <LPC213x.h>
#include "uart.h"

extern void PWM_Init(void);
extern void SetSpeed(unsigned int);

void delay_ms(unsigned int ms)
{
    unsigned int i,j;

    for(i=0;i<ms;i++)
    {
        for(j=0;j<6000;j++);
    }
}

int main()
{
    IODIR0 |= (1<<8) | (1<<9);

    IOSET0 = (1<<8);   // IN1 = 1
    IOCLR0 = (1<<9);   // IN2 = 0

    UART0_Init();

    PWM_Init();

    while(1)
    {
        SetSpeed(25);
        UART0_TxString("Speed = 25%\r\n");
        delay_ms(3000);

        SetSpeed(50);
        UART0_TxString("Speed = 50%\r\n");
        delay_ms(3000);

        SetSpeed(75);
        UART0_TxString("Speed = 75%\r\n");
        delay_ms(3000);

        SetSpeed(100);
        UART0_TxString("Speed = 100%\r\n");
        delay_ms(3000);
    }
}
