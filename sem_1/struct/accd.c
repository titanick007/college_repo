#include <stdio.h>
typedef struct{
    char name[25];
    long int accno;
    int bal;
}ACCOUNT;
ACCOUNT input(){
    ACCOUNT a;
    printf("Enter name\n");
    scanf(" %s",a.name);
    printf("Enter account number\n");
    scanf("%ld",&a.accno);
    printf("Enter account balance\n");
    scanf("%d",&a.bal);
    return a;
}
void checkbal1(ACCOUNT a){
    if (a.bal<200) printf("%s\n",a.name);
}
void checkbal2(ACCOUNT a){
    if (a.bal>1000) printf("%s : $%d\n",a.name,a.bal+100);
}
int main()
{
    ACCOUNT a1,a2,a3,a4,a5;
    a1=input();
    a2=input();
    a3=input();
    a4=input();
    a5=input();
    printf("list of accounts with less than $200 balance\n");
    checkbal1(a1);
    checkbal1(a2);
    checkbal1(a3);
    checkbal1(a4);
    checkbal1(a5);
    printf("list of accounts with more than $1000 balance\n");
    checkbal2(a1);
    checkbal2(a2);
    checkbal2(a3);
    checkbal2(a4);
    checkbal2(a5);
    return 0;
}