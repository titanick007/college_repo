#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b;
    char st[20];
    FILE *fptr;
    fptr=fopen("values.txt","r");
    fscanf(fptr,"%s",st);
    printf("%s\n",st);
    return 0;
}