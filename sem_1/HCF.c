#include <stdio.h>
int main()
{
    int a,b,r=0;
    printf("Enter two positive numbers\n");
    scanf("%d%d",&a,&b);
    if (a>b){
        r=b;b=a;a=r;
    }
    while (b%a!=0){
    r=b%a;
    b=a;
    a=r;
    }
    printf("The HCF = %d\n",a);
    return 0;
}
    