#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fptr;
    fptr=fopen("ITP.txt","w");
    fputs("I am good\n",fptr);
    fputs("I am from indore.",fptr);
    fclose(fptr);
    return 0;
}