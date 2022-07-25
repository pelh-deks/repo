%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%left '+''-'
%left '*''/'
%%
start:exp {printf("Result=%d\n",$$);}
exp:exp'+'exp {$$=$1+$3;}
|exp'-'exp {$$=$1-$3;}
|exp'*'exp {$$=$1*$3;}
|exp'/'exp
{
if($3==0)
{
printf("divide by zero error\n");
exit(0);
}
else{
$$=$1/$3;
}
}
|'('exp')' {$$=$2;}
|NUM {$$=$1;}
;
%%
int main()
{
printf("Enter the expression :\n");
yyparse ();
return 0;
}
int yyerror()
{
printf("Error\n");
return -1;
}
