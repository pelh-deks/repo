%{
#include<stdio.h>
#include<stdlib.h>

%}

%token A B
%%
 
s:A s1 B 
s1: |A s1
;
%%

int main()
{
printf("enter a string:\n");

yyparse();
printf("valid string\n");
}
int yyerror()
{
printf("Invalid string\n");
exit(0);
}
