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

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.printStack();


    return 0;
}