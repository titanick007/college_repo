#include <stdio.h>
#include <stdlib.h>
void insert(int arr[],int n){
    printf("Enter numbers into array\n");
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    insert(arr,n);
    printf("Unsorted array\n");
    printarr(arr,n);
    for(int i=0;i<n;++i){
        int temp=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>=temp){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=temp;
    }
    printf("Sorted array\n");
    printarr(arr,n);
    return 0;
}