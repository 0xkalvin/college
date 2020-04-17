#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1073741824

int main(void)
{
    printf("Running version 3 \n");
    long long int *array = (long long int *)(malloc(N * sizeof(long long int)));
    long long int sum = 0;

    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }

    #pragma omp parallel shared(array, sum)
    {
        int tid = omp_get_thread_num();
        printf("Thread %d starting... \n", tid);
        
        #pragma omp for reduction(+: sum)
        for (long long int i = 0; i < N; i++)
        {
            sum += array[i];
        }
    }

    printf("The sum of the array is %lli \n", sum);

    return 0;
}