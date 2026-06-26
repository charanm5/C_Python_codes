#include <LPC213x.h>

void PWM_Init(void)
{
    PINSEL0 &= ~(3<<14);
    PINSEL0 |=  (2<<14);     // P0.7 = PWM2

    PWMPR = 0;

    PWMMR0 = 15000;          // Period

    PWMMR2 = 0;

    PWMMCR = (1<<1);         // Reset on MR0

    PWMLER = (1<<0) | (1<<2);

    PWMPCR = (1<<10);        // Enable PWM2

    PWMTCR = (1<<1);         // Reset counter
    PWMTCR = (1<<0) | (1<<3);// Enable PWM
}

void SetSpeed(unsigned int duty)
{
    if(duty >= 100)
        PWMMR2 = PWMMR0 - 1;
    else
        PWMMR2 = (PWMMR0 * duty)/100;

    PWMLER = (1<<2);
}
