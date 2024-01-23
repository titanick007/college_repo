#include <stdio.h>
int main()
{
    int days,y,m;
    printf("Enter no. of days\n");
    scanf("%d",&days);
    y=days/365;
    days=days%365;
    m=days/30;
    days=days%30;
    printf("%d years,%d months and %d days\n",y,m,days);
    return 0;
}