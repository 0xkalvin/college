#include <stdio.h>
#include <stdlib.h>

// defining type Node which has a value and a pointer to the next element 
typedef struct Node{
    int value;
    struct Node *next;
}Node;

// takes a 
void printList(Node *n){  
    printf("[ ");
    while(n != NULL){
        if(n->next == NULL) printf(" %d", n->value);
        else    printf(" %d,", n->value);

        n = n->next;
    }
    printf(" ]");
    printf("\n\n");
}

Node *basicLinkedList(){
    
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    
    // allocate 2 nodes 
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));
    
    head->value = 10;     // assign value in first node
    head->next = second; // link first node with the second node

    second->value = 20;
    second->next = third;

    third->value = 30;
    third->next = NULL; // there`s no next element, so list ends here

    return head;
}

// ====================> TO DO:
// now that`s tricky 
Node *createDynamicLinkedList(int size){

    Node head;
    head.next = NULL;

    Node *current = &head;

    for(int i = 0; i < size; i++){
        current->next = malloc(sizeof*(current->next));
        current = current->next;
        current->value = i*10;
        current->next = NULL;
    }    

    return head.next;
    
}


int main(){

    int size = 10;
    Node *myBasicList = basicLinkedList();
    printList(myBasicList);

    Node *myDynamicList = createDynamicLinkedList(size);
    printList(myDynamicList);
   
    
   

    return 0;
}