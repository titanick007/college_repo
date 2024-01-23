#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
void swap(int *a,int*b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void insert(int arr[],int n,int k){
    int i=n;
    arr[n+1]=k;
    while(i>1){
        if(arr[i/2]<arr[i]){
            swap(&arr[i],&arr[i/2]);
            i/=2;
        }
        else return;
    }
}
void deletemax(int arr[],int n){
    printf("%d ",arr[1]);
    arr[1]=arr[n];
    --n;
    int i=1,a;
    while(i<n){
        if(arr[2*i]>arr[2*i+1])a=2*i;
        else a=2*i+1;
        if(arr[i]<arr[a]){
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
    int maxheap[MAXSIZE];
    printf("Enter data\n");
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        insert(maxheap,i,k);
    }
    for(int i=1;i<=n;++i){
        printf("%d ",maxheap[i]);
    }
    printf("\n");
    for(int i=n;i>0;--i){
        deletemax(maxheap,n);
    }
    return 0;
}