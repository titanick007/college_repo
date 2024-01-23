#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    if(2*i>n)return;
    int a;
    while(i>n/2){
        if(arr[2*i]>arr[2*i+1])a=2*i;
        else a=2*i+1;
        if(arr[i]<arr[a]){
            swap(&arr[a],&arr[i]);
            i=a;
        }
        else return;
}
}
void buildheap(int arr[],int n){
    int i=(n/2);
    while(i>=1){
        heapify(arr,n,i);
        --i;
    }
}
int main(){
    int n,k;
    printf("Enter size of list\n");
    scanf("%d",&n);
    printf("Enter data\n");
    int heap[MAXSIZE];
    for(int i=1;i<=n;++i){
        scanf("%d",&heap[i]);
    }
    buildheap(heap,n);
    printf("The heap is\n");
    for(int i=1;i<=n;++i){
        printf("%d ",heap[i]);
    }
    printf("\n");
    return 0;
}