%{
    int valid = 1;
%}

%%
^a.*  printf("VALID \n");


.*a$  printf("VALID \n");
.*           printf("IN-VALID \n");
%%
int yywrap(){
    return 1;
}
int main()
{
    yylex();
    return 0;
}