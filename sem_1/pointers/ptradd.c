#include <stdio.h>
int main(){
    int a,b,c;
    int *p1,*p2,*p3;
    printf("Enter two nos\n");
    scanf("%d%d",&a,&b);
    p1=&a;
    p2=&b;
    p3=&c;
    *p3=*p1+*p2;
    printf("p1 =%d\n",p1);
    printf("p2 =%d\n",p2);
    printf("p3 =%d\n",p3);
    printf("a + b= %d\n",*p3);
    return 0;
}