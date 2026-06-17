#include <stdio.h>
#include <stdint.h>

#define REG_BASE 0x40000000

int main()
{
    volatile uint32_t *reg_modifiable = (volatile uint32_t *)REG_BASE;
    const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
    const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;

    /* Reading is allowed for all */
    printf("Read via reg_readonly: %u\n", *reg_readonly);
    printf("Read via reg_const_volatile: %u\n", *reg_const_volatile);

    /* *reg_readonly = 10; */   //  not allowed 
    /* *reg_const_volatile = 20; */ // not allowed 

    *reg_modifiable = 100;  //  allowed

    printf("Write done via reg_modifiable (conceptual)\n");

    return 0;
}