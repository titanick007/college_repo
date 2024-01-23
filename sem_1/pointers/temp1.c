#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* fptr;
    fptr=fopen("ITP.txt","r");
    char a[100];
    while(fgets(a,100,fptr)){
        printf("%s",a);
    }
    fclose(fptr);
    return 0;
}