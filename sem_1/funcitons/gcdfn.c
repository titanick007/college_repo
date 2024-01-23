#include <stdio.h>
int gcd(int a,int b){
    int r,i;
    if(a>b){
        r=a;
        a=b;
        b=r;
    }
    while(b%a!=0)
    {
        r=b%a;
        b=a;
        a=r;
    }
    return r;
}
int main()
{
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d%d",&a,&b);
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    return 0;
}