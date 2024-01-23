#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void llprint(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
int main(){
    int n;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    struct node* head;
    struct node* temp;
    struct node* newnode;
    head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
    printf("Enter no. of elements\n");
    for(int i=0;i<n;++i){
        if(head==NULL){
            scanf("%d",&head->data);
            head=temp;
            head->next=newnode;
        }
        else{
            scan("%d",&head->data);
            head=temp;
            head->
        }
    }
    return 0;
}