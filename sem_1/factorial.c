#include <stdio.h>
int main()
{
    int n,fact=1,count=1;
    printf("Enter a natural number\n");
    scanf("%d",&n);
    while (count<=n){
        fact=fact*count;
        count=count+1;
    }
    printf("factorial of %d is %d\n",n,fact);
    return 0;
}