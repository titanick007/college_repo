#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* createlist(int size){
    struct node* head=NULL,*p,*temp;
    for(int i=0;i<size;++i){
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter a number\n");
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL) head=p;
        else temp->next=p;
        temp=p;
    }
    return head;
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
struct node* conc(struct node* head1,struct node* head2){
     if (head1 == NULL) {
        return head2;  
    }
    if (head2 == NULL) {
        return head1;  
    }
    struct node*temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}
int main(){
    int n1,n2;
    printf("Enter the size of each list\n");
    scanf("%d %d",&n1,&n2);
    struct node *head1,*head2;
    head1=createlist(n1);
    head2=createlist(n2);
    printf("List 1\n");
    traverse(head1);
    printf("List 2\n");
    traverse(head2);
    printf("Conatenated list\n");
    traverse(conc(head1,head2));
    return 0;
}