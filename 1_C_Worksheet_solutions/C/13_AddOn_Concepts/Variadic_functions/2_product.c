#include <stdio.h>
#include <stdarg.h>

void multiply(int count, ...)
{
    int product = 1;
    va_list args;
    va_start(args,count);
    for(int i=0;i<count;i++)
        product *= va_arg(args,int);
    va_end(args);
    printf("Sum = %d\n",product);
}

int main() {
   multiply(3,1,2,3);
   multiply(2,32,23);
   
   return 0;
}