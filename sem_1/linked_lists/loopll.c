#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insertattail(struct node* head, int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return ;
    }
    else{
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    }
}
void llprint(struct node* head){
    head=head->next;
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    struct node* head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the values\n");
    for(int i=0;i<n;++i){
        int b;
        scanf("%d",&b);
        insertattail(head,b);
    }
    
    llprint(head);
    return 0;
}