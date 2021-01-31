%{
#include "y.tab.h"
void yyerror (char *s);
int yylex();
%}
%%
"print"				   {return print;}
"exit"				   {return exit_command;}
[a-zA-Z]			   {yylval.id = yytext[0]; return identifier;}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[ \t]                ;
[-+=;]           	   {return yytext[0];}
[\n]                    return 0;
.                      {ECHO; yyerror ("unexpected character");}

%%
int yywrap (void) {return 1;}