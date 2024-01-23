#include <stdio.h>
int main()
{
    float rad,Pmeter,area;
    printf("Enter radius of circle\n");
    scanf("%f",&rad);
    Pmeter=2*3.14*rad;
    area=3.14*rad*rad;
    printf("The perimeter and area of this circle is %f and %f\n",Pmeter,area);
    return 0;
}