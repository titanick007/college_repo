#include <stdio.h>
int main(){
    int m,n;
    printf("Enter no. of rows\n");
    scanf("%d",&m);
    printf("Enter no. of columns\n");
    scanf("%d",&n);
    int mat[m*n];
    int *p=mat;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;j++) scanf("%d",((mat+i)+j));
    }
    int r,c;
    printf("Enter row no.\n");
    scanf("%d",&r);
    printf("Enter column no.\n");
    scanf("%d",&c);
    for(int i=0;i<m;++i){
        if(i+1==r){
            for(int j=0;j<n;++j){
                if(j+1==c) printf("The element is position (%d,%d) is %d\n",i+1,j+1,*((mat+i)+j));
            }
        }
    }
}