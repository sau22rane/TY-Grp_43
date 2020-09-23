%{
    int multiLine = 1;
    int singleLine = 2;
    char str[500];
%}
%x IN_MULTI_COMMENT
%x IN_SINGLE_COMMENT
%%



<INITIAL>{
"//"              BEGIN(IN_SINGLE_COMMENT);
"/*"              BEGIN(IN_MULTI_COMMENT);
}
<IN_MULTI_COMMENT>{
"*/"        strcpy(yytext,str); return multiLine;
.           strcat(str,yytext); //printf("%s",str);
}
<IN_SINGLE_COMMENT>{
"\n"        strcpy(yytext,str); return singleLine;
.           strcat(str,yytext); //printf("%s",str);
}

%%
int yywrap(){
    return 1;
}