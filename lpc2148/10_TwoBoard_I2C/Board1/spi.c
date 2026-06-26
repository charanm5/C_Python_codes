#include <LPC213x.h>

#define WREN  0x06
#define WRITE 0x02
#define READ  0x03
#define RDSR  0x05

extern void delay_ms(unsigned int ms);

#define CS_LOW()  IOCLR0 = (1<<7)
#define CS_HIGH() IOSET0 = (1<<7)

void SPI0_Init(void)
{
    PINSEL0 |= 0x00001500;

    IODIR0 |= (1<<7);
    CS_HIGH();

    S0SPCR = (1<<5) | (1<<3);
    S0SPCCR = 8; 
}

unsigned char SPI0_TxRx(unsigned char data)
{
    S0SPDR = data;

    while(!(S0SPSR & (1<<7)));

    return S0SPDR;
}

void EEPROM_WriteEnable(void)
{
    CS_LOW();

    SPI0_TxRx(WREN);

    CS_HIGH();
}

void EEPROM_WriteByte(unsigned int addr, unsigned char data)
{
    EEPROM_WriteEnable();

    CS_LOW();

    SPI0_TxRx(WRITE);

    SPI0_TxRx((addr >> 8) & 0xFF);
    SPI0_TxRx(addr & 0xFF);

    SPI0_TxRx(data);

    CS_HIGH();

    delay_ms(10);     // EEPROM write cycle
}

unsigned char EEPROM_ReadByte(unsigned int addr)
{
    unsigned char data;

    CS_LOW();

    SPI0_TxRx(READ);

    SPI0_TxRx((addr >> 8) & 0xFF);
    SPI0_TxRx(addr & 0xFF);

    data = SPI0_TxRx(0xFF);

    CS_HIGH();

    return data;
}
