#ifndef RTC_H
#define RTC_H
#include <LPC21xx.h>

void I2C0_Init(void);
void i2c_byte_write_frame(unsigned char sa, unsigned char mr, unsigned char data);
unsigned char i2c_byte_read_frame(unsigned char sa, unsigned char mr);

#endif
