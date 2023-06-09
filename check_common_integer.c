#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

int check_common_integer(node* root_a, node* root_b);

int main (void) {
    node* head = malloc(sizeof(node));
    node* node2 = malloc(sizeof(node));
    node* node3 = malloc(sizeof(node));

    head->val = 1;
    head->next=node2;
    node2->val=2;
    node2->next=node3;
    node3->val=3;
    node3->next=NULL;

    node* root = malloc(sizeof(node));
    node* r2 = malloc(sizeof(node));
    node* r3 = malloc(sizeof(node));

    root->val = 0;
    root->next=r2;
    r2->val=2;
    r2->next=r3;
    r3->val=9;
    r3->next=NULL;

    check_common_integer(head, root);
}

int check_common_integer(node* root_a, node* root_b) {
    node* temp_a;
    int a, b;
    node* temp_b = root_b;
    int count=0;
    //make loop to itirate through all nodes of a
    for (temp_a=root_a; temp_a->next!=0; temp_a=temp_a->next) {
        //pick first node in a, compare with all nodes in b
        a = temp_a->val;
        for (temp_b=root_b;temp_b->next;temp_b=temp_b->next) {
            b = temp_b->val;
            if (a==b) {count+=1; break;}
        }
        if (count!=0) {
            printf("Both lists have at least %i in common", a);
            return 1;
        } 
    }
    if (count==0) {
        printf("Lists have nothing in common");
        return 0;
    }
    
}
