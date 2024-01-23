#include <stdio.h>
int fib(int n){
    if(n==0) return 1;
    else if (n==1) return 1;
    else{
        for(int i=1;i<=n;++i){
            printf("%d",fib(n-1)+fib(n-2));
            return (fib(n-1)+fib(n-2));
        }
    }
}
int main(){
    int n; 
    printf("Enter the no. of terms\n");
    scanf("%d",&n);
    printf("%d ",fib(n));
    printf("\n");
    return 0;
}