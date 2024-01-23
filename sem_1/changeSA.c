#include <stdio.h>
#include <math.h>
int main()
{
    float Rad,rad,sa1,sa2;int N;
    printf("Enter the radius of metal sphere\n");
    scanf("%f",&Rad);
    printf("Enter the number of metal balls it should be melted into\n");
    scanf("%d",&N);
    sa1=4*3.14*pow((double)Rad,2);
    rad=Rad/cbrt((double)N);
    sa2=4*3.14*pow(rad,2);
    printf("sa1=%lf\n",sa1);
    printf("sa2=%lf\n",sa2);
    printf("The difference in surface area= %lf\n",(N*sa2)-sa1);
    return 0;
}