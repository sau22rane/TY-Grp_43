%{
#include "converter_python.h"
%}

%union{
    int i;
    struct ast_node *n;
}

%right <i> INC_OP DEC_OP
%left  <i> SHL_OP SHR_OP
%left  <i> LE_OP GE_OP
%left  <i> EQ_OP NE_OP
%left  <i> AND_OP
%left  <i> OR_OP
%right <i> ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN

%token <i> IDENTIFIER CONSTANT

%token INT STRUCT FLOAT CHAR
%token IF ELSE FOR CONTINUE BREAK RETURN READ WHILE

%token EXTDEFS PARAS STMTS DEFS DECS ARGS INIT_ARGS

%type <n> extdef func para var def dec init init_arg
%type <n> expr assignment logical_or logical_and bit_or bit_xor bit_and equality relational shift additive multi unary postfix primary
%type <n> program extdefs paras stmts defs decs args init_args
%type <n> stmt compound_stmt expr_stmt selection_stmt iteration_stmt while_stmt jump_stmt 

%start program

%%

program:
  /* empty */   { set_parse_tree($$ = NULL); }
  | extdefs       { set_parse_tree($$ = $1); }
  ;

extdefs:
  extdef          { $$ = list_new(EXTDEFS, $1, NULL); }
  | extdefs extdef  { list_append($$ = $1, list_new(EXTDEFS, $2, NULL)); }
  ;

extdef:
  def                         { $$ = $1; }
  | INT    func compound_stmt   { $$ = funcdef_new(int_type(), $2, $3); }
  | FLOAT func compound_stmt   { $$ = funcdef_new(float_type(), $2, $3); }
  | CHAR func compound_stmt   { $$ = funcdef_new(char_type(), $2, $3); }
  ;


func:
  IDENTIFIER '(' paras ')'  { $$ = funchead_new($1, $3); }
  | IDENTIFIER '('       ')'  { $$ = funchead_new($1, NULL); }
  ;

paras:
  para            { $$ = list_new(PARAS, $1, NULL); }
  | paras ',' para  { list_append($$ = $1, list_new(PARAS, $3, NULL)); }
  ;

para:
  INT    var  { $$ = para_new(int_type(), $2); }
  ;

var:
  IDENTIFIER            { $$ = var_new($1); }
  | var '[' CONSTANT ']'  { $$ = subvar_new($1, $3); }
  ;

stmts:
  stmt        { $$ = list_new(STMTS, $1, NULL); }
  | stmts stmt  { list_append($$ = $1, list_new(STMTS, $2, NULL)); }
  ;

stmt:
  compound_stmt   { $$ = $1; }
  | expr_stmt       { $$ = $1; }
  | selection_stmt  { $$ = $1; }
  | iteration_stmt  { $$ = $1; }
  | while_stmt      { $$ = $1 ;}
  | jump_stmt       { $$ = $1; }
  ;

compound_stmt:
  '{' defs stmts '}'  { $$ = compound_stmt_new($2, $3); }
  | '{' defs       '}'  { $$ = compound_stmt_new($2, NULL); }
  | '{'      stmts '}'  { $$ = compound_stmt_new(NULL, $2); }
  | '{'            '}'  { $$ = compound_stmt_new(NULL, NULL); }
  | ';'                 { $$ = compound_stmt_new(NULL, NULL); }
  ;

expr_stmt:
  expr ';'  { $$ = expr_stmt_new($1); }
  ;

selection_stmt:
  IF '(' expr ')' stmt            { $$ = if_stmt_new($3, $5, NULL); }
  | IF '(' expr ')' stmt ELSE stmt  { $$ = if_stmt_new($3, $5, $7); }
  ;

iteration_stmt:
  FOR '(' expr ';' expr ';' expr ')' stmt   { $$ = for_stmt_new($3,   $5,   $7,   $9); }
  | FOR '(' expr ';' expr ';'      ')' stmt   { $$ = for_stmt_new($3,   $5,   NULL, $8); }
  | FOR '(' expr ';'      ';' expr ')' stmt   { $$ = for_stmt_new($3,   NULL, $6,   $8); }
  | FOR '(' expr ';'      ';'      ')' stmt   { $$ = for_stmt_new($3,   NULL, NULL, $7); }
  | FOR '('      ';' expr ';' expr ')' stmt   { $$ = for_stmt_new(NULL, $4,   $6,   $8); }
  | FOR '('      ';' expr ';'      ')' stmt   { $$ = for_stmt_new(NULL, $4,   NULL, $7); }
  | FOR '('      ';'      ';' expr ')' stmt   { $$ = for_stmt_new(NULL, NULL, $5,   $7); }
  | FOR '('      ';'      ';'      ')' stmt   { $$ = for_stmt_new(NULL, NULL, NULL, $6); }
  ;

while_stmt:
  WHILE '(' expr ')' stmt {$$ = while_stmt_new($3 , $5);}
  ;

jump_stmt:
  RETURN expr ';'   { $$ = return_stmt_new($2); }
  | CONTINUE ';'      { $$ = continue_stmt_new(); }
  | BREAK ';'         { $$ = break_stmt_new(); }
  ;

defs:
  def       { $$ = list_new(DEFS, $1, NULL); }
  | defs def  { list_append($$ = $1, list_new(DEFS, $2, NULL)); }
  ;

def:
  INT    decs ';'   { $$ = def_new(int_type(), $2); }
  ;

decs:
  dec           { $$ = list_new(DECS, $1, NULL); }
  | decs ',' dec  { list_append($$ = $1, list_new(DECS, $3, NULL)); }
  ;

