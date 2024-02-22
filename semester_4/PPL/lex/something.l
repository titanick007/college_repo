%{
#include <stdio.h>

int numoperands=0;
int numoperators=0;
int numbrackets=0;
%}


%%

[0-9]+	{printf("NUMBER : %s\n",yytext);numoperands++;}
[-+*/]	{printf("OPERATOR : %s\n",yytext);numoperators++;}
[()]	{printf("BRACKET : %s\n",yytext);numbrackets++;}
[\t]		;//ignoring whitespace and newlines
.		{printf("Invalid character : %s\n",yytext);}
"\n"	{printf("Number of operands: %d\n Number of operators: %d\n Number of brackets :%d\n",numoperands,numoperators,numbrackets);numoperands=0;numoperators=0;numbrackets=0;}

%%

int yywrap(void){}
int main(){
	printf("Input :");
	yylex();
	//printf(": %d\n",wordcounter);
	return 0;
}


