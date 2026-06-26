#include <LPC213x.h>
#include "spi.h"
#include "uart.h"

extern char arr[13];
extern unsigned char flag;

unsigned char sec,min,hour;
unsigned int addr = 0x00;

void delay_ms(unsigned int ms)
{
	T0PC = 0;
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC < ms);
	T0TCR = 0X03;
	T0TCR = 0X00;
}

void convert_time(char *time)
{
	hour = ((time[0] - 48) * 10) + time[1] - 48;
	min = ((time[2] - 48) * 10) + time[3] - 48;
	sec = ((time[4] - 48) * 10) + time[5] - 48;
}

void store_flash(void)
{
	if((addr + 3) < 0x7FFF)
	{
		EEPROM_WriteByte(addr, hour);
		addr++;
		EEPROM_WriteByte(addr, min);
		addr++;
		EEPROM_WriteByte(addr, sec);
		addr++;
	}
	else
	{
		uart0_tx_string("Flash is Full\r\n");
	}
}

void read_flash(void)
{
	unsigned char read = 0;
	uart0_tx_string("Stored Value:");
	read = EEPROM_ReadByte(addr - 3);
	uart0_tx_integer(read);
	read = EEPROM_ReadByte(addr - 2);
	uart0_tx_integer(read);
	read = EEPROM_ReadByte(addr - 1);
	uart0_tx_integer(read);
	uart0_tx_string("\r\n");
}

unsigned int bcd_to_dec(unsigned char data)
{
    return ((data >> 4) * 10) + (data & 0x0F);
}

int main()
{
	unsigned char last_data = 0xFF;
	SPI0_Init();
  uart0_init();
	I2C1_SlaveInit();
	
	uart0_tx_string("Waiting for data receive\r\n");
	
	while(1)
	{

    if(I2C1STAT == 0x60)
    {
        I2C1CONCLR = (1<<3);
    }

    if(I2C1STAT == 0x80)
    {
			if(last_data == 0x0)
			{
				hour = I2C1DAT;
				hour = bcd_to_dec(hour);
			}
			else if(last_data == 0x1)
			{
				min = I2C1DAT;
				min = bcd_to_dec(min);
			}
			else if(last_data == 0x2)
			{
				sec = I2C1DAT;
				sec = bcd_to_dec(sec);
				store_flash();
				read_flash();
			}
			last_data = I2C1DAT;
      I2C1CONCLR = (1<<3);
    }

    if(I2C1STAT == 0x88)
    {
        uart0_tx_string("NACK\r\n");
        I2C1CONCLR = (1<<3);
    }
	}
}
