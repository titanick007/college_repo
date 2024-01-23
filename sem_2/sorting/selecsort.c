#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    printf("Enter size of the array\n");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter numbers into the array\n");
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array\n");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<n;++i){
        int min=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<=arr[min]) min=j;
        }
        if(min!=i) swap(&arr[min],&arr[i]);
    }
    printf("Sorted array\n");
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0; 
}