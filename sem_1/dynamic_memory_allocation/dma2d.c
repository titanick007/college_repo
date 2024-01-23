#include <stdio.h>
#include <stdlib.h>
int main(){
    int m,n;
    printf("Enter the no. of rows and columns\n");scanf("%d %d",&m,&n);
    int *p= (int *)malloc(n*sizeof(int));
    int* a[m];
    for(int i=0;i<m;++i){
        a[i]= p;
        for(int j=0;j<n;++j){
            scanf("%d",*(p+j));
        }
    }
    for(int i=0;i<m;++i){
        printf("%d\n",a[i]);
        
    }
    return 0;
}