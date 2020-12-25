// Even and Odd tokenization

#include<stdio.h>
#include<stdlib.h>
#include "prac1.h"
extern int yylex();
extern int yylineno;
extern char* yytext;


int main(){ 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == keyword){
            printf("Keyword: %s",yytext);
        }
        if(ntoken == block_start){
            printf("\nblock start\n%s",yytext);
        }

        if(ntoken == block_end){
            printf("%s\nblock end",yytext);
        }
        if(ntoken == number){
            printf("\nnumber:%s ",yytext);
        }
        if(ntoken == identifier){
            printf("\nIdentifier:%s ",yytext);
        }
        if(ntoken == string){
            printf("\nstring:%s ",yytext);
        }
        if(ntoken == operator){
            printf("\noperator:%s ",yytext);
        }
        if(ntoken == EOL){
            printf("\nEOL:%s ",yytext);
        }
        ntoken = yylex();
    }
}