#include <lpc214x.h>

void UART0_Init(void);
void UART0_TxChar(char);
void UART0_TxString(char *);
char UART0_RxChar(void);
