#include <stdio.h>
int sumd(int a){
    int sum;
    if (a<=10) return a;
    else return((a%10)+(sumd(a/10)));
}
int main(){
    int a;
    printf("Enter a number\n");
    scanf("%d",&a);
    printf("The sum of digits of %d is %d\n",a,sumd(a));
    return 0;
}