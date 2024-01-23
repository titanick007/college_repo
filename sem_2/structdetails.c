#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[20];
    int roll;
    float cgpa;
}details;
int main(){
    int n;
    printf("Enter the no. of students\n");
    scanf("%d",&n);
    details arr[n];
    float max=0;
    details maxd;
    details mind;
    float min=10;
    for(int i=0;i<n;++i){
        printf("Enter name\n");
        scanf("%s",&arr[i].name);
        printf("Enter roll no.\n");
        scanf("%d",&arr[i].roll);
        printf("Enter cgpa\n");
        scanf("%f",&arr[i].cgpa);
        if(arr[i].cgpa>=max){
            max=arr[i].cgpa;
            maxd=arr[i];
        }
        if(arr[i].cgpa<=min){
            min=arr[i].cgpa;
            mind=arr[i];
        }
    }
    printf("\n\nHighest cgpa\n");
    printf("%s\n%d\n%f\n\n",maxd.name,maxd.roll,maxd.cgpa);
    printf("\n\nLowest cgpa\n");
    printf("%s\n%d\n%f\n\n",mind.name,mind.roll,mind.cgpa);

}