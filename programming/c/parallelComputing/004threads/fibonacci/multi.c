
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct fib_params
{
    long long int n;
    long long int result;

} fib_params;

void *multiThreadFibonacci(void *args)
{
    fib_params *params = (fib_params *)args;
    long long int n = params->n;
    long long int fib[n];

    fib[0] = 0;
    fib[1] = 1;

    for (long long int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    params->result = fib[n];
    return NULL;
}

int main(void)
{

    long long int n = 163;

    if (n < 0)
    {
        printf("Number of the fibonacci term should be a non negative integer");
        exit(-1);
    }

    if (n <= 1)
    {
        printf("Multi Thread: the Fibonacci of %lli is %lli \n", n, n);
        return 0;
    }

    pthread_t t1;
    fib_params *p1 = (fib_params *)malloc(sizeof(fib_params));
    p1->n = n - 1;
    if (pthread_create(&t1, NULL, multiThreadFibonacci, (void *)p1))
    {
        printf("Thread 1 has failed");
        exit(-1);
    }

    pthread_t t2;
    fib_params *p2 = (fib_params *)malloc(sizeof(fib_params));
    p2->n = n - 2;
    if (pthread_create(&t2, NULL, multiThreadFibonacci, (void *)p2))
    {
        printf("Thread 2 has failed");
        exit(-1);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Multi Thread: the Fibonacci of %lli is %lli \n", n, p1->result + p2->result);

    free(p1);
    free(p2);
    pthread_exit(NULL);

    return 0;
}