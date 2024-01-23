#include <stdio.h>
typedef struct{
    int day;
    int month;
    int year;
}Date;
Date input(){
    Date a;
    printf("Enter the day(1-30)\n");
    scanf("%d",&a.day);
    printf("Enter the month(1-12)\n");
    scanf("%d",&a.month);
    printf("Enter the year\n");
    scanf("%d",&a.year);
    return a;
}
int main(){
    Date d1,d2;
    d1=input();
    d2=input();
    int flag=0;
    if (d1.day==d2.day){
        if (d1.month==d2.month){
            if(d1.year==d2.year) flag=1;
        }
    }
    if(flag==1) printf("Dates are equal\n");
    else printf("Dates are not equal\n");
}