#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createlist(int size){
    struct node* head=NULL,*p,*temp;
    printf("Enter data\n");
    for(int i=0;i<size;++i){
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL) head=p;
        else temp->next=p;
        temp=p;
    }
    return head;
}
void traverse(struct node*head){
    struct node*p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    struct node* head=createlist(n);
    traverse(head);
    return 0;
}