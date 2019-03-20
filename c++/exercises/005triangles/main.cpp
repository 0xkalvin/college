#include <stdlib.h>
#include <iostream>
#include "triangle.h"

using namespace std;

int main(){

    Triangle t1(1,2,3);
    Triangle t2(3,4,5);



    double area_total = t1 + t2;

    cout <<"t1 area " <<t1.getArea() <<endl;
    cout <<"is t1 valid " << boolalpha << t1.isValid() <<endl;
    cout <<"t2 area " << t2.getArea() <<endl;
    cout <<"is t2 valid " << boolalpha<< t2.isValid() <<endl;
    
    cout << area_total <<endl;


    return 0;
}