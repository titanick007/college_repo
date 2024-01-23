#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *leftc;
    struct node *rightc;
};

struct node *find(struct node *temp, int B){
    if (temp == NULL)return NULL;
    else{
        if (temp->data == B) return temp;
        else{
            if (temp->data > B){
                if (temp->leftc == NULL)return temp;
                else return find(temp->leftc, B);
            }
            else{
                if (temp->rightc == NULL) return temp;
                else return find(temp->rightc, B);
            }
        }
    }
}
void insert(struct node **root, int val){
    struct node *x = find(*root, val);
    if (x == NULL){
        struct node *y = (struct node *)malloc(sizeof(struct node));
        y->data = val;
        y->leftc = y->rightc = NULL;
        *root = y;
    }
    else if (x->data > val){
        struct node *y = (struct node *)malloc(sizeof(struct node));
        y->data = val;
        y->leftc = y->rightc = NULL;
        x->leftc = y;
    }
    else{
        struct node *y = (struct node *)malloc(sizeof(struct node));
        y->data = val;
        y->leftc = y->rightc = NULL;
        x->rightc = y;
    }
}

void inorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->leftc);
    printf("%d ", root->data);
    inorder(root->rightc);
}
// counting the number of nodes recursively
static int c = 0;
int count_recursive(struct node *root){
    if (root != NULL){
        count_recursive(root->leftc);
        c++;
        count_recursive(root->rightc);
    }
    return c;
}
// count number of nodes non recursively
int countNodes(struct node *root){
    if (root == NULL)
        return 0;

    int count = 0;
    struct node *stack[100]; // Assuming the maximum number of nodes in the tree is 100
    int top = -1;
    struct node *current = root;

    while (current != NULL || top != -1){
        while (current != NULL){
            stack[++top] = current;
            current = current->leftc;
        }
        current = stack[top--];
        count++;
        current = current->rightc;
    }
    return count;
}
// finding sum of nodes recursively
int sumOfNodes(struct node *root){
    if (root == NULL) return 0;
    else return root->data + sumOfNodes(root->leftc) + sumOfNodes(root->rightc);
}
// finding sum of nodes non recursively
int sumNodes(struct node *root){
    if (root == NULL) return 0;
    int sum = 0;
    struct node *stack[100]; // Assuming the maximum number of nodes in the tree is 100
    int top = -1;
    struct node *current = root;
    while (current != NULL || top != -1){
        while (current != NULL){
            stack[++top] = current;
            current = current->leftc;
        }

        current = stack[top--];
        sum += current->data;
        current = current->rightc;
    }
    return sum;
}
// compute depth recursively
int computedepth(struct node *root){
    if (root == NULL) return 0;
    int leftDepth = computedepth(root->leftc);
    int rightDepth = computedepth(root->rightc);

    if (leftDepth > rightDepth)return leftDepth + 1;
    else return rightDepth + 1;
}
int main(){
    struct node *root = NULL;
    printf("enter number of elements in the list: ");
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(&root, a[i]);
    }
    inorder(root);
    int x = count_recursive(root);
    int x1 = countNodes(root);
    int sum = sumOfNodes(root);
    int sum1 = sumNodes(root);
    int depth = computedepth(root);
    printf("\nnumber of nodes in tree is(printed recursively): %d", x);
    printf("\nnumber of nodes in tree is(printed non-recursively): %d", x1);
    printf("\nsum of nodes(recursively): %d", sum);
    printf("\nsum of nodes(non recursively): %d", sum1);
    printf("\ndepth of tree is: %d", depth);
    return 0;
}
