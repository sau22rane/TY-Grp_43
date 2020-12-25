%{
	#include<stdio.h>
	extern YYSTYPE yylval;
%}
%%
[0-9]+ {
	sscanf(yytext,"%lf", &yylval);
	return NUMBER;

	}
[ \t] ;
"exit"	{return exit_command;}
"&&"	{return AND;}
"||"	{return OR;}
"&"		{return LAND;}
"|"		{return LOR;}
"**" 	{return POW;}
"<<" 	{return LEFTSHIFT;}
">>" 	{return RIGHTSHIFT;}
"!" 	{return NOT;}
"^" 	{return XOR;}
[\n] return 0;

. return yytext[0];
%%
int yywrap(){
	return 1;
}