#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void llprint(struct node* head){
    while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
    }
}
int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    int n;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=3;
    head->next=second;
    second->data=5;
    second->next=third;
    third->data=2;
    third->next=NULL;
    llprint(head);
    return 0;
}
    