#include <stdio.h>
int main() {
    int m,n,i,j;
    printf("Enter the no. of rows\n");
    scanf("%d",&m);
    printf("Enter the no. of columns\n");
    scanf("%d",&n);
    int A[m][n],B[n][m];
    printf("Taking inputs\n");
    for(i=0;i<m;++i){
        printf("Row %d\n",i);
        for(j=0;j<n;++j) scanf("%d",&A[i][j]);
    }
    for(i=0;i<m;++i){
       
        for(j=0;j<n;++j) B[j][i]=A[i][j];
    }
    printf("The matrix is \n");
    for(i=0;i<m;++i){
        for(j=0;j<n;++j) printf("%d ",A[i][j]);
        printf("\n");
    }
    printf("Transpose of the matrix is\n");
    for(i=0;i<n;++i){
        for(j=0;j<m;++j) printf("%d ",B[i][j]);
        printf("\n");
    }
    return 0;
}
