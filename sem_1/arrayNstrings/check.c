#include <stdio.h>
int main(){
    int a[15],k=0,i,n,numc;
    printf("Enter the number of entries\n");
    scanf("%d",&n);
    printf("Enter the number to be checked\n");
    scanf("%d",&numc);
    printf("Enter the array\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        if(a[i]==numc)k++;
    }
    printf("%d is present in the array %d times\n",numc,k);
    return 0;
}