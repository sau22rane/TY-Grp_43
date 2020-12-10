#include<stdio.h>
#include "INST.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){
    int ntoken, vtoken;
    ntoken = yylex();
    while(ntoken){
        printf("%d %s\n",ntoken,yytext  );
        ntoken = yylex();
    }
}