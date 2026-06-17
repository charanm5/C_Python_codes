#include <stdio.h>

void addMatrices(int *a, int *b, int *res, int r, int c)
{
    int i;

    for (i = 0; i < r * c; i++)
    {
        *(res + i) = *(a + i) + *(b + i);
    }
}

void transpose(int *mat, int *trans, int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            *(trans + j * r + i) = *(mat + i * c + j);
        }
    }
}

int main()
{
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[2][3] = {{6, 5, 4}, {3, 2, 1}};
    int sum[2][3];
    int trans[3][2];

    int i, j;

    addMatrices((int *)a, (int *)b, (int *)sum, 2, 3);

    printf("Matrix Sum:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    transpose((int *)a, (int *)trans, 2, 3);

    printf("\nTranspose of A:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}