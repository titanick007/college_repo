#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char name[20];
    int runs;
    float avg;
}stats;
int main(){
    int n;
    printf("Enter no. of inputs\n");
    scanf("%d",&n);
    stats* ptr=(stats*)malloc(n*sizeof(stats));
    for(int i=0;i<n;++i){
        printf("Enter name\n");
        scanf("%s",&ptr[i].name);
        printf("Enter runs\n");
        scanf("%d",&ptr[i].runs);
        printf("Enter average\n");
        scanf("%f",&ptr[i].avg);
    }
    printf("\nNAME\t\tRUNS\t\tAVG\n");
    for(int i=0;i<n;++i){
        printf("%s\t\t\t%d\t\t%f\n",ptr[i].name,ptr[i].runs,ptr[i].avg);
    }
    return 0;
}