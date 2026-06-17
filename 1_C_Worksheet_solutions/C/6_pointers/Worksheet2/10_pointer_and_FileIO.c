#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    long size;
    char *buffer;
    size_t result;

    fp = fopen("data.txt", "r+");
    if (fp == NULL)
    {
        printf("File open failed\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    buffer = (char *)malloc((size + 1) * sizeof(char));
    if (buffer == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    result = fread(buffer, 1, size, fp);
    buffer[result] = '\0';

    printf("File content:\n%s\n", buffer);

    fseek(fp, 0, SEEK_END);
    fprintf(fp, "\nAppended using pointer buffer\n");

    fclose(fp);
    free(buffer);
    buffer = NULL;

    return 0;
}