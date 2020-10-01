// Even and Odd

#include<stdio.h>
#include<stdlib.h>
#include "tokenizer.h"
extern int yylex();
extern int yylineno;
extern char* yytext;


int main(){ 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == condition){
            printf("condition: %s",yytext);
        }
        if(ntoken == block_start){
            printf("\nblock start\n%s",yytext);
        }

        if(ntoken == block_end){
            printf("%s\nblock end",yytext);
        }
        if(ntoken == func){
            printf("  function:%s",yytext);
        }
        if(ntoken == datatype){
            printf("datatype:%s",yytext);
        }
        if(ntoken == number){
            printf("  value:%s ",yytext);
        }
        if(ntoken == variable){
            printf("  variable:%s ",yytext);
        }
        if(ntoken == string){
            printf("  string:%s ",yytext);
        }
        if(ntoken == operator){
            printf("  operator:%s ",yytext);
        }
        ntoken = yylex();
    }
}