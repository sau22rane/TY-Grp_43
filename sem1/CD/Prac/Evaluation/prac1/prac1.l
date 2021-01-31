%{
    #include "prac1.h"
%}
    
%%

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int                return keyword;
long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while    return keyword;


"{"                     return block_start;
"}"                     return block_end;
\"[a-zA-Z0-9!@#$%^&*()_+= ]*\"  return string;
[a-zA-Z][a-zA-Z0-9]*    return identifier;
0|([1-9][0-9]*)             return number;
=|==|%|<|>|<=|>=|&&|\|\|  return operator;
";"                     return EOL;
.                   printf("%s", yytext);
%%
int yywrap(){
    return 1;
}   