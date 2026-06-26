#include <LPC213x.h>
#include <stdint.h>

void delay_ms(unsigned int ms)
{
	  T0TCR = 0x02;      
    T0TC  = 0;

    T0TCR = 0x01;      

    while(T0TC < ms);  

    T0TCR = 0x00;      	
}

int main()
{
	uint32_t count=0;
	uint8_t prev_state = 0;
	  T0CTCR = 0x00;      
    T0PR   = 11999;     

	IO0DIR |= (1<<0) | (1<<1) | (1<<2) | (1<<3);
	while(1)
	{
		
		if(IO0PIN & (1<<4))
		{
			if(!prev_state)
			{
				count++;
				delay_ms(500);
				IO0CLR = 0x0F;
				IO0SET |= (count & 0x0F);
				prev_state = 1;
			}
		}
		else
			prev_state = 0;
	}
}
