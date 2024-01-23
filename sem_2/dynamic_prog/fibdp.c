#include <stdio.h>
#include <stdlib.h>
int val[1000];
int fib(int n){
    if(n==1||n==2){
        val[n]=1;
        return val[n];
    }
    else{
        if(val[n]==0)val[n]=fib(n-1)+fib(n-2);
        return val[n];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%dth term in fib series is %d\n",n,fib(n));
    return 0;
}