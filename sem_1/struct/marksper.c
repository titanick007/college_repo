#include <stdio.h>

typedef struct{
int rollno;
char name[25];
float chem_marks;
float maths_marks;
float phy_marks;
}RESULT;

RESULT input(){
RESULT U;
printf("Enter roll no.\n");
scanf("%d",&U.rollno);
printf("Enter name\n");
scanf("%s",U.name);
printf("Enter chem marks\n");
scanf("%f",&U.chem_marks);
printf("Enter maths marks\n");
scanf("%f",&U.maths_marks);
printf("Enter phy marks\n");
scanf("%f",&U.phy_marks);
return U;
}
int main(){
RESULT a,b,c,d,e;
printf("Enter the details of the 1st student\n");
a=input();
printf("Enter the details of the 2nd student\n");
b=input();
printf("Enter the details of the 3rd student\n");
c=input();
printf("Enter the details of the 4th student\n");
d=input();
printf("Enter the details of the 5th student\n");
e=input();
printf(" %s : %f\n",a.name,(a.chem_marks+a.maths_marks+a.phy_marks)/3);
printf(" %s : %f\n",b.name,(b.chem_marks+b.maths_marks+b.phy_marks)/3);
printf(" %s : %f\n",c.name,(c.chem_marks+c.maths_marks+c.phy_marks)/3);
printf(" %s : %f\n",d.name,(d.chem_marks+d.maths_marks+d.phy_marks)/3);
printf(" %s : %f\n",e.name,(e.chem_marks+e.maths_marks+e.phy_marks)/3);
return 0;
}

