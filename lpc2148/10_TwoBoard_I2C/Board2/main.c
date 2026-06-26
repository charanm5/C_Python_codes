#include <LPC213x.h>
#include "uart.h"
#include "i2c.h"
#include "ds1307.h"

extern unsigned char sec,min,hour;

void delay_ms(unsigned int ms)
{
	T0PC = 0;
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC < ms);
	T0TCR = 0X03;
	T0TCR = 0X00;
}
#define SLAVE_ADDR 0xA0
int main()
{
	I2C0_Init();
	I2C1_Init();
	uart0_init();
	
	DS1307_SetTime();
	
	uart0_tx_string("Started Master\r\n");
	
	while(1)
	{
		DS1307_ReadTime();
		
		I2C1_MasterWrite(SLAVE_ADDR, 0x0, hour);
		
		delay_ms(100);

		I2C1_MasterWrite(SLAVE_ADDR, 0x1, min);
		
		delay_ms(100);

		I2C1_MasterWrite(SLAVE_ADDR, 0x2, sec);
		
		delay_ms(2000);
	}
	
}
