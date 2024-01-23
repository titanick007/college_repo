#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
    FILE* sptr,*dptr;
    if(argc!=3){
        printf("Usage: ./a.out, in.txt,out.txt\n");
        exit(0);
    }
    if((sptr=fopen("ITP.txt","r"))==NULL){
        printf("input file doesn't exist\n");
        exit(0);
    }
    else if((dptr=fopen("dest.txt","w"))==NULL){
        printf("output file doesn't exist\n");
        exit(0);
    }
    char c;
    while((c=fgetc(sptr))!=EOF){
        fputc(c,dptr);
    }
    fclose(sptr);
    fclose(dptr);
    return 0;
}