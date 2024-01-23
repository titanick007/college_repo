#include <stdio.h>
int main()
{
int a,b,c,d,min;
printf("Enter four integers\n");
scanf("%d%d%d%d",&a,&b,&c,&d);
if(a>b) min=b;
else min=a;
if(min>c) min=c;
if(min>d) min=d;
printf("The smallest number is %d\n",min);
return 0;
}