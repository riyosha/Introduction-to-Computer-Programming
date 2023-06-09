#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct node {
    char* name;
    struct node* next;
} node;

node* create_node(char* new_name);
node* new_nodePosition_FirstName(node* root, node* new_node);
node* new_nodePosition_LastName(node* root, node* new_node);
node* insertBy_FirstName(node* root, node* new_node);
node* insertBy_LastName(node* root, node* new_node);
node* delete(node** root, char* name);
int  compare_string_lex(char* A, char* B);
void print_list(node* root);
void free_list(node* head);

int main(void) {
    //nodes for first names 
    node* root = (node*)malloc(sizeof(node));
    root->name = "Becky Smith Aaron";
    root->next = NULL;

    node* n1 = (node*)malloc(sizeof(node));
    n1->name = "Reha Gupta Diwan";
    n1->next = NULL;

    node* n2 = (node*)malloc(sizeof(node));
    n2->name = "Aasha Max Bhosle";
    n2->next = NULL;
    
    node* n3 = (node*)malloc(sizeof(node));
    n3->name = "Zehnab Tista Raina";
    n3->next = NULL;

    node* n4 = (node*)malloc(sizeof(node));
    n4->name = "Xavier Jaish Kumar";
    n4->next = NULL;

    //nodes for last names 
    node* root1 = (node*)malloc(sizeof(node));
    root1->name = "Becky Smith Aaron";
    root1->next = NULL;

    node* l1 = (node*)malloc(sizeof(node));
    l1->name = "Reha Gupta Diwan";
    l1->next = NULL;

    node* l2 = (node*)malloc(sizeof(node));
    l2->name = "Aasha Max Bhosle";
    l2->next = NULL;
    
    node* l3 = (node*)malloc(sizeof(node));
    l3->name = "Zehnab Tista Raina";
    l3->next = NULL;

    node* l4 = (node*)malloc(sizeof(node));
    l4->name = "Xavier Jaish Kumar";
    l4->next = NULL;

    root = insertBy_FirstName(root, n3);
    root = insertBy_FirstName(root, n1);
    root = insertBy_FirstName(root, n2);
    root = insertBy_FirstName(root, n4);
    
    printf("List by first name: \n");
    print_list(root);


    root1 = insertBy_LastName(root1, l3);
    root1 = insertBy_LastName(root1, l1);
    root1 = insertBy_LastName(root1, l2);
    root1 = insertBy_LastName(root1, l4);

    printf("\nList by last name: \n");
    print_list(root1);

    root = delete(&root, "Reha Gupta Diwan");
    printf("\n\nNew list (by first name):\n");
    //please use delete function with root1 to test it with lastname list
    print_list(root);

    free_list(root);

}

node* create_node(char* new_name) {
    node* temp = (node*)malloc(sizeof(node*));
    temp->name = new_name;
    temp->next = NULL;
    return temp;
}

node* new_nodePosition_FirstName(node* root, node* new_node){
    node* prev = root;
    node* temp=prev->next;
    //base case, if new name lex smaller than root, will be considered in insertion
    //compare new name with temp->name
    if (temp) {
        int x = compare_string_lex(temp->name, new_node->name);
        //if lexically greater, compare with temp->next
        if (x==2) {
            if (temp->next) {new_nodePosition_FirstName(temp, new_node);}
            if (!temp->next) {return temp;}
        }
        //if lexically smaller, return prev
        else if (x==1) {
            return prev;
        }
        else {return NULL;}
    }
    if (!temp) {
        int x = compare_string_lex(prev->name, new_node->name);
        if (x==2) {
            return root;
        }
    }
}

node* insertBy_FirstName (node* root, node* new_node) {
    
    if (compare_string_lex(root->name, new_node->name)==1) {
        new_node->next=root;
        root=new_node;
        return root;
    }

    node* new_nodePos = new_nodePosition_FirstName(root, new_node);

    //insert new_node after new_nodePos
    new_node->next=new_nodePos->next;
    new_nodePos->next = new_node;
    return root;

}


