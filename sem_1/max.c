#include <stdio.h>
int main()
{
    int x,y,max;
    printf("Enter two integers\n");
    scanf("%d%d",&x,&y);
    if (x>y)
    max=x;
    else
    max=y;
    printf("The Greater number is %d\n",max);
    return 0;
}