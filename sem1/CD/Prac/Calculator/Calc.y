%{
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define YYSTYPE double
int yylex();
void yyerror();
%}
%token NUMBER OR AND NOT LOR LAND LEFTSHIFT RIGHTSHIFT POW exit_command XOR 
%left '+' '-'
%left '*' '/' '%' 
%left OR AND LAND LOR RIGHTSHIFT LEFTSHIFT XOR NOT

%%

S: expr { 
        long int temp = (long int) $$;
        if( $$ - temp !=0.0)
            printf("Results = %lf\n\n", $$);
        else
            printf("Results = %ld\n\n", temp);
        };

expr: conditional_expr 
    ;

conditional_expr: conditional_expr OR conditional_expr {$$ = $1 || $3;}
                |conditional_expr AND conditional_expr {$$ = $1 && $3;}
                |conditional_expr LAND conditional_expr {$$ = (int)$1 & (int)$3;}
                |conditional_expr LOR conditional_expr {$$ = (int)$1 | (int)$3;}
                |NOT conditional_expr {$$ = !$2 ;}
                |conditional_expr XOR conditional_expr {$$ = (int)$1 ^ (int)$3;}
                |pow_expr {$$ = $1;}
                ;

pow_expr: pow_expr POW shift {$$ = pow($1,$3);}
        |shift {$$ = $1;}
        ;

shift: shift RIGHTSHIFT add_expr {$$ = (int)$1 >> (int)$3;}
        |shift LEFTSHIFT add_expr {$$ = (int)$1 << (int)$3;}
        |add_expr {$$ = $1;}
        ;

add_expr: mul_expr
            |add_expr '+' add_expr {$$ = $1 + $3;}
            |add_expr '-' add_expr {$$ = $1 - $3;}
            |exit_command 		{exit(EXIT_SUCCESS);}
            ;

mul_expr: brackets
            |mul_expr '*' mul_expr {$$ = $1 * $3;}
            |mul_expr '/' mul_expr {$$ = $1 / $3;}
            ;

brackets: '(' expr ')' {$$ = $2; }
            | primary;


primary: NUMBER{$$ = $1;}
            ;

%%

#include "lex.yy.c"
int main(void){
    printf("Available Operations:\nARITHMETIC: ADDITION(+) SUBTRACTION(-) MULTIPLICATION(*) DIVISION(/) POWER(**)\nLOGICAL: AND(&&) OR(||) NOT(!) \nBITWISE: AND(&) OR(|) XOR(^)\n\nTo exit: exit\n\n");
    while(1){
	yyparse();}
}
void yyerror(){
   printf("\nEntered arithmetic expression is Invalid\n\n");
}