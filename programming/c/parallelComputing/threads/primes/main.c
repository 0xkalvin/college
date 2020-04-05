#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define START 0
#define END 100

int *primes = NULL;
pthread_mutex_t locker = PTHREAD_MUTEX_INITIALIZER;

typedef struct range {
    int start;
    int end;
} range;


void* findPrimes(void* params){

    range r = *(range*)params;
    int isPrime;

    for (int i = r.start; i <= r.end; i++)
    {   
        
        if (i < 2)   continue;
        
        isPrime = 1;
        
        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if(isPrime){
            pthread_mutex_lock(&locker);
            primes[i - START] = i;
            pthread_mutex_unlock(&locker);

        } 
    }  
    return NULL;  
}


int main(void){

    primes = (int*)calloc((END - START), sizeof(int));

    pthread_t t1;
    range r1;
    r1.start = START;
    r1.end = END/2;
    pthread_create(&t1, NULL, findPrimes, (void*)&r1);

    pthread_t t2;
    range r2;
    r2.start = END/2 + 1;
    r2.end = END;
    pthread_create(&t2, NULL, findPrimes, (void*)&r2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for(int i = 0; i < END - START; i++){
        if(primes[i] != 0){
            printf("%d \n", primes[i]);
        }
    }

    pthread_mutex_destroy(&locker);
    free(primes);

    return 0;
}