#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    float marks;
};

void updateStudent(struct Student *s)
{
    s->id = s->id + 1;
    s->marks = s->marks + 10.0f;
}

int main()
{
    struct Student *sp = NULL;

    sp = (struct Student *)malloc(sizeof(struct Student));
    if (sp == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    sp->id = 101;
    sp->marks = 75.5f;

    printf("Before update: id = %d, marks = %.2f\n", sp->id, sp->marks);

    updateStudent(sp);

    printf("After update: id = %d, marks = %.2f\n", sp->id, sp->marks);

    free(sp);
    sp = NULL;

    return 0;
}