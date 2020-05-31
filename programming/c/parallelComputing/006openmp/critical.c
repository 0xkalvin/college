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

    if(array == NULL){
        printf("Error during memory allocation for array");
        exit(-1);
    }

    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }

    printf("Using %d threads \n", numThreads);
    #pragma omp parallel
    {
        long long int temp = 0;

        #pragma omp for
        for (long long int i = 0; i < N; i++)
        {
            temp += array[i];
        }

        #pragma omp critical
        {
            sum += temp;
        }
    }

    printf("Sum is %lli \n", sum);

    return 0;
}