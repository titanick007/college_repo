#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main(){
    int n;
    printf("Enter size of string\n");
    scanf("%d",&n);
    char string[n];
    printf("Enter strings containing a and b");
    for(int i=0;i<n;++i)scanf("%c ",&string[i]);
    int states;
    printf("Enter no. of states\n");
    scanf("%d",&states);
    struct node *nfa [states][2];
    for(int i=0;i<states;++i){
        for(int j=0;j<2;++j){
            
        }
    }
    int cstate=0;
    int fstate=3;
    int currentstate[];
    for(int i=0;i<n;++i){
        int symbol=string[i]-'a';
        currentstate[i]=nfa[cstate][symbol];
    }
    int i=0;
    while(currentstate!=NULL){
        if()
    }
    return 0;
}
