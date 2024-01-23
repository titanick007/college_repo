#include <stdio.h>
int main(){
    int i=5;
    int *a=&i;
    int **b=&a;
    int ***c=&b;
    printf("%d\n", ******c);
}