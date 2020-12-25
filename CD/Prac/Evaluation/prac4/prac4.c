// Implement LEX/FLEX code to count the number of characters, words and lines in an input
// file.

#include<stdio.h>
#include<stdlib.h>
extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){ 
    int ntoken = yylex();
    int letters = 0;
    int lines = 0;
    int words = 0;
    while(ntoken){
        switch(ntoken){
            case 1:
                letters++;
                break;
            case 2:
                words++;
                break;
            case 3:
                lines ++;
                words++;
                break;
            default:
                break;

        }
        ntoken = yylex();
    }
    printf("Letters: %d\nWords: %d\nLines: %d\n", letters, words, lines);
}