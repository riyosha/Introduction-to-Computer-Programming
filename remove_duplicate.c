#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
	struct node* next;
} node;

node* remove_duplicate(node* root);
void printList(node* root);
void free_list(node* head);

int main() {
    node* root = (node*)malloc(sizeof(node));
    root->val=1;
    root->next=(node*)malloc(sizeof(node));
    root->next->val=2;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->val=2;
    root->next->next->next=NULL;
    

    root = remove_duplicate(root);
    printList(root);
    free_list(root);

}

node* remove_duplicate(node* root) {
    node* temp1 = root;
    node* temp2;
    //following program iterates through the entire linked list, sets each node as temp1 and compares its values with the subsequent nodes
    //if duplicate value is found, the latter one is deleted 
    while(temp1) {
        temp2=temp1;
        while(temp2&&temp2->next){
            if(temp2->next->val==temp1->val) {
                node* t =temp2->next;
                temp2->next=temp2->next->next;
                free(t);
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return root;
}

void printList(node* root) {
    node* p = root;
    do {
        printf(p==root?"%d":(p->next==root?", %d\n":", %d"), p->val);
        p = p->next;
    } while (p!= root);
}
void free_list(node* head) {

    while(head!=NULL){
        node* prev=head;
        head=head->next;
        free(prev);
    }
}