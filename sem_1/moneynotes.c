#include <stdio.h>
int main()
{
    int amt,fiveh,twoh,hund,fifty,twenty,ten,fivec,twoc;
    printf("Enter the amount of money\n");
    scanf("%d",&amt);
    fiveh=amt/500;
    amt=amt%500;
    twoh=amt/200;
    amt=amt%200;
    hund=amt/100;
    amt=amt%100;
    fifty=amt/50;
    amt=amt%50;
    twenty=amt/20;
    amt=amt%20;
    ten=amt/10;
    amt=amt%10;
    fivec=amt/5;
    amt=amt%5;
    twoc=amt/2;
    amt=amt%2;
    printf("There is %d $500 notes, %d $200 notes, %d $100 notes, %d $50 notes, %d $20 notes, %d $10 notes, %d $5 coins, %d $2 coins,%d $1 coins\n",fiveh,twoh,hund,fifty,twenty,ten,fivec,twoc,amt);
    return 0;
}