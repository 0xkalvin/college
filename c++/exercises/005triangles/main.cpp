#include <stdlib.h>
#include <iostream>
#include "triangle.h"

using namespace std;

void triangle_operations(){
   
    Triangle t1(1,2,3);
    Triangle t2(3,4,5);

    double area_total = t1 + t2;

    cout <<"t1 area " <<t1.getArea() <<endl;
    cout <<"is t1 valid " << boolalpha << t1.isValid() <<endl<<endl;
    cout <<"t2 area " << t2.getArea() <<endl;
    cout <<"is t2 valid " << boolalpha<< t2.isValid() <<endl<<endl;
    
    bool eq = t2 == t1;
    cout <<"is equal " << boolalpha << eq <<endl;

    bool gt = t2 > t1;
    cout <<"is greater than " << boolalpha << gt <<endl;

    cout <<"t1 area `"<<t1.getArea() << "` + t2 area `" <<t2.getArea()<<"` is "<<area_total <<endl;
}

void triangle_array(Triangle arr[]){
    
    for(int i = 0; i < 3; i++){
        int a, b, c;
        cout <<"Enter the 3 sides of the "<< i <<" triangle" <<endl;
        cin >> a;
        cin >> b;
        cin >> c;
        arr[i] = Triangle(a,b,c);
    }

    for(int i = 0; i < 3; i++){
        cout << "The area of the triangle at position " << i << " is "<< arr[i].getArea() <<endl;
    }

    cout <<"The number of existing triangles is " <<arr[0].getNumOfTriangles()<<endl;

}

void total_area_array(Triangle arr[]){

    int total_area = 0;
    for(int i = 0; i < 3; i++){
        total_area += arr[i].getArea();
    }

    cout << "the total area of this array of triangles is " << total_area << endl;
}


int main(){


    Triangle arr[3];

    while (true)
    {
        cout << "\n";
        cout << "------ TRIANGLES AND STUFF  --------\n";
        cout << "\n         0 - exit.";
        cout << "\n         1 - next triangle info.";
        cout << "\n         2 - total area\n";

        int choice;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            triangle_array(arr);
        
        }
        else if (choice == 2){
            total_area_array(arr);
        }
    }


    return 0;
}