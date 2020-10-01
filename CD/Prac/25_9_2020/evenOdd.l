%{
    #include "tokenizer.h"
%}

%%
"if("                   return condition;
"int"                   return datatype;
"else"                  return condition;
"{"                     return block_start;
"}"                     return block_end;
[a-zA-Z][a-zA-Z0-9]*"(" return func;
[a-zA-Z][a-zA-Z0-9]*    return variable;
\"[a-zA-Z0-9!@#$%^&*()_+= ]*\"    return string;
[1-9][0-9]*             return number;
==|%|<|>|<=|>=|&&|\|\|    return operator;
.                   printf("%s", yytext);
%%
int yywrap(){
    return 1;
}   