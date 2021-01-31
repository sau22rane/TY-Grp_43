%{
    int number = 1;
%}
%%

[1-9][0-9]*|0      return number;
.                  printf("%s",yytext);

%%
int yywrap(){
    return 1;
}