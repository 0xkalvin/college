
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
const int useMultiThread = 1;


typedef struct fib_params
{
    int n;
    int result;

} fib_params;

void *fibonnaci(void *arg)
{

    fib_params *params = (fib_params *)arg;
    int n = params->n;
    int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    params->result = fib[n];
    return NULL;
}


int main(void)
{

    int n;
    printf("Enter the number of a fibonacci term you wanna know: \n");
    scanf("%d", &n);

    if (useMultiThread)
    {

        pthread_t t1;
        fib_params *p1 = (fib_params *)malloc(sizeof(fib_params));
        p1->n = n - 1;
        if (pthread_create(&t1, NULL, fibonnaci, (void *)p1))
        {
            printf("Thread 1 has failed");
            exit(-1);
        }

        pthread_t t2;
        fib_params *p2 = (fib_params *)malloc(sizeof(fib_params));
        p2->n = n - 2;
        if (pthread_create(&t2, NULL, fibonnaci, (void *)p2))
        {
            printf("Thread 2 has failed");
            exit(-1);
        }

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);

        printf("Fib of %d is %d \n", n, p1->result + p2->result);

        free(p1);
        free(p2);
        pthread_exit(NULL);
    }
    else {
        

    }

    return 0;
}