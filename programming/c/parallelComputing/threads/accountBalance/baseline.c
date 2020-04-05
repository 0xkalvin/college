#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL_TRANSACTIONS 2147483000
#define AMOUNT_PER_DEPOSIT 10
#define AMOUNT_PER_WITHDRAW 10


void* deposits(void *args){

    int *currentBalance = (int*)args;

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++)
    {
        *currentBalance += AMOUNT_PER_DEPOSIT;
    }
}

void* withdrawals(void *args){

    int *currentBalance = (int*)args;

    for (int i = 0; i < TOTAL_TRANSACTIONS; i++)
    {
        *currentBalance -= AMOUNT_PER_WITHDRAW;
    }

}


int main(void){

    int balance = 1000;

    printf("Initial balance is %d \n", balance);

    deposits((void*)&balance);
    withdrawals((void*)&balance);

    printf("Final balance is %d \n", balance);


    return 0;
}