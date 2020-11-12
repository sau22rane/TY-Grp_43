#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;
extern int number;
int main(){ 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == number){
            fprintf(stderr,"int: %d\thex: %x\n",atoi(yytext),atoi(yytext));
        }
        ntoken = yylex();
    }
    return 0;
}