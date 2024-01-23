#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
typedef struct node list;
typedef list* nptr;
nptr createnode(int k){
    nptr temp=(nptr)malloc(sizeof(list));
    temp->data=k;
    temp->next=NULL;
    return temp;
}
nptr insertorder(nptr head,int k){
    nptr temp,prev,p;
    temp=createnode(k);
    if(head==NULL||k<=head->data){
        temp->next=head;
        return temp;
    }
    else{
        p=head;
        prev=p;
        p=p->next;
        while(p!=NULL&&k>p->data){
            prev=p;
            p=p->next;
        }
        prev->next=temp;
        temp->next=p;
        return head;
    }
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
void printreverse(nptr head){
    if(head==NULL)return;
    else{
        printreverse(head->next);
        printf("%d ",head->data);
    }
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    nptr head=NULL;
    printf("Enter data\n");
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(n==0) head=createnode(k);
        else head=insertorder(head,k);
    }
    printf("ordered list\n");
    traverse(head);
    printf("Reverse list\n");
    printreverse(head);
    printf("\n");
    return 0;
}