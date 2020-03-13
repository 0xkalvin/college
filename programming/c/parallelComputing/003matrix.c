#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int **createMatrix(int size)
{
    int **m = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        m[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            m[i][j] = SIZE * i + j;
        }
    }
    return m;
}

void freeMemory(int **m, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(m[i]);
    }
    free(m);
}

void printMatrix(int **m, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int **multiplyMatrixIJK(int **m1, int **m2, int size){
    int **m3 = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        m3[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                m3[i][j]  += m1[i][k] * m2[k][j];
            }
        }
    }
    return m3;
}

int **multiplyMatrixIKJ(int **m1, int **m2, int size){
    int **m3 = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        m3[i] = (int *)malloc(size * sizeof(int));
        for (int k = 0; k < size; k++)
        {
            for (int j = 0; j < size; j++)
            {
                m3[i][j]  += m1[i][k] * m2[k][j];
            }
        }
    }
    return m3;
}

int main()
{
    int **m1, **m2, **m3;

    m1 = m2 = createMatrix(SIZE);
    m3 = multiplyMatrixIKJ(m1, m2, SIZE);
    // m3 = multiplyMatrixIJK(m1, m2, SIZE);

    printMatrix(m1, SIZE);
    printMatrix(m2, SIZE);
    printMatrix(m3, SIZE);

    freeMemory(m1, SIZE);
    freeMemory(m3, SIZE);

    return 0;
}
