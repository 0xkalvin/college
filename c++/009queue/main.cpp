#include "queue.h"

using namespace std;

int main(){

    Queue q;

    for(int i = 0; i < 10; i++)  q.enqueue(i);

    q.print();

     
    for(int i = 0; i < 5; i++) q.dequeue();   

    q.print();

    return 0;
}