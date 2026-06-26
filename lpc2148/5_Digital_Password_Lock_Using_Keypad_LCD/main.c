#include <lpc213x.h>
#include <string.h>

/* Control pins */
#define RS (1<<12)
#define EN (1<<14)

/* Data pins (4-bit mode only) */
#define D4 (1<<20)
#define D5 (1<<21)
#define D6 (1<<22)
#define D7 (1<<23)

char password[] = "1234";
char entered[5];

char keymap[4][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

void delay(unsigned int ms)
{
    volatile unsigned int i,j;

    for(i=0;i<ms;i++)
        for(j=0;j<6000;j++);
}

char keypad_getkey(void)
{
    int row,col;

    unsigned long rows[4]=
    {
        (1<<23),
        (1<<24),
        (1<<25),
        (1<<26)
    };

    unsigned long cols[3]=
    {
        (1<<27),
        (1<<28),
        (1<<29)
    };

    IO1DIR |= 0x0F800000;      // P1.23-P1.26 output
    IO1DIR &= ~(0x38000000);   // P1.27-P1.29 input

    while(1)
    {
        for(row=0;row<4;row++)
        {
            IO1SET = 0x0F800000;

            IO1CLR = rows[row];

            delay(2);

            for(col=0;col<3;col++)
            {
                if(!(IO1PIN & cols[col]))
                {
                    delay(20);

                    if(!(IO1PIN & cols[col]))
                    {
                        while(!(IO1PIN & cols[col]));

                        return keymap[row][col];
                    }
                }
            }
        }
    }
}

/* send upper nibble to LCD */
void lcd_send_nibble(unsigned char nibble)
{
    IO0CLR = (D4|D5|D6|D7);

    if(nibble & 0x01) IO0SET = D4;
    if(nibble & 0x02) IO0SET = D5;
    if(nibble & 0x04) IO0SET = D6;
    if(nibble & 0x08) IO0SET = D7;

    IO0SET = EN;
    delay(2);
    IO0CLR = EN;
    delay(2);
}

/* send byte (cmd/data) */
void lcd_send_byte(unsigned char val, unsigned char isData)
{
    if(isData)
        IO0SET = RS;
    else
        IO0CLR = RS;

    /* send upper nibble */
    lcd_send_nibble(val >> 4);

    /* send lower nibble */
    lcd_send_nibble(val & 0x0F);
}

void lcd_cmd(unsigned char cmd)
{
    lcd_send_byte(cmd, 0);
    delay(5);
}

void lcd_data(unsigned char data)
{
    lcd_send_byte(data, 1);
    delay(5);
}

void lcd_string(char *str)
{
    while(*str)
        lcd_data(*str++);
}

void lcd_init(void)
{
    PINSEL0 = 0;
    PINSEL1 = 0;

    IO0DIR |= RS | EN;
    IO0DIR |= D4 | D5 | D6 | D7;

    delay(20);

    /* Initialization sequence for 4-bit mode */
    lcd_send_nibble(0x03);
    delay(5);
    lcd_send_nibble(0x03);
    delay(5);
    lcd_send_nibble(0x03);
    delay(5);
    lcd_send_nibble(0x02);   // switch to 4-bit mode

    lcd_cmd(0x28);  // 4-bit, 2 line
    lcd_cmd(0x0C);  // display ON, cursor OFF
    lcd_cmd(0x06);  // entry mode
    lcd_cmd(0x01);  // clear display
    delay(10);
}

void gpio_init()
{
	IO0DIR |= ((1<<0) | (1<<1));
}

int main(void)
{
	  int i;
    lcd_init();
	  gpio_init();
	lcd_cmd(0x01);
			delay(10);
	    lcd_cmd(0x80);
			lcd_string("Enter Password:");
		 while(1)
    {
			lcd_cmd(0x80);
			lcd_string("Enter Password:");

        for(i=0;i<4;i++)
        {
            entered[i] = keypad_getkey();

            lcd_cmd(0xC0+i);

            lcd_data('*');
        }

        entered[4]='\0';

        if(strcmp(entered,password)==0)
        {
					IO0SET |= (1<<1);
					lcd_cmd(0xC0);
            lcd_string("SUCCESS");
        }
        else
        {
					IO0SET |= (1<<0);
					lcd_cmd(0xC0);
            lcd_string("FAILURE");
        }
				
				delay(300);

				lcd_cmd(0x01);
				delay(10);
				IO0CLR |= ((1<<0) | (1<<1));
        for(i=0;i<500000;i++);
    }
}
