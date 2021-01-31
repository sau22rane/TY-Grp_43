%{
    int good = 1;
%}

%%
^a.*  return good;

.*a$  return good;
.           ;
%%
int yywrap(){
    return 1;
}   