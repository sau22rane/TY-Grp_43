%{
#include<stdio.h>
#include <stdlib.h>
#define YYSTYPE double
int yylex();
void yyerror();
%}
%token NUMBER OR AND NOT LOR LAND LEFTSHIFT RIGHTSHIFT POW exit_command
%left '+' '-'
%left '*' '/' '%'
%%

S: add_expr { printf("Results = %lf\n\n", $$);};

add_expr: mul_expr
            |add_expr '+' add_expr {$$ = $1 + $3;}
            |add_expr '-' add_expr {$$ = $1 - $3;}
            |exit_command 		{exit(EXIT_SUCCESS);}
            ;

mul_expr: brackets
            |mul_expr '*' mul_expr {$$ = $1 * $3;}
            |mul_expr '/' mul_expr {$$ = $1 / $3;}
            ;

brackets: '(' add_expr ')' {$$ = $2; }
            | primary;


primary: NUMBER{$$ = $1;}
            ;

%%

#include "lex.yy.c"
int main(void){
    while(1){
	yyparse();}
}
void yyerror(){
   printf("\nEntered arithmetic expression is Invalid\n\n");
}