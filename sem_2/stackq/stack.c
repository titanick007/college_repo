#include <stdio.h>
#include <stdlib.h>
#define max 10000
struct st{
    int arr[max];
    int top;
};
typedef struct st stack;
void push(stack* s,int k){
    if(s->top<max){
        (s->top)++;
        s->arr[s->top]=k;
    }
    else printf("Error\n");
}
void pop(stack* s){
    if(s->top>-1){
        printf("%d\n",s->arr[s->top]);
        (s->top)--;
    }
    else printf("Error\n");
}
int main(){
    int n,k;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    stack s1;s1.top=-1;
    printf("Enter data\n");
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        push(&s1,k);
    }
    pop(&s1);
    return 0;
}