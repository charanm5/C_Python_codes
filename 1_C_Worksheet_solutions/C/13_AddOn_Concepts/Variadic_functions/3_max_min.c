#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

void MaxMin(int count, ...)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int temp;
    va_list args;
    va_start(args,count);
    for(int i=0;i<count;i++)
    {
        temp = va_arg(args,int);
        if(temp < min)
            min = temp;
        if(temp > max)
            max = temp;
    }
    va_end(args);
    printf("Max = %d , Min = %d\n",max,min);
}

int main() {
   MaxMin(5,1,2,3,4,5);
   MaxMin(2,32,23);
   
   return 0;
}