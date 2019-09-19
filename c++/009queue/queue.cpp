#include "queue.h"

Queue::Queue()
{
    this->front = this->rear = NULL;
}

Queue::~Queue()
{
    delete this->front;
    delete this->rear;
}

void Queue::enqueue(int value)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (this->front == NULL)
    {
        this->front = this->rear = newNode;
    }
    else
    {
        this->rear->next = newNode;
        this->rear = newNode;
    }

    return;
}

void Queue::dequeue()
{
    if (this->front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        Node *temp = this->front;
        this->front = this->front->next;
        free(temp);
    }
    return;
}

void Queue::print()
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