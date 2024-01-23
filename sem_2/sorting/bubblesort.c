#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-1-i;++j){
            if(a[j]>a[j+1])swap(&a[j],&a[j+1]);
        }
    }
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}