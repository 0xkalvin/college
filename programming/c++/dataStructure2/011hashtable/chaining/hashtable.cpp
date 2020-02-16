#include "hashtable.h"


Node* createNode(int key, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        return NULL;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

HashTable::HashTable(int capacity){
    this->capacity = capacity;

    this->table = (Node**)malloc(this->capacity * sizeof(Node*));

    for(int i = 0; i < this->capacity; i++){
        this->table[i] = NULL;
    }
}

HashTable::~HashTable(){
    
    for(int i = 0; i < this->capacity; i++){
        free(this->table[i]);
    }

    free(this->table);
}

int HashTable::hash(int key){
    return key % this->capacity;
}


void HashTable::insert(int key, int value){
    
    int index = this->hash(key);

    if(this->table[index] != NULL){

        std::cout << "There's a collision for this key " << key << ". Chaining..."<<std::endl;
        
        Node* temp = this->table[index];

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = createNode(key, value);
    }
    else {
        this->table[index] = createNode(key, value);
    }

}


bool HashTable::search(int key){

    int index = this->hash(key);

    Node* temp = this->table[index];

    if(temp == NULL){
        return false;
    }
    else {
        
        while(temp != NULL){

            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
}
