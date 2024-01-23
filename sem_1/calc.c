#include <stdio.h>
int main()
{
    int num1,num2;char op;/*taking input of two nos and operation*/
    printf("Enter the first operand\n");
    scanf("%d",&num1);
    printf("Enter the operation\n");
    scanf(" %c",&op);
    printf("Enter the second operand\n");
    scanf("%d",&num2);
    switch (op){
        case '+':printf("%d + %d = %d\n",num1,num2,num1+num2);break;
        case '-':printf("%d - %d = %d\n",num1,num2,num1-num2);break;
        case '*':printf("%d * %d = %d\n",num1,num2,num1*num2);break;
        case '/':printf("%d/%d = %f\n",num1,num2,(float)num1/num2);break;
        default:printf("Invalid input\n");break;
    }
    return 0;
}