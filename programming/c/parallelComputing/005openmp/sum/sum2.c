#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1073741824

int main(void)
{
    printf("Running version 2 \n");
    long long int *array = (long long int *)(malloc(N * sizeof(long long int)));
    long long int sum = 0;

    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }

    #pragma omp parallel shared(array, sum)
    {
        long long int tid = omp_get_thread_num();
        printf("Thread %lli starting... \n", tid);
        
        long long int max_num_threads = omp_get_max_threads();
        long long int start = tid * N/max_num_threads; 
        long long int end = start + N/max_num_threads;
        
        for (long long int i = start; i < end; i++)
        {
            #pragma omp critical
            sum += array[i];
        }
    }

    printf("The sum of the array is %lli \n", sum);

    return 0;
}