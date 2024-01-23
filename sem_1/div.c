#include <stdio.h>
int main()
{
    int a;
    printf(" Enter a natural number\n");
    scanf("%d",&a);
    if(a%2==0)
    printf(" is not divisible by 2 \n");
    else
        printf("%d",a," is not divisible by 2 \n");
    return 0;
}
