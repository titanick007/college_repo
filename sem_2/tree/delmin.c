#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
struct node* newnode(int k){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insert(struct node*root,int k){
    if(root==NULL){
       return newnode(k);
    }
    if(k<=root->data)root->left=insert(root->left,k);
    else if(k>root->data)root->right=insert(root->right,k);
    return root;
}
void inorder(struct node*root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node*root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int minval(struct node*root){
    if(root==NULL){
        printf("Error\n");
        return 0;
    }
    struct node*temp=root;
    while(temp->left!=NULL)temp=temp->left;
    return temp->data;
}
struct node* delmin(struct node*root,int k){
    if(root==NULL)return root;
    else if(k<root->data)root->left=delmin(root->left,k);
    else if(k>root->data)root->right=delmin(root->right,k);
    else{
        if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else{
            free(root);
            return root;
        }
    }
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
    for(int i=0;i<n-1;++i){
        int min=minval(root);
        root=delmin(root,min);
        inorder(root);
        printf("\n");  
    }
    return 0;
}