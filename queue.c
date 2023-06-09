#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct queue {
    int data[MAX];
    int front;
    int rear;
} queue;

void enqueue(queue* q1, int value);
void dequeue(queue* q1);
void display(queue* q1);


int main(void) {
    queue* q1 = (queue*)malloc(sizeof(queue));
    q1->front=0;
    q1->rear=0;

    enqueue(q1, 1);
    enqueue(q1, 4);
    enqueue(q1, 8);
    enqueue(q1, 12);
    enqueue(q1, 3);

    dequeue(q1);

    display(q1);

}

void enqueue(queue* q1, int value) {
    //adds vale to rear of queue
    if (q1->rear==MAX) {printf("Queue is full");}
    else if (q1->rear<MAX) {
        q1->data[q1->rear]=value;
        (q1->rear)++;
    }    
}

void dequeue(queue* q1) {
    //deletes value from front of queue
    if (q1->front==q1->rear) {printf("Queue is empty");}
    else if (q1->front<q1->rear) { 
        printf("Dequeued element is %i\n", q1->data[q1->front]);
        q1->front++;
    }
}

void display(queue* q1) {
    //prints queue
    for (int i = q1->front; i<q1->rear; i++) {
        printf ("%i ", q1->data[i]);
    }
    
}

