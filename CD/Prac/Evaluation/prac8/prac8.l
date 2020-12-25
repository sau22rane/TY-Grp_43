%{
#include<stdio.h>
#include "y.tab.h"
%}

%%
[0-9]+		{strcpy(yylval.tok,yytext); return NUM;}
[a-z]+ 		{strcpy(yylval.tok,yytext); return VAR;}
" "         ;
.			{return yytext[0];}
\n 			{return 0;}
%%

int yywrap(){return 1;}