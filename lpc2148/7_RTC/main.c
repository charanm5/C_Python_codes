#include "rtc.h"
#include "ds1307.h"
#include "lcd.h"
#include "delay.h"
#include "uart.h"

void int_to_str(int num,char *str);

extern unsigned char sec,min,hour;

char buf[10];

int main()
{
    lcd_init();

    I2C0_Init();
	
		UART0_Init();

    //Run once, then comment it
    DS1307_SetTime();
	

    while(1)
    {
			
        DS1307_ReadTime();

        lcd_cmd(0x80);
				lcd_data((hour /0x10) + 48);
			  lcd_data((hour % 0x10) + 48);
			  UART0_TxChar((hour / 0x10) + 48);
			  UART0_TxChar((hour % 0x10) + 48);
			

        lcd_data(':');

				lcd_data((min /0x10) + 48);
			  lcd_data((min % 0x10) + 48);
			  UART0_TxChar((min / 0x10) + 48);
			  UART0_TxChar((min % 0x10) + 48);

        lcd_data(':');

				lcd_data((sec /0x10) + 48);
			  lcd_data((sec % 0x10) + 48);
			  UART0_TxChar((sec / 0x10) + 48);
			  UART0_TxChar((sec % 0x10) + 48);

        delay_ms(200);
    }
}

void int_to_str(int num,char *str)
{
    int i=0,j;
    char temp;

    if(num==0)
    {
        str[0]='0';
        str[1]='\0';
        return;
    }

    while(num>0)
    {
        str[i++]=num%10+'0';
        num/=10;
    }

    str[i]='\0';

    for(j=0;j<i/2;j++)
    {
        temp=str[j];
        str[j]=str[i-j-1];
        str[i-j-1]=temp;
    }
}
