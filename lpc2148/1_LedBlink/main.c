#include <LPC213x.h>

/* software delay*/
/*void delay()
{
    int i;
    for(i=0;i<500000;i++);
}*/

void delay_ms(unsigned int ms)
{
    T0TCR = 0x02;      // Reset timer
    T0TC  = 0;

    T0TCR = 0x01;      // Start timer

    while(T0TC < ms);  // Wait

    T0TCR = 0x00;      // Stop timer
}

int main()
{
    T0CTCR = 0x00;      // Timer mode
    T0PR   = 11999;     // 1 ms resolution

    IO0DIR |= (1<<10);
		IO0DIR |= (1<<11);
		IO0DIR |= (1<<12);

    while(1)
    {
        IO0SET = (1<<10);
        delay_ms(1000);

        IO0CLR = (1<<10);
			  IO0SET = (1<<11);
        delay_ms(1000);
			
				IO0CLR = (1<<11);
			  IO0SET = (1<<12);
        delay_ms(1000);
			
				IO0CLR = (1<<12);
			  
    }
}
