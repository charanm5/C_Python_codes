#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t size = 1024 * 1024 * 1024; 

    void *ptr = malloc(size);

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocation successful!\n");

    free(ptr);

    return 0;
}