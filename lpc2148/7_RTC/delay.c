#include "delay.h"

void delay_ms(unsigned int delay)
{
	int i,j;
	for(i=0;i<delay;i++)
		for(j=0;j<6000;j++);
}
