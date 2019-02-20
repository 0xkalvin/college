#include <iostream>
#include "adtArray-header.h"

using namespace std;


int main()
{
    int *new_array;
    
    adtArray array;


    system("clear");
    while (true)
    {
        cout << "\n";
        cout << "------ ARRAY MENU WITH CLASS--------";
        cout << "\n0 - exit.";
        cout << "\n1 - print array.";
        cout << "\n2 - add element";
        cout << "\n3 - delete element";
        cout << "\n4 - exchange elements position";
        cout << "\n5 - find max and min";
        cout << "\n6 - sort by ascending order";
        cout << "\n7 - sort by descending order";
        cout << "\n8 - returns new sorted array";
        cout << "\n---------------------------";
        cout << "\n Which option will it be -> ";

        int choice;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            array.print();
        }
        else if (choice == 2)
        {
            cout << "Insert the new element" << endl;
            int n;
            cin >> n;
            cout << "Insert its position (1 to 10)" << endl;
            int position;
            cin >> position;
            cout << array.addElement(n, position) << endl;
        }
        else if (choice == 3)
        {
            cout << "Insert the element position which you want to delete (1 to 10)" << endl;
            int position;
            cin >> position;
            cout << array.deleteElement(position) << endl;
        }
        else if (choice == 4)
        {
            cout << "Insert the position of the elements you want to exchange (1 to 10)" << endl;
            int pos1, pos2;
            cin >> pos1;
            cin >> pos2;
            cout << array.exchangeElementsPosition(pos1, pos2) << endl;
        }
        else if (choice == 5)
        {
            cout << array.findMaxAndMin() <<endl;
        }
        else if (choice == 6)
        {
            array.selection_sort();
            cout << "by ascending order! " << endl;
            
        }
        else if (choice == 7)
        {
            array.selection_sort();
            array.invert_array(array.get_numbers());
            cout << "by descending order! " << endl;
        
        }
        else if(choice == 8){
            
            new_array = array.new_sorted_array();
            cout << "new array sorted " <<endl;

        }   
    }

    return 0;
}