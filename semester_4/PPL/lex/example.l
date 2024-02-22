%{
#include <stdio.h>
int wordcount=0;
%}


%%

[a-zA-Z]+	{++wordcount;}
.		;//ignore everything else

"\n" {printf("Word count= %d\n",wordcount);return 0;} 

%%

int yywrap(void){}

int main(){
	printf("Input: ");
	yylex();
	return 0;
}


