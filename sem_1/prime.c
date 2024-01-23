#include <stdio.h>
#include <math.h>
int main()
{
    int n, i=2,flag=0;
    printf("Enter a positive number\n");
    scanf("%d",&n);
    double limit=sqrt(n);
    while(i<=limit){
        if (n%i==0){
            printf("%d is not a prime number\n",n);
            flag=1;break;
        }
        i=i+1;
    }
    if (flag==0) printf("%d is a prime number\n",n);
    return 0;
}