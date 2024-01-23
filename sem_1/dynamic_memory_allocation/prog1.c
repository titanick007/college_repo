#include <stdio.h>
#include <stdlib.h>
int main(){
    int m1,n1,m2,n2;
    printf("Enter the no. of rows and columns of matrix 1\n");
    scanf("%d %d",&m1,&n1);
    printf("Enter the no. of rows and columns of matrix 2\n");
    scanf("%d %d",&m2,&n2);
    if(n1!=m2){
        printf("The no. of columns in matrix1 and no. of rows in matirx2 must be equal\n");
        exit(0);
    }
    int mat1[m1][n1];
    int mat2[m2][n2];
    int res[m1][n2];
    for(int i=0;i<m1;++i){
        for(int j=0;j<n1;++j){
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i=0;i<m2;++i){
        for(int j=0;j<n2;++j){
            scanf("%d",&mat2[i][j]);
        }
    }
    int sum;
    for(int i=0;i<m1;++i){
        for(int j=0;j<n2;++j){
            sum=0;
            for(int k=0;k<n1;++k){
                sum=sum+(mat1[i][k]*mat2[k][j]);
            }
            res[i][j]=sum;
        }
    }
    printf("Matrix1\n");
    for(int i=0;i<m1;++i){
        for(int j=0;j<n1;++j){
            printf("%d ",mat1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix2\n");
    for(int i=0;i<m2;++i){
        for(int j=0;j<n2;++j){
            printf("%d ",mat2[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m1;++i){
        for(int j=0;j<n2;++j){
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}