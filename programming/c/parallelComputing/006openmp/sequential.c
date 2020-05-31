#include <stdio.h>
#include <stdlib.h>
#define N 1073741824

int main(void)
{

    long long int sum = 0;
    long long int *array;
    array = (long long int *)malloc(N * sizeof(long long int));

    // Populate array
    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }

    for (long long int i = 0; i < N; i++)
    {
        sum += array[i];
    }

    printf("Sum is %lli \n", sum);

    return 0;
}