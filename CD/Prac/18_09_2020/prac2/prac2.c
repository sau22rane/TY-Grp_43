// Implement LEX/FLEX code to select only lines that begin or end with the letter ‘a’ and
// delete everything else.

#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){ 
    int ntoken = yylex();
    int valid = 1;
    while(ntoken){
        if(ntoken == valid){
            printf("%s",yytext);
        }
        ntoken = yylex();
    }
}