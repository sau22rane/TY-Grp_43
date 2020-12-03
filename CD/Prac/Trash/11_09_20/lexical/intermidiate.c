//lex -o a.c tokenizer.l
//gcc intermidiate.c a.c -o intermidiate
//./intermidiate <test.txt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "INST.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern void yyset_in(FILE *name);

FILE *intermidiate, *machine, *ass_code;

typedef struct Table
{
    /* data */
    char element[10];
    int address;
} Table;

Table sym_table[100], lit_table[100];
int sym_n = 0, lit_n = 0, pool_n = 0, sym_idx, IP = 0, pool[100];
int ident_value();
int add_sym();
void add_lit();
void assign_address();
int main(){

    ass_code = fopen("test.txt","r");
    yyset_in(ass_code);
    intermidiate = fopen("Intermidiate Code.txt","w");
    pool[0] = 0;
    int ntoken, vtoken;

    ntoken = yylex();
    if(ntoken==START){
        ntoken = yylex();
        IP = atoi(yytext);
        printf("Starting at : %d\n", IP);
        printf("(AD,%02d)(C,%d)\n",START%10,IP);
        fprintf(intermidiate,"(AD,%02d)(C,%d)\n",START%10,IP);
    }
    ntoken = yylex();
    ntoken = yylex();
    while(ntoken){
        //printf("%d %d %s\n",IP, ntoken,yytext  );
        switch (ntoken)
        {
        case IDENTIFIER:
            sym_idx = add_sym();
            //printf("%d %s\n",sym_idx, sym_table[sym_idx].element);
            break;
        
        case ORIGIN:
            IP = 0;
            while(ntoken!=EOL){
                ntoken = yylex();
                if(ntoken==IDENTIFIER){
                    IP+=ident_value();
                    printf("\n%d",IP);
                }
                else if(ntoken==OPERATOR){
                    if(strcmp(yytext,"+")==0){
                        ntoken = yylex();
                        IP+=atoi(yytext);
                    }
                    if(strcmp(yytext,"-")==0){
                        ntoken = yylex();
                        IP-=atoi(yytext);
                    }
                }

                printf("\n%d",IP);
            }
            IP = IP-1;
            break;        
        case LTORG:
            assign_address(LTORG);
            ntoken = yylex();
            break;

        case EOL:
            printf("\n%d",IP+1);
            fprintf(intermidiate,"\n");
            IP++;
            break;
        case END:
            assign_address(END);
            break;
        default:
            break;
        }
        if(ntoken<100){
            printf("(IS,%02d)",ntoken);
            fprintf(intermidiate,"(IS,%02d)",ntoken);
        }
        else if(ntoken<200){
            if(ntoken!=ORIGIN && ntoken!=EQU){
                //printf("(AD,%02d)",ntoken%100);
                //fprintf(intermidiate,"(AD,%02d)",ntoken%100);
            }
            else{
                while(ntoken!=EOL)
                    ntoken = yylex();
            }
        }
        else if(ntoken<300){
            printf("(DL,%02d)",ntoken%100);
            fprintf(intermidiate,"(DL,%02d)",ntoken%100);
        }
        else if(ntoken<400){
            printf("(RG,%02d)",ntoken%100);
            fprintf(intermidiate,"(RG,%02d)",ntoken%100);
        }
        else if(ntoken == LITERAL_START){
            ntoken = yylex();
            add_lit();
            printf("(L,%02d)",lit_n-1);
            fprintf(intermidiate,"(L,%02d)",lit_n-1);
        }
        else if(ntoken == IDENTIFIER){
            printf("(S,%02d)",sym_idx);
            fprintf(intermidiate,"(S,%02d)",sym_idx);
        }
        else if(ntoken == CONSTANT){
            printf("(C,%d)",atoi(yytext));
            fprintf(intermidiate,"(C,%d)",atoi(yytext));
        }
        
        ntoken = yylex();

    }
    fclose(intermidiate);
    machine = fopen("Machine Code.txt","w");
    intermidiate = fopen("Intermidiate Code.txt","r");
    yyset_in(intermidiate);
    ntoken = yylex();
    ntoken = yylex();
    ntoken = yylex();
    ntoken = yylex();
    int count = 1;
    while(ntoken){
        switch(ntoken){
            case IS:
                count++;
                ntoken = yylex();
                printf("(%d)",atoi(yytext));
                break;
            case RG:
            if(count!=1){
                count++;
                ntoken = yylex();
                printf("(%d)",atoi(yytext));
                break;
            }
            case DL:
            if(count!=1){
                ntoken = yylex();
                printf("(%d)",atoi(yytext));
                break;
            }
            case L:
            if(count!=1){
                ntoken = yylex();
                printf("(%d)",lit_table[atoi(yytext)].address);
            }
                break;
            case C:
            if(count==1){
                ntoken = yylex();
                printf("--(%d)",lit_table[atoi(yytext)].address);
                break;
            }
            else if(count==2){
                ntoken = yylex();
                printf("-(%d)",lit_table[atoi(yytext)].address);
                break;
            }
            else{
                ntoken = yylex();
                printf("(%d)",lit_table[atoi(yytext)].address);
                break;
            }

            case S:
            if(count!=1){
                ntoken = yylex();
                printf("(%d)",atoi(yytext));
            }
                break;
            case EOL:
                printf("\n");
                count = 1;
                break;
                
            default:
                break;
        }
        ntoken = yylex();
    }
    fclose(intermidiate);

}






int ident_value(){
    for(int i=0;i<sym_n;i++){
        if(strcmp(sym_table[i].element,yytext)==0){
            return sym_table[i].address;
        }
    }
}

int add_sym(){
    for(int i=0;i<sym_n;i++){
        if(strcmp(sym_table[i].element,yytext)==0){
            return i;
        }
    }
    strcpy(sym_table[sym_n].element,yytext);
    sym_table[sym_n].address=IP;
    sym_n++;
    return sym_n-1;
}

void add_lit(){
    strcpy(lit_table[lit_n].element,yytext);
    //printf("\nvghjkl %d\n",lit_n);
    lit_n++;
}

void assign_address(int ntoken){
    for(int i = pool[pool_n]; i<lit_n;i++){
        lit_table[i].address = IP;
        //printf("IP : %s %d\n",lit_table[i].element, IP);printf("(AD,%02d)",ntoken%100);
        printf("(AD,%02d)(DL,02)(C,%02d)\n",ntoken%100,atoi(lit_table[i].element));
        fprintf(intermidiate,"(AD,%02d)(DL,02)(C,%02d)\n",ntoken%100,atoi(lit_table[i].element));
        IP++;
    }
    pool_n++;
    pool[pool_n] = lit_n-1;
    IP--;
}