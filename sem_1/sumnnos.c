#include <stdio.h>
int main()
{
    int n,sum=0,count=1;
    printf("Enter the no. of natural numbers\n");
    scanf("%d",&n);
    while (count<=n){
    sum=sum+count;
    count=count+1;
    }
    printf("The sum of first %d natural numbers=%d\n",n,sum);
    return 0;
}