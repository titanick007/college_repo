#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insertattail(struct node* head,int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        
    }
}