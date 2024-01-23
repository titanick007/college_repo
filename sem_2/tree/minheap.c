#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insert_minheap(int arr[],int n,int k){
    int i=n+1;
    arr[n+1]=k;
    while(i>1){
        if(arr[i/2]>arr[i]){    
            swap(&arr[i],&arr[i/2]);
            i=i/2;
        }
        else return ;
    }
}
void deletemin(int arr[],int n){
    arr[1]=arr[n];
    --n;
    int i=1,a;
    while(i<n){
        if(arr[2*i]<arr[2*i+1])a=2*i;
        else a=2*i+1;
        if(arr[i]>arr[a]){
            swap(&arr[i],&arr[a]);
            i=a;
        }
        else{
            arr[n+1]=0;
            return;
        }
    }
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    int minheaparr[MAX_SIZE];
    printf("Enter data\n");
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        insert_minheap(minheaparr,i,k);
    }
    for(int i=1;i<=n;++i){
        printf("%d ",minheaparr[i]);
    }
    printf("\n");
    deletemin(minheaparr,n);
    --n;
    for(int i=1;i<=n;++i){
        printf("%d ",minheaparr[i]);
    }
    printf("\n");
    return 0;
}