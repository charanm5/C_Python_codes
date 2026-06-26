#include<stdint.h>

void uart_init(void);
void uart_send(char *str);
uint8_t uart_recv(void);
