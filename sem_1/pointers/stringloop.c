#include <stdio.h>
#include <string.h>
int main(){
    char s[10]="Done";
    for(int i=0;i<strlen(s);++i)
    printf("%s",s+i);
    printf("\n");
    return 0;
}