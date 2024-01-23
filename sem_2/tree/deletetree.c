#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left,*right;
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
struct node* minvalue(struct node*root){
    if(root==NULL)return NULL;
    else {
        struct node*temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
}
struct node* deletenode(struct node*root,int k){
    if(root==NULL)return root;
    else if(k<root->data)root->left=deletenode(root->left,k);
    else if(k>root->data)root->right=deletenode(root->right,k);
    else{
        if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node*temp=root->left;
            free(root);
            return temp;
        }
        struct node*temp=minvalue(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
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
    printf("inorder\n");
    inorder(root);
    printf("\nEnter number to be deleted\n");
    scanf("%d",&k);
    root=deletenode(root,k);
    printf("inorder\n");
    inorder(root);
    printf("\n");
    return 0;
}