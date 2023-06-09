#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void detect_circular_linked_list(node* root);

int main(void) {
        
    //sample manually made linked-list for testing
    node* head = NULL;
    node* node2 = NULL;
    node* node3 = NULL;

    head = malloc(sizeof(node));
    node2 = malloc(sizeof(node));
    node3 = malloc(sizeof(node));

    head->val = 1;
    head->next=node2;
    node2->val=2;
    node2->next=node3;
    node3->val=3;
    node3->next=NULL;

    detect_circular_linked_list(head);
}

void detect_circular_linked_list(node* root) {
    node* temp = root;
    //traverse through list and check if node->next = root
    for(temp; temp->next!=NULL&&temp->next!=root; temp=temp->next);
    //if node->next = root link is circular
    //if node->next = NULL link i not circular
    if (temp->next==NULL) {
        printf("List is not circular");
        return;
    } 
    if (temp->next==root) {
        printf("List is circular");
        return;
    }

}
