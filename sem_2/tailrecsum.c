#include <stdio.h>
#include <stdlib.h>
int tailrecsum(int n,int rt){
    if(n==0) return rt;
    else return tailrecsum(n-1,rt+n);
}
int main(){
    int n;int rt=0;
    printf("Enter a natural number\n");
    scanf("%d",&n);
    printf("Sum of first %d natural numbers =%d\n",n,tailrecsum(n,rt));
    return 0;
}