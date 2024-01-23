#include <stdio.h>
#include <math.h>
int gx(int x){
if (x==1) return (6);
if (x>1) {
int f=floor((float)x/2);
return(4*gx(f)+x);
}
if(x<1) {
printf("Invalid input\n");
}
}
int fx(int a){
int m=pow(10,9)+7;
return(gx((int)pow(2,a))%m);
}
int main(){
int a;
printf("Enter a number\n");
scanf("%d",&a);
printf("f(%d) = %d\n",a,fx(a));
return 0;
}