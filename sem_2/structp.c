#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct point{
    float x;
    float y;
};
struct point midp(struct point a,struct point b){
    struct point m;
    m.x=(a.x+b.x)/2;
    m.y=(a.y+b.y)/2;
    return m;
}
float dist(struct point a, struct point b){
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
int main(){
    struct point a;
    struct point b;
    printf("Enter the coordinates of the first point\n");
    scanf("%f %f",&a.x,&a.y);
    printf("Enter the coordinates of the second point\n");
    scanf("%f %f",&b.x,&b.y);
    struct point mid=midp(a,b);
    printf("The mid point of (%f,%f) and (%f,%f) is (%f,%f)\n",a.x,a.y,b.x,b.y,mid.x,mid.y);
    printf("The distance between the points is %f units\n",dist(a,b));
    return 0;
}