%{
    int multiLine = 1;
    int singleLine = 2;
    int upper = 3;
    char str[500];
%}
%x IN_MULTI_COMMENT
%x IN_SINGLE_COMMENT
%%

"/*"(.|\n)*"*/"      return multiLine;
\/\/[^\n]*                     return singleLine;
[A-Z]                       return upper;

%%
int yywrap(){
    return 1;
}