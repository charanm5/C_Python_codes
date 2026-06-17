#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 0;
    int choice, value;
    int i;

    while (1)
    {
        printf("MENU\n");
        printf("1. Add element\n");
        printf("2. Display array\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value: ");
            scanf("%d", &value);

            int *temp = realloc(arr, (size + 1) * sizeof(int));
            if (temp == NULL)
            {
                printf("Memory allocation failed!\n");
                free(arr);
                return 1;
            }

            arr = temp;
            arr[size] = value;
            size++;
        }
        else if (choice == 2)
        {
            if (size == 0)
            {
                printf("Array is empty\n");
            }
            else
            {
                printf("Array elements: ");
                for (i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            free(arr);
            printf("Memory freed. Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}