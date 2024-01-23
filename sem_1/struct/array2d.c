#include <stdio.h>
int main(){
int a[3][3];
int i,j;
printf("Enter the values of array\n");
for(i=0;i<=3;i++){
for(j=0;j<=i;j++) scanf("%d",&a[i][j]);
}
for(i=0;i<=3;i++){
for(j=0;j<=i;j++) printf("%d ",a[i][j]);
printf("\n");
}
}
