#include <stdio.h>
#include <stdlib.h>
void binary(int num,int arr[16],int size){
    for(int i=size-1;i>=0;--i){
        if(num<2) {arr[i]=num;num=num/2;}
        else {
            arr[i]=num%2;
            num=num/2;
        }
    }
}
void comp1(int arr[16],int size,int a[16]){
    for(int i=0;i<size;++i){
        if(arr[i]==1)a[i]=0;
        else a[i]=1;
    }
}
void binadd(int a1[16],int a2[16],int sum[16],int size){
    int carry=0;
    for(int i=size-1;i>=0;--i){
       sum[i]=(~a1[i]&&a2[i])||(a1[i]&&~a2[i]);
       carry=a1[i]&&a2[i];
    }
}
int main(){
    int n,m;int size=16;
    printf("Enter first number\n");
    scanf("%d",&n);
    printf("Enter second number\n");
    scanf("%d",&m);
    int bin1[16];
    binary(n,bin1,size);
    printf("%d in binary form is ",n);
    for(int i=0;i<size;++i)printf("%d",bin1[i]);
    printf("\n");
    int bin2[16];
    binary(m,bin2,size);
    printf("%d in binary form is ",m);
    for(int i=0;i<size;++i)printf("%d",bin2[i]);
    printf("\n");
    //comp1(bin1,size,co1);
    //printf("1's complement ");
    //for(int i=0;i<size;++i)printf("%d",co1[i]);
   // printf("\n");
    int sum[16];
    binadd(bin1,bin2,sum,size);
    printf("sum of two binary numbers is ");
    for(int i=0;i<size;++i)printf("%d",sum[i]);
    printf("\n");
    return 0;
}