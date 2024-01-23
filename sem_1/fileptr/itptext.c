#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE* fptr;
    char filename[]="ITP.txt";
    fptr=fopen(filename,"w");
    if(fptr==NULL){
        printf("Error in creation\n");
        exit(0);
    }
    fprintf(fptr,"Intro to Programming\n");
    return 0;
}