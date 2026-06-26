#include <LPC21xx.h>
#include "rtc.h"

unsigned char sec,min,hour;

unsigned char dec_to_bcd(unsigned char val)
{
    return ((val/10)<<4)|(val%10);
}

unsigned char bcd_to_dec(unsigned char val)
{
    return ((val>>4)*10)+(val&0x0F);
}

void DS1307_SetTime(void)
{

    i2c_byte_write_frame(0xD0, 0x0, 0x00);      // sec
    i2c_byte_write_frame(0xD0, 0x1, 0x59);     // min
    i2c_byte_write_frame(0xD0, 0x2, 0x23);     // hour

}

void DS1307_ReadTime(void)
{

    sec  = i2c_byte_read_frame(0xD0, 0x0);
    min  = i2c_byte_read_frame(0xD0, 0x1);
    hour = i2c_byte_read_frame(0xD0, 0x2);

}
