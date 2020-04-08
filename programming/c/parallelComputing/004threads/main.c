
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS_NUMBER 5

void* sayHello(void* args){
    int tid = (int)(long)args;
    printf("Hello from thread %d\n", tid);
    
}

int main(void){

    pthread_t threads[THREADS_NUMBER];
    pthread_attr_t attribute;

    pthread_attr_init(&attribute);
    pthread_attr_setdetachstate(&attribute, PTHREAD_CREATE_JOINABLE);

    for (int i = 0; i < THREADS_NUMBER; i++)
    {   
        printf("Creating thread %d...\n", i);
        int statusCode = pthread_create(&threads[i], &attribute, sayHello, (void*)(long)i);
        if(statusCode){
            printf("Create thread has failed with code %d", statusCode);
            exit(-1);
        }
    }  

    void *status;
    pthread_attr_destroy(&attribute);
    for(int i = 0; i < THREADS_NUMBER; i++){

        int statusCode = pthread_join(threads[i], &status);

        if(statusCode){
            printf("Thread joining has failed with code %d", statusCode);
            exit(-1);
        }

        printf("Main thread has completed joining with thread %d \n", i);
    }


    pthread_exit(NULL);
    return 0;
}