dec:
  var           { $$ = dec_new($1, NULL); }
  | var '=' init  { $$ = dec_new($1, $3); }
  ;

init:
  expr                { $$ = $1; }
  | '{' init_args '}'   { $$ = $2; }
  ;

expr:
  assignment  { $$ = $1; }
  | READ '(' expr ')' { $$ = binop_new('=', $3, func_call_new(id_new(sym("read")), NULL)); }
  ;

assignment:
  logical_or                      { $$ = $1; }
  | unary  '='         assignment   { $$ = binop_new('=', $1, $3); }
  | unary  ADD_ASSIGN  assignment   { $$ = binop_new(ADD_ASSIGN, $1, $3); }
  | unary  SUB_ASSIGN  assignment   { $$ = binop_new(SUB_ASSIGN, $1, $3); }
  | unary  MUL_ASSIGN  assignment   { $$ = binop_new(MUL_ASSIGN, $1, $3); }
  | unary  DIV_ASSIGN  assignment   { $$ = binop_new(DIV_ASSIGN, $1, $3); }
  | unary  MOD_ASSIGN  assignment   { $$ = binop_new(MOD_ASSIGN, $1, $3); }
  | unary  AND_ASSIGN  assignment   { $$ = binop_new(AND_ASSIGN, $1, $3); }
  | unary  XOR_ASSIGN  assignment   { $$ = binop_new(XOR_ASSIGN, $1, $3); }
  | unary  OR_ASSIGN   assignment   { $$ = binop_new(OR_ASSIGN, $1, $3); }
  | unary  SHL_ASSIGN  assignment   { $$ = binop_new(SHL_ASSIGN, $1, $3); }
  | unary  SHR_ASSIGN  assignment   { $$ = binop_new(SHR_ASSIGN, $1, $3); }
  ;

logical_or:
  logical_and                   { $$ = $1; }
  | logical_or OR_OP logical_and  { $$ = binop_new(OR_OP, $1, $3); }
  ;

logical_and:
  bit_or                      { $$ = $1; }
  | logical_and AND_OP bit_or   { $$ = binop_new(AND_OP, $1, $3); }
  ;

bit_or:
  bit_xor             { $$ = $1; }
  | bit_or '|' bit_xor  { $$ = binop_new('|', $1, $3); }
  ;

bit_xor:
  bit_and               { $$ = $1; }
  | bit_xor '^' bit_and   { $$ = binop_new('^', $1, $3); }
  ;

bit_and:
  equality              { $$ = $1; }
  | bit_and '&' equality  { $$ = binop_new('&', $1, $3); }
  ;

equality:
  relational                  { $$ = $1; }
  | equality EQ_OP relational   { $$ = binop_new(EQ_OP, $1, $3); }
  | equality NE_OP relational   { $$ = binop_new(NE_OP, $1, $3); }
  ;

relational:
  shift                   { $$ = $1; }
  | relational '>'   shift  { $$ = binop_new('>', $1, $3); }
  | relational GE_OP shift  { $$ = binop_new(GE_OP, $1, $3); }
  | relational '<'   shift  { $$ = binop_new('<', $1, $3); }
  | relational LE_OP shift  { $$ = binop_new(LE_OP, $1, $3); }
  ;

shift:
  additive                { $$ = $1; }
  | shift SHL_OP additive   { $$ = binop_new(SHL_OP, $1, $3); }
  | shift SHR_OP additive   { $$ = binop_new(SHR_OP, $1, $3); }
  ;

additive:
  multi               { $$ = $1; }
  | additive '+' multi  { $$ = binop_new('+', $1, $3); }
  | additive '-' multi  { $$ = binop_new('-', $1, $3); }
  ;

multi:
  unary             { $$ = $1; }
  | multi '*' unary   { $$ = binop_new('*', $1, $3); }
  | multi '/' unary   { $$ = binop_new('/', $1, $3); }
  | multi '%' unary   { $$ = binop_new('%', $1, $3); }
  ;

unary:
  postfix       { $$ = $1; }
  | INC_OP unary  { $$ = prefix_new(INC_OP, $2); }
  | DEC_OP unary  { $$ = prefix_new(DEC_OP, $2); }
  | '-' unary     { $$ = prefix_new('-', $2); }
  | '!' unary     { $$ = prefix_new('!', $2); }
  | '~' unary     { $$ = prefix_new('~', $2); }
  ;

postfix:
  primary                 { $$ = $1; }
  | postfix INC_OP          { $$ = postfix_new(INC_OP, $1); }
  | postfix DEC_OP          { $$ = postfix_new(DEC_OP, $1); }
  | postfix '[' expr ']'    { $$ = indexing_new($1, $3); }
  | postfix '(' args ')'    { $$ = func_call_new($1, $3); }
  | postfix '('      ')'    { $$ = func_call_new($1, NULL); }
  | postfix '.' IDENTIFIER  { $$ = member_new($1, $3); }
  ;

primary:
  IDENTIFIER    { $$ = id_new($1); }
  | CONSTANT      { $$ = const_new($1); }
  | '(' expr ')'  { $$ = $2; }
  ;

args:
  expr            { $$ = list_new(ARGS, $1, NULL); }
  | args ',' expr   { list_append($$ = $1, list_new(ARGS, $3, NULL)); }
  ;

init_args:
  init_arg                { $$ = list_new(INIT_ARGS, $1, NULL); }
  | init_args ',' init_arg  { list_append($$ = $1, list_new(INIT_ARGS, $3, NULL)); }
  ;

init_arg:
  expr   { $$ = $1; }
  ;
