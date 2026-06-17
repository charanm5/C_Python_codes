#include <stdio.h>
#include <string.h>

struct Student
{
    char type;
    union
    {
        int roll_number;
        char id[10];
    } data;
};

void initRoll(struct Student *s, int roll);
void initID(struct Student *s, char id[]);
void display(struct Student s);

int main()
{
    struct Student s1, s2;

    initRoll(&s1, 101);
    initID(&s2, "STU1001");

    display(s1);
    display(s2);

    return 0;
}

void initRoll(struct Student *s, int roll)
{
    s->type = 'R';
    s->data.roll_number = roll;
}

void initID(struct Student *s, char id[])
{
    s->type = 'I';
    strcpy(s->data.id, id);
}

void display(struct Student s)
{
    if (s.type == 'R')
        printf("Roll Number: %d\n", s.data.roll_number);
    else if (s.type == 'I')
        printf("Student ID: %s\n", s.data.id);
}