#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* reverse(node* head);
void free_list(node* head);

int main(void) {
    node* head = malloc(sizeof(node));
    node* node2 = malloc(sizeof(node));
    node* node3 = malloc(sizeof(node));

    head->val = 1;
    head->next=node2;
    node2->val=2;
    node2->next=node3;
    node3->val=3;
    node3->next=NULL;

    head = reverse(head);

    node* p = head;
    //prints list
    while ( p != NULL) {

        printf(p == head?"%d":", %d", p->val);
        p = p->next;

    }

    free_list(head);
    return 0;

}

node* reverse(node* head) {
    //function recursively reavhes the last node and then starts reversing the pointers in each node
    //base case for last two nodes
    if(!head||!head->next) {return head;}

    node* rest = reverse(head->next);
    head->next->next=head;

    head->next=NULL;
    //rest remains the last node in every call
    return rest;

}

void free_list(node* head) {
    node* prev = head;
    node* temp;
    while(prev) {
        temp=prev->next;
        free(prev);
        prev = temp;
    }
}