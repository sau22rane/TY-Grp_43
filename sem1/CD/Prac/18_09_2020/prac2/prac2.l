%{
    int good = 1;
%}

%%
^a[a-z ]*a$  return good;

^a[a-z ]*  return good;

^[a-z ][a-z ]*a$  return good;
.           ;
%%
int yywrap(){
    return 1;
}   