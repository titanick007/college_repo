#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
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
void insert(struct node**head,int pos){
    struct node* temp;
    temp=*head;
    struct node* p=(struct node*)malloc(sizeof(struct node));
    printf("Enter the number\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(pos==1){
        p->next=*head;
        *head=p;
    }
    else{
        int i=1;
        while(temp->next!=NULL){
            if(i==pos-1)break;
            else temp=temp->next;
            ++i;
        }
        if(pos>i+1)printf("invalid position\n");
        else if(temp->next==NULL){
            temp->next=p;
        }
        else{
            p->next=temp->next;
            temp->next=p;
        }
    }
}
void printl(struct node*head){
    struct node* p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter size of list\n");
    scanf("%d",&n);
    struct node* head=createlist(n);
    int pos,key;
    printf("Enter position\n");
    scanf("%d",&pos);
    printf("original list\n");
    printl(head);
    insert(&head,pos);
    printf("new list\n");
    printl(head);
    return 0;
}