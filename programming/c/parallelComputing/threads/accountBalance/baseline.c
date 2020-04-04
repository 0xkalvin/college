#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL_TRANSACTIONS 10000000
#define AMOUNT_PER_TRANSACTION 10

void* deposits(void *args){

    int *currentBalance = (int*)args;

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++)
    {
        *currentBalance += AMOUNT_PER_TRANSACTION;
    }
}

void* withdrawals(void *args){

    int *currentBalance = (int*)args;

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++)
    {
        *currentBalance -= AMOUNT_PER_TRANSACTION;
    }

}




int main(void){


    int balance = 1000;

    printf("Initial balance is %d \n", balance);

    deposits((void*)&balance);
    
    printf("balance after deposits is %d \n", balance);

    withdrawals((void*)&balance);

    printf("Balance after withdrawals %d \n", balance);


    return 0;
}