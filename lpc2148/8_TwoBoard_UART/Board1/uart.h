#include<LPC213x.h>
#include<stdint.h>

void uart0_init(void);
void uart1_init(void);

void uart0_send(char *str);
void uart1_send(char *str);

uint8_t uart0_recv(void);
uint8_t uart1_recv(void);
