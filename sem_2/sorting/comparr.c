#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectsort(int arr[],int n){
    int min=0;
    for(int i=0;i<n;++i){
        int min=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<=arr[min]) min=j;
        }
        if(min!=i) swap(&arr[min],&arr[i]);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int s,t,n;
    printf("Enter size of two arrays\n");
    scanf("%d %d",&s,&t);
    n=s+t;
    int a[s];
    int b[t];
    printf("Enter numbers into first array\n");
    for(int i=0;i<s;++i){
        scanf("%d",&a[i]);
    }
    printf("Enter numbers into second array\n");
    for(int i=0;i<t;++i){
        scanf("%d",&b[i]);
    }
    selectsort(a,s);
    selectsort(b,t);
    printf("The sorted arrays\n");
    printarr(a,s);
    printf("\n");
    printarr(b,t);
    int count=0,i=0,j=0;
    for(i=0,j=0;i<s&&j<t;){
        if(a[i]>b[j]){
            count=count+(s-i);
            ++j;
        }
        else
        ++i;
    }
    printf("The number of pairs of (a[i],b[j]) for which a[i]>b[j] is %d\n",count);
    return 0;
}