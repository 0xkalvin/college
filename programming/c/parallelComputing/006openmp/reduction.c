#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1073741824

int main(void)
{
    int numThreads = omp_get_max_threads();
    long long int sum = 0;
    long long int *array;
    array = (long long int *)malloc(N * sizeof(long long int));

    // Populate array
    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }

    printf("Using %d threads \n", numThreads);
    // Compute sum using multi threads with omp reduction 
    #pragma omp parallel for reduction(+:sum)
        for (long long int i = 0; i < N; i++)
        {
            sum += array[i];
        }

    printf("Sum is %lli \n", sum);

    return 0;
}