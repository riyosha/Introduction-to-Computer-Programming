#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50


typedef struct stack {
    int data[MAX];
    int top;
} stack;
void push(stack* sp, int value);
int pop(stack* sp);
void display(stack* sp);

int main(void) {
    stack* stack1 = malloc(sizeof(stack));
    stack1->top=-1;
    int popped_number;

    push(stack1, 5);
    push(stack1, 8);
    push(stack1, 2);
    push(stack1, 10);
    display(stack1);

    popped_number = pop(stack1);
    printf("\nValue removed = %i\n", popped_number);
    display(stack1);

    return 0;
}

void push(stack* sp, int value) {
    //pushes value on top of stack
    if(sp->top == MAX-1) {
        printf("Insertion not possible\n");
    }
    else {
        (sp->top)++;
        sp->data[sp->top] = value;
    }
}

int pop(stack* sp) {
    //deletes value from top of stack
    int t;
    if(sp->top == -1) {
        printf("Removal not possible\n");
        return -1;
    }
    else {
        t = sp->data[sp->top];
        (sp->top)--;
        return t;
    }
}

void display(stack* sp) {
    for(int i = sp->top; i>=0;i--) {printf("%i ",sp->data[i]);}
}