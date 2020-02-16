#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>


typedef struct Node {

    int value;
    int key;
    struct Node* next;

} Node;

class HashTable{

    private:
        Node** table;
        int capacity;

    public:

        HashTable(int capacity);
        ~HashTable();
        int hash(int key);
        bool search(int key);
        void insert(int key, int value);

};


#endif