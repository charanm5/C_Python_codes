#include <LPC213x.h>

void SPI_Init_Slave(void)
{
    PINSEL0 &= ~(0xFF << 8);
    PINSEL0 |=  (0x55 << 8);

    S0SPCR = 0x00;   // Slave mode
	
	 //S0SPDR = 'B';
}

unsigned char SPI_Read(void)
{
    while(!(S0SPSR & (1<<7)));   // wait for SPIF

    return S0SPDR;               // read received data
}