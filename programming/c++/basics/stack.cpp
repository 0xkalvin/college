# include<iostream>
#define MAX 1000

using namespace std;

class Stack{
    
    private:
        int top;

    public:
        int a[MAX];
        Stack(){top = -1;}
        void push(int x); 
        void pop(); 
        bool isEmpty();
        void printStack();
        int getTop(); 
};


// add element into stack
void Stack::push(int x){
    if(x >= MAX - 1) cout << " STACK OVERFLOW !!! "<<endl;
    else
    {
        a[++top] = x;
        cout<<x <<" pushed into stack\n"<<endl; 
    }
}

// remove element from stack
void Stack::pop(){
    if(top < 0) cout << " STACK UNDERFLOW !!! "<<endl;
    else
    {
        int x = a[top--];
        cout<<x <<" popped from stack\n"<<endl; 
    }
}

bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

int Stack::getTop(){
    return a[top];
}

void Stack::printStack(){
    system("clear");
    cout << "MY STACK"<<endl;
    cout << " ____"<<endl<<endl;
    for(int i = top; i >= 0; i--){
        cout << "  "<<a[i] <<endl;
    }
    cout << " ____"<<endl<<endl;
    
}

int main(){

    Stack s1;
    int size;

    cout << "enter the size of the stack"<<endl;
    cin >> size;

    for(int i = 0; i < size; i++){
        s1.push(i*10);
    }
    
    s1.printStack();


    return 0;
}