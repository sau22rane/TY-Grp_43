%{
    int multiLine = 1;
    int singleLine = 2;
%}
%x IN_COMMENT
%%
<INITIAL>{
"/*"              BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
"*/"        return multiLine;
.           ;
}


"//"[^\n]*\n      return singleLine;

%%
int yywrap(){
    return 1;
}