%{
    int word = 2;
    int letter = 1;
    int line = 3;
%}

%%
" "     return word;
"\n"    return line;

.       return letter;
%%
int yywrap(){
    return 1;
}