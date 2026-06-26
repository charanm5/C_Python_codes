
void SPI0_Init(void);
unsigned char SPI0_TxRx(unsigned char data);
void EEPROM_WriteEnable(void);
void EEPROM_WriteByte(unsigned int addr, unsigned char data);
unsigned char EEPROM_ReadByte(unsigned int addr);
