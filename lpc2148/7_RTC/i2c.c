#include "rtc.h"
#include "uart.h"

#define SI ((I2CONSET >> 3) & 1)
unsigned char data;

void I2C0_Init(void)
{
    PINSEL0 |= 0x50;

    I2SCLH = 75;
    I2SCLL = 75;

    I2CONSET = (1 << 6);                 // Enable I2C0
}

void i2c_byte_write_frame(unsigned char sa, unsigned char mr, unsigned char data)
{
	I2CONSET = (1<< 5);
	I2CONCLR = (1 << 3);
	while(SI == 0);
	I2CONCLR = (1 << 5);
	if(I2STAT != 0x08)
	{
		UART0_TxString("wERR:wstart\r\n");
		goto exit;
	}
	
	//send sa+w check ack
	I2DAT = sa;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x20)
	{
		UART0_TxString("wERR:sa+w\r\n");
		goto exit;
	}
	
	//send mr and ack check
	I2DAT = mr;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x30)
	{
		UART0_TxString("wERR:mr+w\r\n");
		goto exit;
	}
	//send data and check
	I2DAT = data;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x30)
	{
		UART0_TxString("wERR:data\r\n");
		goto exit;
	}
	exit:
	I2CONSET = (1 << 4);
	I2CONCLR = (1 << 3);
}

unsigned char i2c_byte_read_frame(unsigned char sa, unsigned char mr)
{
	I2CONSET = (1<< 5);
	I2CONCLR = (1 << 3);
	while(SI == 0);
	I2CONCLR = (1 << 5);
	if(I2STAT != 0x08)
	{
		UART0_TxString("ERR:start\r\n");
		goto exit;
	}
	
	//send sa+w check ack
	I2DAT = sa;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x20)
	{
		UART0_TxString("ERR:sa+w\r\n");
		goto exit;
	}
	
	//send mr and ack check
	I2DAT = mr;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x30)
	{
		UART0_TxString("ERR:mr\r\n");
		goto exit;
	}
	
	//restart
	I2CONSET = (1<< 5);
	I2CONCLR = (1 << 3);
	while(SI == 0);
	I2CONCLR = (1 << 5);
	if(I2STAT != 0x10)
	{
		UART0_TxString("ERR:restart\r\n");
		goto exit;
	}
	
	//send sa+r check ack
	I2DAT = sa | 1;
	I2CONCLR = (1 << 3);
	while(SI == 0);
	if(I2STAT == 0x48)
	{
		UART0_TxString("ERR:sa+r\r\n");
		goto exit;
	}
	
	//data read and check
	I2CONCLR = (1 << 3);
	while(SI == 0);
	data = I2DAT;
	
	exit:
	I2CONSET = (1 << 4);
	I2CONCLR = (1 << 3);
	
	return data;
}
