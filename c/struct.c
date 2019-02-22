#include <stdio.h>
#include <stdlib.h>


// creates type 'struct User'
struct User
{
    int userId;
    char firstName[30];
    char lastName[30];
    int age;
    float weight;

};

// creates type 'struct Point'
struct Point
{
    int x;
    int y;
};
// rename the type 'struct Point' to Point
typedef struct Point Point;

// it`s possible to rename a native existing type also
typedef int newInt;


// combining those two syntax, we can do
typedef struct Book{
    char author[40];
    char title[40];
} Book;

int main(){

    struct User jack;
    Point p1;

    jack.age = 25;
    p1.x = 1;

    newInt a;
    a = 999;

    printf("\n the age of this user is %d \n\n", jack.age);
    printf("X value for this Point type is  %d \n\n", p1.x);
    printf("The new integer type variable has the value %d\n", a);


    

}