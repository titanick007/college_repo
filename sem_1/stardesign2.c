#include <stdio.h>
int main()
{
    int ROW=5;
    for (int row=1;row<=ROW;row++)
    {
        for (int i=1;i<=row-1;i++)
            printf(" ");
        for (int j=1;j<=5-row+1;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}