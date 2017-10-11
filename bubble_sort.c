#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//Implements a single-linked list in C
//Implements the Node with its payload and pointer
struct Node{
    int value;
    //I need some way to reference each object from start to the last
    struct Node *next;
};

struct Node *first = NULL;



void iterate_list() {
    if(first == NULL)
        printf("The List is empty, nothing to iterate.\n");
    else{
        struct Node *reference;
        reference = first;
        while(reference != NULL) {
            printf(" (%d) ",reference->value);
            reference = reference->next;
        }
        printf("\n");
    }
}


void  delete_list() {
    struct Node *reference;
    while(first!=NULL) {
        reference = first;
        first = first->next;
        free(reference);
    }
}

int pop() {
    int tmp;
    struct Node *reference;
    reference = first;
    tmp = reference->value;
    first = first->next;
    free(reference);
    return tmp;
}


void push(int val) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->value = val;
    temp->next = first;
    first = temp;
}

int peek() {
    return first->value;
}

void swap(struct Node *prev, struct Node *cur) {
    int a = prev->value;
    prev->value = cur->value;
    cur->value = a;
}

void iterate_list_n(int n) {
    int i=0;
    if(first == NULL)
        printf("The List is empty, nothing to iterate.\n");
    else{
        struct Node *reference;
        reference = first;
        while(reference != NULL && i<n ) {
            printf(" (%d) ",reference->value);
            reference = reference->next;
            i++;
        }
        printf("\n");
    }
}

void swap_references(struct Node *prev, struct Node *temp) {
    /* TODO: First pointer needs a change
     * Tip: prev=NULL;
     */
    if(prev) {
        prev->next = temp->next;
        temp->next = prev->next->next;
        prev->next->next = temp;
    }
    else{
        first = temp->next;
        temp->next = temp->next->next;
        first->next = temp;
    }
   
}

void bubble_sort(int n) {
    struct Node *temp = first;
    struct Node *prev = NULL;
    for(int i=n; i>0; i--) {
        temp=first;
        prev=NULL;
        while(temp->next) {
            if(temp->value > temp->next->value){
                swap_references(prev,temp);
                if(prev)
                    prev = prev->next;
                else
                    prev = first;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
}

int main() {
    int n = 100000;
    time_t t;
    int i;
    srand((unsigned) time(&t));
    for( i = 0 ; i < n ; i++ ) {
        push(rand() % 200000);
    }
    printf("Not sorted :(\n");
    iterate_list();
    bubble_sort(n);
    printf("Sorted :) \n");
    iterate_list();
    delete_list();
    return 0;
}
