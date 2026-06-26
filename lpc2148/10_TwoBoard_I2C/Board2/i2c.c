#include "i2c.h"
#include "uart.h"
#include <stdio.h>

char buf[20];

#define SI ((I2C0CONSET >> 3) & 1)
unsigned char data;

void I2C0_Init(void)
{
    PINSEL0 |= 0x50;

    I2C0SCLH = 75;
    I2C0SCLL = 75;

    I2C0CONSET = (1 << 6);                 // Enable I2C0
}

#define SI1 ((I2C1CONSET>>3)&1)

void I2C1_Init(void)
{
    PINSEL0 &= ~((3<<22) | (3<<28));
    PINSEL0 |=  ((3<<22) | (3<<28));

    I2C1SCLH = 75;
    I2C1SCLL = 75;

    I2C1CONSET = (1<<6);
}

void I2C1_MasterWrite(unsigned char sa, unsigned char mr, unsigned char data)
{
	I2C1CONSET = (1<< 5);
	I2C1CONCLR = (1 << 3);
	uart0_tx_string("START\r\n");
	while(SI1 == 0);
	I2C1CONCLR = (1 << 5);
	if(I2C1STAT != 0x08)
	{
		sprintf(buf,"STAT=%02X\r\n",I2C1STAT);
		uart0_tx_string(buf);
		uart0_tx_string("1wERR:wstart\r\n");
		goto exit;
	}
	
	//send sa+w check ack
	I2C1DAT = sa;
	I2C1CONCLR = (1 << 3);
	uart0_tx_string("SA+W\r\n");
	while(SI1 == 0);
	if(I2C1STAT == 0x20)
	{
		sprintf(buf,"STAT=%02X\r\n",I2C1STAT);
		uart0_tx_string(buf);
		uart0_tx_string("1wERR:sa+w\r\n");
		goto exit;
	}
	
	//send mr and ack check
	I2C1DAT = mr;
	I2C1CONCLR = (1 << 3);
	uart0_tx_string("MR\r\n");
	while(SI1 == 0);
	if(I2C1STAT == 0x30)
	{
		uart0_tx_string("1wERR:mr+w\r\n");
		goto exit;
	}
	//send data and check
	I2C1DAT = data;
	I2C1CONCLR = (1 << 3);
	uart0_tx_string("DATA\r\n");
	while(SI1 == 0);
	if(I2C1STAT == 0x30)
	{
		uart0_tx_string("1wERR:data\r\n");
		goto exit;
	}
	exit:
	I2C1CONSET = (1 << 4);
	I2C1CONCLR = (1 << 3);
}

void i2c_byte_write_frame(unsigned char sa, unsigned char mr, unsigned char data)
{
	I2C0CONSET = (1<< 5);
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	I2C0CONCLR = (1 << 5);
	if(I2C0STAT != 0x08)
	{
		uart0_tx_string("wERR:wstart\r\n");
		goto exit;
	}
	
	//send sa+w check ack
	I2C0DAT = sa;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x20)
	{
		uart0_tx_string("wERR:sa+w\r\n");
		goto exit;
	}
	
	//send mr and ack check
	I2C0DAT = mr;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x30)
	{
		uart0_tx_string("wERR:mr+w\r\n");
		goto exit;
	}
	//send data and check
	I2C0DAT = data;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x30)
	{
		uart0_tx_string("wERR:data\r\n");
		goto exit;
	}
	exit:
	I2C0CONSET = (1 << 4);
	I2C0CONCLR = (1 << 3);
}

unsigned char i2c_byte_read_frame(unsigned char sa, unsigned char mr)
{
	I2C0CONSET = (1<< 5);
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	I2C0CONCLR = (1 << 5);
	if(I2C0STAT != 0x08)
	{
		uart0_tx_string("ERR:start\r\n");
		goto exit;
	}
	
	//send sa+w check ack
	I2C0DAT = sa;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x20)
	{
		uart0_tx_string("ERR:sa+w\r\n");
		goto exit;
	}
	
	//send mr and ack check
	I2C0DAT = mr;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x30)
	{
		uart0_tx_string("ERR:mr\r\n");
		goto exit;
	}
	
	//restart
	I2C0CONSET = (1<< 5);
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	I2C0CONCLR = (1 << 5);
	if(I2C0STAT != 0x10)
	{
		uart0_tx_string("ERR:restart\r\n");
		goto exit;
	}
	
	//send sa+r check ack
	I2C0DAT = sa | 1;
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	if(I2C0STAT == 0x48)
	{
		uart0_tx_string("ERR:sa+r\r\n");
		goto exit;
	}
	
	//data read and check
	I2C0CONCLR = (1 << 3);
	while(SI == 0);
	data = I2C0DAT;
	
	exit:
	I2C0CONSET = (1 << 4);
	I2C0CONCLR = (1 << 3);
	
	return data;
}
