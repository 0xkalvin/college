#include "stack.cpp"

int main(){

    Stack<int> pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    pilha.print();

    pilha.pop();

    pilha.print();

    return 0;
}