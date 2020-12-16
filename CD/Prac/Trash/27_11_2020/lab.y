%{
    #include <stdio.h>
    int yylineno;
    int yylex(void);
    int yyerror(char *);
%}
    %token INTEGER OTHER
    %left '+'
%%
    prog: op    {$$=$1; printf("The addition = %d\n",$$);};
    op: op '+' op   {$$ = $1+$3;}
        | INTEGER   {$$ = $1;};
%%
int yyerror(char *s) {
    printf("Syntax Error on line %d is %s\n",yylineno,s);
    return 0;
}
int main(void) {
    yyparse();  
    return 0;
}