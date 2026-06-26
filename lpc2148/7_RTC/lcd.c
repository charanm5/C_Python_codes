#include "lcd.h"
#include "delay.h"

void lcd_data(unsigned char data)
{
	unsigned int temp = 0;
	IOCLR1 = 0x00FE0000;
	temp = (data & 0xF0) << 16;
	IOSET1 = temp;
	IOSET1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
	
	IOCLR1 = 0x00FE0000;
	temp = (data & 0x0F) << 20;
	IOSET1 = temp;
	IOSET1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
}

void lcd_cmd(unsigned char cmd)
{
	unsigned int temp = 0;
	IOCLR1 = 0x00FE0000;
	temp = (cmd & 0xF0) << 16;
	IOSET1 = temp;
	IOCLR1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
	
	IOCLR1 = 0x00FE0000;
	temp = (cmd & 0x0F) << 20;
	IOSET1 = temp;
	IOCLR1 = 1 << 17;
	IOCLR1 = 1 << 18;
	IOSET1 = 1 << 19;
	delay_ms(2);
	IOCLR1 = 1 << 19;
}

void lcd_init(void)
{
	IODIR1 = 0x00FE0000; 
	IOCLR1 = 1 << 19;
	PINSEL2 = 0x00000000;
	lcd_cmd(0x02);
	lcd_cmd(0x28);  /* Initialize lcd */
	lcd_cmd(0x0E);   /* Display on cursor off */
	lcd_cmd(0x06);  /* Auto increment cursor */
	lcd_cmd(0x01);   /* Display clear */
	lcd_cmd(0x80);  /* First line first position */
}

void lcd_string(const char *str)
{
	while(*str != '\0')
	{
		lcd_data(*str);
		str++;
	}
}

void lcd_int(int num)
{
	char str[10];
	int i,r,j;

	for(i=0;i<4;i++,num/=10)
	{
		r = num%10;
		str[i] = r + 48;
	}
	str[i]='\0';

	for(j=i-1;j>=0;j--)
		lcd_data(str[j]);

}
