#include "queue.cpp"

using namespace std;

int main(){

    Queue<int> q;

    for(int i = 0; i < 10; i++){
        q.enqueue(i*i);
    }

    cout << "Removing element from queue" << q.dequeue();

    return 0;
}