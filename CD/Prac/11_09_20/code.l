%{
    
    int ch;
%}

%%
[0-9]*   {printf("Value = %s\n",yytext);}
[A-Za-z_][A-Za-z0-9_]*   {printf("Variable = %s\n",yytext);}
.       {}
%%

int main(){
    printf("hey");
    yylex();
    return 0;
}

int yywrap(){
    printf("hey");
    return 0;
}