#include <stdio.h>
#include <stddef.h>

void mem_copy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    while (n--)
    {
        *d++ = *s++;
    }
}

int main()
{
    int src_int[] = {1, 2, 3, 4, 5};
    int dest_int[5];

    mem_copy(dest_int, src_int, sizeof(src_int));

    printf("Copied integer array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dest_int[i]);
    }
    printf("\n");

    float src_float[] = {1.1f, 2.2f, 3.3f, 4.4f};
    float dest_float[4];

    mem_copy(dest_float, src_float, sizeof(src_float));

    printf("Copied float array: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%.1f ", dest_float[i]);
    }
    printf("\n");

    return 0;
}