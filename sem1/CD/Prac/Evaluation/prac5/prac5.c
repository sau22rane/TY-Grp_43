// Convert all uppercase characters to lowercase except inside comments.

#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;
extern int multiLine;
extern int singleLine;
extern int upper;
int main(){ 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == multiLine){
            printf("%s",yytext);
        }
        else if(ntoken == singleLine){
            printf("%s",yytext);
        }
        else if(ntoken==upper){
            printf("%c",yytext[0]+'a'-'A');
        }
        ntoken = yylex();
    }
}
