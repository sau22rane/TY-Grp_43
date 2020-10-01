// Implement LEX/FLEX code to select only lines that begin or end with the letter ‘a’ and
// delete everything else.

#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;
extern int multiLine;
extern int singleLine;
int main(){ 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == multiLine){
            printf("Multiline comment starts\n/*%s*/\nMultiline comment ends.\n",yytext);
        }
        else if(ntoken = singleLine){
            printf("Single-line comment:\n//%s",yytext);
        }
        ntoken = yylex();
    }
}