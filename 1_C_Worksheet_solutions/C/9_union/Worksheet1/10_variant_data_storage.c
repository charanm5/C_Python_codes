#include <stdio.h>

struct Employee
{
    char name[50], type;
    union
    {
        float salary;
        float hourly_wage;
    } pay;
};

void inputEmployee(struct Employee *e);
void displayEmployee(struct Employee e);

int main()
{
    struct Employee emp[10];
    int i, n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        inputEmployee(&emp[i]);
    }

    printf("\nEmployee Details\n");

    for (i = 0; i < n; i++)
        displayEmployee(emp[i]);

    return 0;
}

void inputEmployee(struct Employee *e)
{
    printf("Enter name: ");
    scanf("%s", e->name);

    printf("Enter type (S for Salaried, H for Hourly): ");
    scanf(" %c", &e->type);

    if (e->type == 'S' || e->type == 's')
    {
        printf("Enter salary: ");
        scanf("%f", &e->pay.salary);
    }
    else
    {
        printf("Enter hourly wage: ");
        scanf("%f", &e->pay.hourly_wage);
    }
}

void displayEmployee(struct Employee e)
{
    printf("\nName: %s\n", e.name);

    if (e.type == 'S' || e.type == 's')
        printf("Salary: %.2f\n", e.pay.salary);
    else
        printf("Hourly Wage: %.2f\n", e.pay.hourly_wage);
}