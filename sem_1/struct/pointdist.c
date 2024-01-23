#include <stdio.h>
#include <math.h>
typedef struct {
float x;
float y;
}POINT;
POINT input(){
POINT U;
printf("Enter x coordinate\n");
scanf("%f",&U.x);
printf("Enter y coordinate\n");
scanf("%f",&U.y);
return U;
}
double dist(POINT a,POINT b){
double d=sqrt((pow((a.x-b.x),2)+pow((a.y-b.y),2)));
return d;
}
int main(){
POINT p1,p2;
printf("Enter the coordinates of first point\n");
p1=input();
printf("Enter the coordiantes of the second point\n");
p2=input();
printf("The distance between the points is %lf\n",dist(p1,p2));
return 0;
}

