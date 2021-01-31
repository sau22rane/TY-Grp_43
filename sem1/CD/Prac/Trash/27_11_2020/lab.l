%{
#include <stdlib.h>
void yyerror(char *);
#include "lab.tab.h"
%}
%%
[0-9]+ {
    yylval = atoi(yytext);
    return INTEGER;
}
[-+\n] return *yytext;
[ \t] ; /* skip whitespace */
. printf("invalid character");
%%
int yywrap(void) {
return 0;
}