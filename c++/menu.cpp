#include <iostream>
using namespace std;

int numbers[10];

void print(){
    cout << "[";
    for(int i = 0; i < 10; i++){
        cout << numbers[i] << " ";
    }
    cout << "]";
}

string addElement(int n, int position){

    position--;
    if(position < 1 || position > 10){
        return "Ouf of range! ";
    }
    if(numbers[position] > 0){
        return "This position is already occupied! ";
    }

    numbers[position] = n;
    return "Added it successfully! ";
}

string deleteElement(int position){
    position--;
    if(position < 1 || position > 10){
        return "Out of range! ";
    }
    else if(numbers[position] == 0){
        return "This position value is already zero! ";
    }
    numbers[position] = 0;
    return "Number deleted successfully! ";
}

string exchangeElementsPosition(int pos1, int pos2){
    pos1--;
    pos2--;
    if(numbers[pos1] == 0 || numbers[pos2] == 0 ){
        return "You cannot exchange the position of a zero! ";
    }
    if(pos1 < 1 || pos1 > 10 || pos2 < 1 || pos2 > 10){
        return "Out of range! ";
    }

    int temp = numbers[pos1];
    numbers[pos1] = numbers[pos2];
    numbers[pos2] = temp;

    return "elements position exchanged successfully! ";
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = 0;
    }

    while (true)
    {
        system("clear");
        cout << "\n";
        cout << "------ ARRAY MENU --------";
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

        if(choice == 0){
            break;
        }
        else if(choice == 1){
            print();
        }
        else if(choice == 2){
            cout << "Insert the new element" <<endl;
            int n;
            cin >> n;
            cout << "Insert its position (1 to 10)" <<endl;
            int position;
            cin >> position; 
            cout << addElement(n, position) <<endl;
        }
        else if(choice == 3){
            cout << "Insert the element position which you want to delete (1 to 10)" <<endl;
            int position;
            cin >> position;
            cout << deleteElement(position) <<endl;
        }
        else if(choice == 4){
            cout << "Insert the position of the elements you want to exchange (1 to 10)" <<endl;
            int pos1, pos2;
            cin >> pos1;
            cin >> pos2;
            cout << exchangeElementsPosition(pos1, pos2) <<endl;
        }

    }

    return 0;
}