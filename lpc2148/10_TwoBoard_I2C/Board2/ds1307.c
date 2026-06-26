#include <LPC213x.h>
#include "i2c.h"

unsigned char sec,min,hour;

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
