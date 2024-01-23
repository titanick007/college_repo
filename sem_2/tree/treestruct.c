#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*right,*left;
};
struct node* newnode(int k){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=k;
    temp->right=temp->left=NULL;
    return temp;
}
struct node* insert(struct node*root,int k){
    if(root==NULL){
        return newnode(k);
    }
    if(k<=root->data)root->left=insert(root->left,k);
    else root->right=insert(root->right,k);
    return root;
}
void inorder(struct node*root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    struct node*root=NULL;
    printf("Enter data\n");
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(i==0)root=newnode(k);
        else insert(root,k);
    }
    inorder(root);
    printf("\n");
    return 0;
}

