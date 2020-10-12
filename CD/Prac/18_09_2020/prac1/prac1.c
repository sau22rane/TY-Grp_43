//Add line numbers to lines of text, printing the new text to the standard output using
//LEX/FLEX.

#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){
    int count = 1;
    printf("%d. ", count);
    int ntoken = yylex();
    int newline = 1;
    while(ntoken){
        printf("%s",yytext);
        if(ntoken == newline){
            count++;
            printf("%d. ",count);
        }
        ntoken = yylex();
    }
}