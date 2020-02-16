#include "tree.cpp"



int main(){

    Tree<int> tree;
    int option;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    while(true){
        cout << "\nBinary Search tree" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Insert a new node" << endl;
        cout << "2 - Find a node" << endl;
        cout << "3 - Delete a node" << endl;
        cout << "4 - Print post order" << endl;
        cout << "5 - Print pre order" << endl;
        cout << "6 - Print in order" << endl;

        cout << "Pick a number" << endl;
        cin >> option;

        switch (option){
            case 0: {
                return 0;
            }
            case 1: {
                system("clear");
                int newValue;
                cout << "Enter the value to be inserted " <<endl;
                cin >> newValue;
                tree.insert(newValue);
                cout << "Value " << newValue << " successfully saved into tree" <<endl;
                break;
            }
            case 2: {
                system("clear");
                int valueToSearch;
                cout << "Which value are you searching for? " <<endl;
                cin >> valueToSearch;
                Node<int>* result = tree.getElement(tree.getRoot(), valueToSearch);
                if(result == NULL) cout << "Value is not in the tree" <<endl;
                else cout << "Found : " << result->getValue() <<endl;
                break;
            }
            case 3: {
                system("clear");
                int valueToRemove;
                cout << "Enter the value to be removed " <<endl;
                cin >> valueToRemove;
                tree.deleteNode(valueToRemove);
                cout << "Value " << valueToRemove << " was removed " <<endl;
                break;
            }
            case 4: {
                system("clear");
                tree.postOrder(tree.getRoot());
                break;
            }
            case 5: {
                system("clear");
                tree.preOrder(tree.getRoot());
                break;
            }
            case 6: {
                system("clear");
                tree.inOrder(tree.getRoot());
                break;
            }
            default: {
                system("clear");
                cout << "Insert a valid option! " <<endl;
                break;
            }
        }
    }


    return 0;
}