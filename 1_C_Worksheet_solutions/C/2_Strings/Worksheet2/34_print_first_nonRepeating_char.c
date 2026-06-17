#include <stdio.h>

int main()
{
    char str[50];
    int freq[256];
    char queue[50];
    int front, rear,i;
    char ch;

    printf("Enter stream: ");
    scanf(" %[^\n]", str);

    for (i = 0; i < 256; i++)
        freq[i] = 0;

    front = 0;
    rear = 0;

    printf("Output: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        freq[(unsigned char)ch]++;

        queue[rear++] = ch;

        while (front < rear && freq[(unsigned char)queue[front]] > 1)
            front++;

        if (front == rear)
            printf("0 ");
        else
            printf("%c ", queue[front]);
    }

    printf("\n");

    return 0;
}