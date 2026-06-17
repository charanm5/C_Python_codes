#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    char *input = NULL;
    int size = 50;

    buffer = (char *)malloc(size * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    input = (char *)malloc(size * sizeof(char));
    if (input == NULL)
    {
        printf("Memory allocation failed\n");
        free(buffer);
        return 1;
    }

    buffer[0] = '\0';

    printf("Enter first string (max %d chars): ", size - 1);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) < size)
    {
        strcpy(buffer, input);
    }

    printf("Stored: %s\n", buffer);

    printf("Enter second string (max %d chars): ", size - 1);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(buffer) + strlen(input) < size)
    {
        strcat(buffer, input);
    }
    else
    {
        printf("Not enough space to concatenate safely\n");
    }

    printf("Final string: %s\n", buffer);

    free(buffer);
    free(input);

    buffer = NULL;
    input = NULL;

    return 0;
}