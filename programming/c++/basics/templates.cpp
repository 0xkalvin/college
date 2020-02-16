#include <iostream>
using namespace std;


template <class My_template>
My_template add(My_template a, My_template b){
    return a + b ;
}



void test_adding(){
    int a = 10;
    int b = 20;

    double c = 1.2;
    double d = 3.4;

    cout <<"int sum: " << add(a,b) <<endl;

    cout <<"double sum: " << add(c,d) <<endl;

}

int main(){

    test_adding();


    return 0;
}