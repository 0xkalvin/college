#include "priorityqueue.h"


int main(void){

    PriorityQueue pq;


    for(int i = 0; i < 10; i++) pq.enqueue(i, i );

    pq.print();

    for(int i = 0; i < 5; i++) pq.dequeue();

    pq.print();

    return 0;
}