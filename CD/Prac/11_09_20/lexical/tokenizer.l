%{
    #include "INST.h"
%}

%%
"STOP"          return STOP;
"ADD"           return ADD;
"SUB"           return SUB;
"MULTI"         return MULTI;
"MOVER"         return MOVER;
"MOVEM"         return MOVEM;
"COMB"          return COMB;
"BC"            return BC;
"DIV"           return DIV;
"READ"          return READ;
"PRINT"         return PRINT;
"START"         return START;
"END"           return END;
"ORIGIN"        return ORIGIN;
"EQU"           return EQU;
"LTORG"         return LTORG;
"DS"            return DS;
"DC"            return DC;
"AREG"          return AREG;
"BREG"          return BREG;
"CREG"          return CREG;
"AD"            return AD;
"DL"            return DL;
"IS"            return IS;
"RG"            return RG;
"L"             return L;
"C"             return C;
"S"             return S;
[a-zA-Z_][a-zA-Z0-9_]*  return IDENTIFIER;
[0-9]*     return CONSTANT;
"='"            return LITERAL_START;
"\n"            return EOL;
[\+\-\*/]       return OPERATOR;
.                     ;
%%

int yywrap(){
    return 1;
}