node* new_nodePosition_LastName(node* root, node* new_node) {
    
    node* prev = root;
    node* temp=prev->next;

    //base case, if new name lex smaller than root, will be considered in insertion
    //compare new name with temp->name
    if (temp) {

        char* t_last = (char*)malloc(100 * sizeof(char));
        char* n_last = (char*)malloc(100 * sizeof(char));

        //find starting position of Last name
        int t_last_pos = 0;
        int n_last_pos = 0;
        while(temp->name[t_last_pos]!=' ') {t_last_pos++;}
        t_last_pos+=1;
        while(temp->name[t_last_pos]!=' ') {t_last_pos++;}
        t_last_pos+=1;
        while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
        n_last_pos+=1;
        while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
        n_last_pos+=1;

        //make new strings with just last names 
        for (int i = 0; t_last_pos+i-1<strlen(temp->name);i++) {
            t_last[i] = temp->name[t_last_pos+i];
        }
        for (int i = 0; n_last_pos+i-1<strlen(new_node->name);i++) {
            n_last[i] = new_node->name[n_last_pos+i];
        }

        int x = compare_string_lex(t_last, n_last);
        //if lexically greater, compare with temp->next
        if (x==2) {
            if (temp->next) {new_nodePosition_LastName(temp, new_node);}
            if (!temp->next) {return temp;}
        }
        //if lexically smaller, return prev
        else if (x==1) {
            return prev;
        }
        else {return NULL;}
    }
    if (!temp) {
        temp=prev;
        char* t_last = (char*)malloc(100 * sizeof(char));
        char* n_last = (char*)malloc(100 * sizeof(char));

        //find starting position of Last name
        int t_last_pos = 0;
        int n_last_pos = 0;
        while(temp->name[t_last_pos]!=' ') {t_last_pos++;}
        t_last_pos+=1;
        while(temp->name[t_last_pos]!=' ') {t_last_pos++;}
        t_last_pos+=1;
        while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
        n_last_pos+=1;
        while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
        n_last_pos+=1;

        //make new strings with just last names 
        for (int i = 0; t_last_pos+i-1<strlen(temp->name);i++) {
            t_last[i] = temp->name[t_last_pos+i];
        }
        for (int i = 0; n_last_pos+i-1<strlen(new_node->name);i++) {
            n_last[i] = new_node->name[n_last_pos+i];
        }

        int x = compare_string_lex(t_last, n_last);
        if (x==2) {
            return root;
        }
    }
}

int compare_string_lex(char* A, char* B) {
    char* a = (char*)malloc(100 * sizeof(char)); 
    char* b = (char*)malloc(100 * sizeof(char));

    //convert word to lowercase
    for (int j=0; A[j]!='\0'; j++) {a[j] = tolower(A[j]);}
    for (int j=0; B[j]!='\0'; j++) {b[j] = tolower(B[j]);}

    int i;
    //x lexicographically greater then y means x comes after y
    //compare each character, return 1 if a lexicographically greater, return 2 if b greater
    for (i=0; a[i]!='\0' || b[i]!='\0'; i++) {
        if (a[i]>b[i]) {return 1;}
        else if (a[i]<b[i]) {return 2;}
    }
    //comparing length of two strings 
    if(a[i]!='\0') {return 1;}
    else if(b[i]!='\0') {return 2;}
    else {return 0;}
}

node* insertBy_LastName (node* root, node* new_node) {

    char* r_last = (char*)malloc(100 * sizeof(char));
    char* n_last = (char*)malloc(100 * sizeof(char));

    //find starting position of Last name
    int r_last_pos = 0;
    int n_last_pos = 0;
    while(root->name[r_last_pos]!=' ') {r_last_pos++;}
    r_last_pos+=1;
    while(root->name[r_last_pos]!=' ') {r_last_pos++;}
    r_last_pos+=1;  
    while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
    n_last_pos+=1;
    while(new_node->name[n_last_pos]!=' ') {n_last_pos++;}
    n_last_pos+=1;

    //make new strings with just last names 
    for (int i = 0; r_last_pos+i-1<strlen(root->name);i++) {
        r_last[i] = root->name[r_last_pos+i];
    }
    for (int i = 0; n_last_pos+i-1<strlen(new_node->name);i++) {
        n_last[i] = new_node->name[n_last_pos+i];
    }

    //base case - if new_node_name smaller than root
    if (compare_string_lex(r_last, n_last)==1) {
        new_node->next=root;
        root=new_node;
        return root;
    }

    node* new_nodePos = new_nodePosition_LastName(root, new_node);

    //insert new_node after new_nodePos
    new_node->next=new_nodePos->next;
    new_nodePos->next = new_node;
    return root;

}

node* delete(node** root, char* name) {
    node* temp;
    //base case, if name is in the root node
    if (strcmp((*root)->name,name)==0) {
        temp = *root;
        *root=((*root)->next);
        free(temp);
        printf("%s deleted", name);
        return *root;
    } else {
        //if name is in current->next, then current->next points to current->next->next
        //current->next is freed
        //we itirate through th elist to check all nodes
        node* current = *root;
        while(current->next) {
            if (strcmp(current->next->name,name)==0) {
                temp=current->next;
                current->next=temp->next;
                free(temp);
                printf("\n%s deleted\n", name);
                return *root;
            } else {current=current->next;}
        }
        if (!current->next) {
            printf("\nName not found\n");
            return *root;
        }
    }
}

//helper function to print list
void print_list(node* root) {
    node* temp = root;
    while(temp!=NULL) {
        printf("%s\n", temp->name);
        temp=temp->next;
    }
}

void free_list(node* head) {

    while(head!=NULL){
        node* prev=head;
        head=head->next;
        free(prev);
    }
}