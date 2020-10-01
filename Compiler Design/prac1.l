%{
    int newline = 1;
%}

%%
"\n" {newline++;
        printf("Line number is %d\n ",newline);}
. ;
%%
int yywrap(){
    return 0;
}
int main()
{
    yylex();
    return 0;
}