#include <stdlib.h>
#include <iostream>
#include "triangle.h"

using namespace std;

void print_triangle_array(Triangle arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i].getArea() << endl;
    }
}

Triangle *initialize_triangle_array()
{
    int a = 0;
    int b = 0;
    int c = 0;

    Triangle *triangles = (Triangle *)malloc(10 * sizeof(Triangle));

    for (int i = 0; i < 10; i++)
    {
        triangles[i] = *(new Triangle(a, b, c));
    }

    return triangles;
}

void update_triangle_array(Triangle arr[], int a, int b, int c, int index)
{
    if (index >= 0 && index < 10)
    {
        arr[index] = Triangle(a, b, c);
        cout << "The triangle " << index << " was updated sucessfully" << endl;
        cout << "its area is " << arr[index].getArea() << " and is perimeter is " << arr[index].getPerimeter() << endl;
    }
    else
        cout << "Out of range! Enter a valid index. " << endl;
}

void total_area_array(Triangle arr[], int size)
{

    double total_area = 0;
    for (int i = 0; i < size; i++)
    {
        total_area += arr[i].getArea();
    }

    cout << "the total area of this array of triangles is " << total_area << endl;
}

int main()
{

    int size = 10;
    Triangle *arr = initialize_triangle_array();

    while (true)
    {
        cout << "\n";
        cout << "------ TRIANGLES AND STUFF  --------\n";
        cout << "\n         0 - exit.";
        cout << "\n         1 - update a triangle.";
        cout << "\n         2 - total area\n";

        int choice;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {

            int a, b, c;
            int index;
            cout << "Enter the index of the triangle which you're going to update (0 - 9): " << endl;
            cin >> index;
            cout << "Enter the 3 sides of the triangle" << endl;
            cin >> a;
            cin >> b;
            cin >> c;
            update_triangle_array(arr, a, b, c, index);
        }
        else if (choice == 2)
        {
            total_area_array(arr, size);
        }
    }

    return 0;
}