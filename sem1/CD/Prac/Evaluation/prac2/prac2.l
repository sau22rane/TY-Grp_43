%{
    int newline = 1;
%}

%%
"\n" return newline;
%%
int yywrap(){
    return 1;
}