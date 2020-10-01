%{
    int word = 1;
    int letter = 0;
    int line = 0;
%}

%%
" "     {word++;
        printf("\nWORDS : %d \n",word);};
"\n"    {line++;
        printf("\nLINE : %d \n",line);
        printf("\nLETTER : %d \n",letter);};

[a-zA-Z]       {letter++;};
%%
int yywrap(){
    return 1;
}
int main()
{
    yylex();
    return 0;
}