#include <stdio.h>
#include <math.h>
typedef struct{
    float x;
    float y;
}point;
point input(){
    point a;
    printf("enter x coordinate\n");
    scanf("%f",&a.x);
    printf("Enter y coordinate\n");
    scanf("%f",&a.y);
    return a;
}
float dist(point a,point b){
    float d=sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
    return d;
}
point midpoint(point a,point b){
    point c;
    c.x=(a.x+b.x)/2;
    c.y=(a.y+b.y)/2;
    return c;
}
float area(point a,point b,point c){
    float ar=a.x*(b.y-c.y)- a.y*(b.x-c.x)+(b.x*c.y-c.x*b.y);
    return ar;
}
int main(){
    point p1=input();
    point p2=input();
    point p3={0,0};
    point p4=midpoint(p1,p2);
    printf("p1 =(%f,%f)\n",p1.x,p1.y);
    printf("p2 =(%f,%f)\n",p2.x,p2.y);
    printf("The distance between p1 and p2 is %f units\n",dist(p1,p2));
    printf("The mid point of p1 and p2 is (%f,%f)\n",p4.x,p4.y);
    printf("The area of triangle formed by p1,p2 and origin is = ");
    printf("%f\n",area(p1,p2,p3));
    return 0;
}
