#include <lpc213x.h>
#include <stdint.h>

/* LCD pins on Port 0 */
#define D4 (1<<16)   // P0.16
#define D5 (1<<17)   // P0.17
#define D6 (1<<18)   // P0.18
#define D7 (1<<19)   // P0.19
#define RS (1<<20)   // P0.20
#define EN (1<<21)   // P0.21

void delay_ms(unsigned int ms)
{
    unsigned int i, j;

    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 6000; j++);
    }
}

/* Generate Enable Pulse */
void lcd_enable(void)
{
    IO0SET = EN;
    delay_ms(2);

    IO0CLR = EN;
    delay_ms(2);
}

/* Send 4-bit nibble */
void lcd_send_nibble(unsigned char nibble)
{
    IO0CLR = D4 | D5 | D6 | D7;

    if(nibble & 0x01) IO0SET = D4;
    if(nibble & 0x02) IO0SET = D5;
    if(nibble & 0x04) IO0SET = D6;
    if(nibble & 0x08) IO0SET = D7;

    lcd_enable();
}

/* Send Command */
void lcd_cmd(unsigned char cmd)
{
    IO0CLR = RS;

    lcd_send_nibble(cmd >> 4);
    lcd_send_nibble(cmd & 0x0F);

    delay_ms(5);
}

/* Send Data */
void lcd_data(unsigned char data)
{
    IO0SET = RS;

    lcd_send_nibble(data >> 4);
    lcd_send_nibble(data & 0x0F);

    delay_ms(5);
}

/* LCD Initialization */
void lcd_init(void)
{
    PINSEL0 = 0x00000000;
    PINSEL1 = 0x00000000;

    IODIR0 |= (D4 | D5 | D6 | D7 | RS | EN);

    delay_ms(50);

    lcd_send_nibble(0x03);
    delay_ms(20);

    lcd_send_nibble(0x03);
    delay_ms(20);

    lcd_send_nibble(0x03);
    delay_ms(20);

    lcd_send_nibble(0x02);
    delay_ms(20);

    lcd_cmd(0x28);     // 4-bit, 2-line
    lcd_cmd(0x0C);     // Display ON
    lcd_cmd(0x06);     // Entry mode
    lcd_cmd(0x01);     // Clear display

    delay_ms(20);
}

/* Print String */
void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

void lcd_int(unsigned int num)
{
    char buf[10];
    int i = 0;

    if(num == 0)
    {
        lcd_data('0');
        return;
    }

    while(num > 0)
    {
        buf[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    while(i > 0)
    {
        i--;
        lcd_data(buf[i]);
    }
}

void adc_init()
{
	PINSEL1 |= (1 << 22);
	AD0CR |= (1<<0) | (3 << 8) | (1<<21);   // channel-0, clkdiv, pdn disable
}



int main(void)
{
	uint16_t result;
    lcd_init();
	  adc_init();

    lcd_cmd(0x80);
    lcd_string("TEMP = ");

    lcd_cmd(0xC0);

    while(1)
    {
			AD0CR &= ~(7 << 24);
			AD0CR |=  (1 << 24);
			while(!(AD0GDR & ((unsigned int)1<<31)));
			result = ((AD0GDR >> 6)  & 0x3FF);
			lcd_cmd(0xC0);
			lcd_int(result);
    }
}
