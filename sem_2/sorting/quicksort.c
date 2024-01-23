#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int split(int a[],int lb,int ub){
    int start=lb,end=ub;
    while(start<end){
        while(a[start]<=a[lb]){
            ++start;
        }
        while(a[ub]>a[lb]){
            --end;
        }
        if(start<end) swap(&a[start],&a[end]);
    }
    swap(&a[lb],&a[end]);
    return end;
}
void qsort(int a[],int lb,int ub){
    if(lb<ub){
        int temp=split(a,lb,ub);
        qsort(a,lb,temp-1);
        qsort(a,temp+1,ub);
    }
    else return;
}
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter data\n");
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    qsort(a,0,n-1);
    for(int i=0;i<n;++i)printf("%d ",a[i]);
    printf("\n");
    return 0;
}