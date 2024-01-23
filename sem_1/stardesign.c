#include <stdio.h>
int main()
{
    int ROW=11,COL=6;
    for(int row=1;row<=5;row++){
        for(int i=1;i<=COL-row;i++)
            printf("  ");
        for(int j=1;j<=row;j++)
            printf("* ");
        printf("\n");
    }
    printf("* * * * * *\n");
    for(int row=1;row<=5;row++){
        for(int i=1;i<=row;i++)
            printf("  ");
        for (int j=1;j<=COL-row;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}