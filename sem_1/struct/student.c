#include <stdio.h>
typedef struct{
    char name[20];
    int roll;
    float cgpa;
}std;
std input(){
    std a;
    printf("Enter name\n");
    scanf("%s",&a.name);
    printf("Enter roll no.\n");
    scanf("%d",&a.roll);
    printf("Enter CGPA\n");
    scanf("%f",&a.cgpa);
    return a;
}
int main(){
    std arr[100];
    int n;
    printf("Enter no. of students\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        arr[i]=input();
    }
    char namestd[20];
    printf("Enter name to be checked\n");
    scanf("%s",&namestd);
    
}
std searchname(char a[20],std arr[n]){
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i].name==a) return arr[i];
    }
    std null;
    null.name='\0';
    return null; 
}
std searchroll(int r,std arr[n]){
    for(int i=0;i<n;i++){
        if(r==arr[i].roll) return arr[i];
    }
    else{
        printf("can't be found\n");
    }
}
void printcgpa(std arr[n],float x){
    for(int i=0;i<n;i++){
        if(arr[i].cgpa>x){
            printf("Name : %s\n",arr[i].name);
            printf("Roll no. : %d\n",arr[i].roll);
            printf("CGPA : %f\n\n",arr[i].cgpa);
        }
    }
