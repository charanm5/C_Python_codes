#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[50];
    int age;
};

int main()
{
    struct Student *ptr;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", ptr[i].name);  // reads full line with spaces

        printf("Age: ");
        scanf("%d", &ptr[i].age);
    }

    printf("Student Details: ");
    for (i = 0; i < n; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", ptr[i].name);
        printf("Age : %d\n\n", ptr[i].age);
    }

    free(ptr);
    printf("Memory freed successfully.\n");

    return 0;
}