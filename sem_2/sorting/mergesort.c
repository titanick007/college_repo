#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int lb,int mid,int ub){
    int n1=mid-lb +1;
    int n2=ub-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;++i){
        a[i]=arr[lb+i];
    }
    for(int i=0;i<n2;++i){
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=lb;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            ++i;
        }
        else{
            arr[k]=b[j];
            ++j;
        }
        ++k;
    }
    while(i<n1){
        arr[k]=a[i];
        ++i;++k;
    }
    while(j<n2){
        arr[k]=b[j];
        ++j;++k;
    }
}
void msort(int a[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;
        msort(a,lb,mid);
        msort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
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
    printf("Enter size fo array\n");
    scanf("%d",&n);
    int a[n];
    insert(a,n);
    msort(a,0,n-1);
    printarr(a,n);
    return 0;
}