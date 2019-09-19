#include "priorityqueue.h"

PriorityQueue::PriorityQueue()
{
    this->front = this->rear = NULL;
}

PriorityQueue::~PriorityQueue()
{
    delete this->front;
    delete this->rear;
}

void PriorityQueue::enqueue(int v, int p)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = v;
    newNode->priority = p;
    newNode->next = NULL;

    if (this->front == NULL)
    {
        this->front = this->rear = newNode;
    }
    else if(this->front->priority < p){
        newNode->next = this->front;
        this->front = newNode;
    }
    else
    {   
        Node* temp = this->front;
        while(temp->next != NULL && temp->next->priority > p){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return;
}


void PriorityQueue::dequeue()
{
    if (this->front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        Node *temp = this->front;
        this->front = this->front->next;
    }
    return;
}


void PriorityQueue::print()
{

    if (this->front == NULL)
        printf("\nQueue is Empty!!!\n");
    else
    {
        Node *temp = this->front;
        while (temp->next != NULL)
        {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf(" %d\n", temp->data);
    }
}