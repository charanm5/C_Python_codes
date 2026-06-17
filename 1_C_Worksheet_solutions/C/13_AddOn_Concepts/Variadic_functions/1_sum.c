#include <stdio.h>
#include <stdarg.h>

void sum(int count, ...)
{
    int sum = 0;
    va_list args;
    va_start(args,count);
    for(int i=0;i<count;i++)
        sum += va_arg(args,int);
    va_end(args);
    printf("Sum = %d\n",sum);
}

int main() {
   sum(3,1,2,3);
   sum(2,32,23);
   
   return 0;
}