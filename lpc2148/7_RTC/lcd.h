#include<LPC21xx.h>

void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_string(const char *);
void lcd_int(int);

