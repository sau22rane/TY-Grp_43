%{
    int number = 1;
%}
%x IN_MULTI_COMMENT
%x IN_SINGLE_COMMENT
%%

[1-9][0-9]*|0      return number;
.                  printf("%s",yytext);

%%
int yywrap(){
    return 1;
}