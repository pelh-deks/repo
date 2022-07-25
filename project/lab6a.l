%{
#include<stdio.h>
int com=0;
%}
%%
"/*"[^*]*.*"*/"  {com++;}
\/\/[^\n]*  {com++;}
%%
main(int argc,char *argv[])
{
if(argc!=3)
{
printf("\n\tUsage:%s <input file><output file>\n",argv[0]);
return;
}
yyin=fopen(argv[1],"r");
yyout=fopen(argv[2],"w");
yylex();
printf("Number of comment lines=%d\n",com);
}