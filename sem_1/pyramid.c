#include <stdio.h>
#define ROWS 6
#define COLS 6
int main(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<ROWS-i;j++)printf(" ");
        for(int k=0;k<=i;k++) printf("* ");
        printf("\n");
    }
    return 0;
}
