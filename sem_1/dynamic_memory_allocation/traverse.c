#include <stdio.h>
#include <stdlib.h>
int main(){
    int m,n;
    printf("Enter the no. of rows and columns \n");
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j) scanf("%d",((a+i)+j));
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(i==0&&j==0) {
                printf("%d ",a[i][j]);
                break;
            }
            else if()

        }
    }
    return 0;
}