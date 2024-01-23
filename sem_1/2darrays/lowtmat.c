#include <stdio.h>
int upptmat(int mat[100][100],int n){
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) {
            if(mat[i][j]!=0) flag=1;
        }
    }
    if(flag==1) return 0;
    else return 1;
}
int main(){
    int n;
    printf("Enter the dimension of the matrix\n");
    scanf("%d",&n);
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&mat[i][j]);
    }
    int a=upptmat(mat,n);
    if(a==1)printf("It is an lower triangular matrix\n");
    else printf("It is not an lower triangular matrix\n");
    return 0;
}