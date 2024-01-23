#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left,*right;
};
int max(int a,int b){
    if(a>=b)return a;
    else return b;
}
struct node* newnode(int k){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=k;
    temp->right=temp->left=NULL;
    return temp;
}
struct node*rotateleft(struct node*root){
    if(root->right==NULL)return root;
    else{
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        root->right=rotateleft(root->right);
        temp=root->right;
        temp->left=root;
        root=temp;
        return root;
    }
}
struct node*rotateright(struct node*root){
    if(root->left==NULL)return root;
    else{
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        root->left=rotateright(root->left);
        temp=root->left;
        temp->right=root;
        root=temp;
        return root;
    }
}
int height(struct node*root){
    if(root==NULL)return -1;
    else return 1+max(height(root->left),height(root->right));
}
struct node* insertavl(struct node*root,int k){
    if(root==NULL)return newnode(k);
    else if(k<root->data)root->left=insertavl(root->left,k);
    else if(k>root->data)root->right=insertavl(root->right,k);
    if(height(root->left)-height(root->right)<-1)rotateleft(root);
    else if(height(root->left)-height(root->right)>1)rotateright(root);
    return root;
}
void preorder(struct node*root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    printf("Enter data\n");
    struct node*root=NULL;
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        insertavl(root,k);
    }
    preorder(root);
    printf("\n"); 
    return 0;
}