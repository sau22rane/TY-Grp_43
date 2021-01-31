%{
    int multiLine = 1;
    int singleLine = 2;
    char str[500];
%}
%x IN_MULTI_COMMENT
%x IN_SINGLE_COMMENT
%%



<INITIAL>{
"//"              printf("\n//spotted\n"); strcpy(str,"\0"); BEGIN(IN_SINGLE_COMMENT);
"/*"              printf("\n/*spotted\n"); BEGIN(IN_MULTI_COMMENT);
}
<IN_MULTI_COMMENT>{
"*/"        strcpy(yytext,str); BEGIN(INITIAL); return multiLine;
.           strcat(str,yytext);
}
<IN_SINGLE_COMMENT>{
"\n"        strcpy(yytext,str); BEGIN(INITIAL); return singleLine;
.           strcat(str,yytext);
}

%%
int yywrap(){
    return 1;
}