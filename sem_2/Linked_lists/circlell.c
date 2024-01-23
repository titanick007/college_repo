#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createlist(int size){
    struct node* head,*p,*temp;
    for(int i=0;i<size;++i){
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL) head=p;
        else temp->next=p;
        temp=p;
    }
}
void circlell(struct node* head){
    struct node* p;
    p=head;
    while(p!=NULL)p=p->next;
    p->next=head;
}
void traverse(struct node* head){
    struct node* p;
    p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the size of the list\n");
    scanf("%d",&n);
    printf("Enter data into the list\n");
    struct node* head;
    head=createlist(n);
    printf("Normal list\n");
    traverse(head);
    circlell(head);
    printf("Circular list\n");
    struct node*p1=head;
    for(int i=0;i<(n*2)+1&&p1!=NULL;++i){
        printf("%d ",p1->data);
        p1=p1->next;
    }
    printf("\n");
    return 0;
}