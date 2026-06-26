#ifndef DS1307_H
#define DS1307_H

unsigned char dec_to_bcd(unsigned char);
unsigned char bcd_to_dec(unsigned char);
void DS1307_SetTime(void);
void DS1307_ReadTime(void);

#endif
