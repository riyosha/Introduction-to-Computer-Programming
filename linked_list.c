#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* add_at_beginning(node* root, int value);
node* add_at_end(node* root, int value);
node* add_after_node(node* root, node* node_a, int value);
node* delete_at_beginning(node* root);
node* delete_at_end(node* root); 
void search(node* root, int value, node* last);
void printList(node* root);
void freeLinkedList(node* root);
node* last_node(node* root);


int main(void) {
    node* root =(node*)malloc(sizeof(node*));
    root->val = 10;
    root->next=root;

    root = add_at_beginning(root, 5);
    root = add_at_end(root, 11);
    root = add_at_beginning(root, 4);
    root = add_after_node(root, root->next->next, 8);

    printf("Original list: ");
    printList(root);
    
    root = delete_at_end(root);
    root = delete_at_beginning(root);

    printf("List after deletion: ");
    printList(root);

    node* last = last_node(root);

    search(root, 8, last);
    search(root, 9, last);

    freeLinkedList(root);
    return 0;
}

node* add_at_beginning(node* root, int value) {
    node* temp = (node*)malloc(sizeof(node*));
    node* last = last_node(root);
    temp->val = value;
    //base case
    if(root==NULL) {temp=root; temp->next=root; return root;}
    //add root at beginning
    temp->next = root;
    root=temp;
    //adjust last node's pointer
    last->next=root;

    return root;
}

node* add_at_end(node* root, int value) {
    node* temp = (node*)malloc(sizeof(node*));
    node* last = last_node(root);
    temp->val = value;

    //base case
    if(root==NULL) {temp=root; temp->next=root; return root;}
    //last node points to new node
    last->next=temp;
    //new node points to the root
    temp->next=root;

    return root;
}

node* add_after_node(node* root, node* node_a, int value) {
    node* temp = (node*)malloc(sizeof(node*));
    temp->val = value;

    //base case
    if(root==NULL) {root=temp; temp->next=root; return root;}
    if(node_a==NULL) {node_a=temp; temp->next=root; return root;}
    //temp next points to node_a's next
    temp->next = node_a->next;
    //node_a next points to temp
    node_a->next=temp;

    return root;
}

node* last_node(node* root) {
    node* last = root;
    while(last->next!=root) {last=last->next;}
    return last;
}

node* delete_at_beginning(node* root) {
    node* temp = root;
    node* last = last_node(root);

    if (root==NULL) {return NULL;}
    //root->next becomes root
    if (temp->next) {
        temp=root->next;
        last->next=temp;
        root->next=NULL;
        free(root);
        return temp;
    } else {
        free(root);
        return NULL;
    }
    
}

node* delete_at_end(node* root) {
    node* last = last_node(root);
    node* second_last = root;

    if (root==NULL) {return NULL;}

    //find second_last last node
    while(second_last->next!=last) {second_last=second_last->next;}
    //second last points to root
    second_last->next=root;
    //free last node
    free(last);
    return root;
}

void search(node* root, int value, node* last) {
    if (root->val==value) {printf("Value present in list\n"); return;}
    else if (root==last) {printf("Value not found\n"); return;} 
    else {search(root->next, value, last);}
}

void printList(node* root) {
    node* p = root;
    do {
        printf(p==root?"%d":(p->next==root?", %d\n":", %d"), p->val);
        p = p->next;
    } while (p!= root);
}

void freeLinkedList(node* root) {
    node* temp, *prev = root;
    node* last = last_node(root);
    last->next = NULL;

    if (root==NULL) {return;}

    while(temp->next) {
        temp=temp->next;
        free(prev);
        prev=temp;
    }

    return;
}