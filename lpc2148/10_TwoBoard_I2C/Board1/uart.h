

void uart0_init(void);
void uart0_tx_char(char ch);
void config_vic_for_uart0(void);
void en_uart0_interrupt(void);
void uart0_tx_string(char *ptr);
void uart0_tx_integer(unsigned int num);
void uart0_tx_hex(unsigned char data);

void I2C1_SlaveInit(void);
unsigned char I2C1_SlaveRead(void);
