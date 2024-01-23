#include <stdio.h>
int main()
{
    int x,y,z,max;
    printf("Enter three integers\n");
    scanf("%d%d%d",&x,&y,&z);
    if (x>y)max=x;
    else max=y;
    if (max>z)printf("The greatest number is %d\n",max);
    else printf("The greatest number is %d\n",z);
    return 0;
}