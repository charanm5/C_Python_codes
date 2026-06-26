#include <LPC213x.h>
#include "uart.h"

//void SPI_Init_Master(void)
//{
//    // Select SPI function for P0.4-P0.7
//    PINSEL0 &= ~(0xFF << 8);
//    PINSEL0 |=  (0x55 << 8);   //0x00005500

//    // Master mode, CPOL=0, CPHA=0
//    S0SPCR = (1<<5);     // MSTR=1

//    // SPI clock = PCLK/8
//    S0SPCCR = 8;
//}

void SPI_Init_Master(void)
{
    // SPI pins
    PINSEL0 &= ~(0xFF << 8);
    PINSEL0 |=  (0x55 << 8);

    // Disable SSEL as GPIO (VERY IMPORTANT FIX)
    PINSEL0 &= ~(3 << 14);   // P0.7 GPIO
    IO0DIR |= (1 << 7);
    IO0SET |= (1 << 7);

    // Master mode
    S0SPCR = (1<<5);

    // SPI speed
    S0SPCCR = 8;
}

char SPI_Transfer(char data)
{
			IO0CLR = (1 << 7);
    S0SPDR = data;
    while(!(S0SPSR & (1<<7)));
	  data = S0SPDR;
			IO0SET = (1 << 7);
    return data;
}

