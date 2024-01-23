#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* fptr;
    //char filename[]="ITP.txt";
    fptr=fopen("ITP.txt","w+");
    if(fptr==NULL){
        printf("Error \n");
        exit(0);
        }
    fprintf(fptr,"yo wassup\n");
    return 0;
}