#include <stdio.h>
#include <stdlib.h>
void binary(int a){
    if(a==0||a==1){
        printf("%d",a);
        return;
    }
    binary(a/2);
    printf("%d",a%2);
    return;
}
int main(){
    int a;
    printf("Enter an integer\n");
    scanf("%d",&a);
    printf("The binary form of %d is ",a);
    binary(a);
    printf("\n");
    return 0;
}