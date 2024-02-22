%{
#include <stdio.h>
int num_char=0;
int num_lines=0;
%}

%%

[\n]	{++num_lines;++num_char;}
.	{if(num_lines==0){num_lines=1;}++num_char;}
":q"	{printf("Number of characters: %d\n Number of lines: %d\n",num_char,num_lines);num_char=0;num_lines=0;}

%%
int yywrap(void){}
int main(){
	yylex();
	return 0;
}
