#include <stdio.h>
#include <stdlib.h>
// binary tree
struct node{
    int data;
    struct node*left,*right;
};
// lcrs structure
struct lcrs{
    int data;
    struct lcrs *lc,*rs;
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
struct lcrs* newlcrs(int k){
    struct lcrs*temp=(struct lcrs*)malloc(sizeof(struct lcrs));
    temp->data=k;
    temp->lc=NULL;
    temp->rs=NULL;
    return temp;
}
void postorder(struct node*root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
//converts binary tree to lcrs
struct lcrs* convert(struct node* root){
    if(root==NULL)return NULL;
    struct lcrs*temp=newlcrs(root->data);
    if(root->left!=NULL) {
        temp->lc=convert(root->left);
        temp->lc->rs=convert(root->right);
    }
    else if(root->right!=NULL) temp->lc=convert(root->right);
    return temp;
}
// traverses lcrs same as postorder
void traverselcrs(struct lcrs* tree){
    if(tree==NULL) return;
    traverselcrs(tree->lc);
    printf("%d ",tree->data);
    traverselcrs(tree->rs);
}
int main(){
    int n,k;
    struct node*bint=NULL;
    printf("Enter size of list\n");
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(i==0)bint=newnode(k);
        else insert(bint,k);
    }
    struct lcrs* tree=NULL;
    tree=convert(bint);
    printf("POSTORDER\n");
    postorder(bint);
    printf("\n");
    printf("traverse tree\n");
    traverselcrs(tree);
    printf("\n");
    if(tree->rs==NULL) printf("correct\n");
    return 0;
}