#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    char *temp_str;
    char **arr_ptr = NULL;

    int count = 0;
    int i;

    scanf("%[^\n]", str);

    temp_str = strtok(str, " \n");

    while (temp_str != NULL)
    {
        char *ptr = malloc(strlen(temp_str) + 1);
        strcpy(ptr, temp_str);

        char **temp = realloc(arr_ptr, (count + 1) * sizeof(char*));
        if (temp == NULL)
        {
            printf("Memory error\n");
            return 1;
        }
        arr_ptr = temp;

        arr_ptr[count] = ptr;
        count++;

        temp_str = strtok(NULL, " \n");
    }

    for (i = 0; i < count; i++)
    {
        printf("%s\n", arr_ptr[i]);
        free(arr_ptr[i]);
    }

    free(arr_ptr);

    return 0;
}