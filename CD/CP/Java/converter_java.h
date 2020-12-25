/****************************************************************************

 CONVERTER_JAVA.h:
 Declares the data structure of ast_node, type_node, scope_node, sym_node and
 other functions prototypes which are used through out the building of the compiler.

*****************************************************************************/

#ifndef CONVERTER_JAVA_H_
#define CONVERTER_JAVA_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

/** Parse functions **/

extern int yylex(void);
extern void yyerror(char const *s);
extern int yyparse(void);

/** AST nodes **/

#define AST_LIST  0
#define AST_FUNCDEF  1
#define AST_FUNCHEAD  2
#define AST_PARA  3
#define AST_STDEF  4
#define AST_VAR  5
#define AST_SUBVAR  6
#define AST_COMPOUND_STMT  7
#define AST_EXPR_STMT  8
#define AST_IF_STMT  9
#define AST_FOR_STMT 10
#define AST_RETURN_STMT  11
#define AST_CONTINUE_STMT  12
#define AST_BREAK_STMT  13
#define AST_DEF  14
#define AST_DEC  15
#define AST_BINOP  16
#define AST_PREFIX  17
#define AST_POSTFIX  18
#define AST_INDEXING  19
#define AST_FUNC_CALL  20
#define AST_MEMBER  21
#define AST_ID  22
#define AST_CONST  23
#define AST_TYPE_LIMIT  24
#define AST_WHILE_STMT 25


typedef struct ast_node {
    int type;
    
    union {
        struct {
            int type;
            struct ast_node *head;
            struct ast_node *tail;
        } list;

        struct {
            int ret_type;
            struct ast_node *funchead;
            struct ast_node *funcbody;
        } funcdef;

        struct {
            int sym_name;
            struct ast_node *paras;
        } funchead;

        struct {
            int para_type;
            struct ast_node *var;
        } para;

        struct {
            int sym_name;
            struct ast_node *defs;
        } stdef;

        struct {
            int sym_name;
        } var;

        struct {
            int index;
            struct ast_node *var;
        } subvar;

        struct {
            struct ast_node *defs;
            struct ast_node *stmts;
        } compound_stmt;

        struct {
            struct ast_node *expr;
        } expr_stmt;

        struct {
            struct ast_node *cond;
            struct ast_node *then;
            struct ast_node *els;
        } if_stmt;

        struct {
            struct ast_node *init;
            struct ast_node *cond;
            struct ast_node *incr;
            struct ast_node *body;
        } for_stmt;

        struct {
            struct ast_node *cond;
            struct ast_node *body;
        } while_stmt;

        struct {
            struct ast_node *retval;
        } return_stmt;

        struct {
            int def_type;
            struct ast_node *decs;
        } def;

        struct {
            struct ast_node *var;
            struct ast_node *init;
        } dec;

        struct {
            int op;
            struct ast_node *lhs;
            struct ast_node *rhs;
        } binop;

        struct {
            int op;
            struct ast_node *unary;
        } prefix;

        struct {
            int op;
            struct ast_node *unary;
        } postfix;

        struct {
            struct ast_node *postfix;
            struct ast_node *expr;
        } indexing;

        struct {
            struct ast_node *postfix;
            struct ast_node *args;
        } func_call;

        struct {
            int sym_name;
            struct ast_node *postfix;
        } member;

        struct {
            int sym_name;
        } id;

        struct {
            int number;
        } constant;

        /*
        struct {
            int sym_name;
            struct ast_node *expr;
        } init_arg;
        */
    };
    int type_id;
    int lvalue; // 1 - left value   0 - right value
    int offset;
    int framesize;
    char fg;
} ast_node;

typedef ast_node ast_expr;
typedef ast_node ast_list;
typedef ast_node ast_stmt;


struct sym_node
{
  char str[1024];
  int sym_id;
  struct sym_node *next;
};
/*
void print_sym_ast(struct sym_node *symbol_node)
{
	printf("%s",symbol_node->str);
	printf("======id : %d ======",symbol_node->sym_id);
	printf("");
}*/
extern struct sym_node *sym_table;

extern int sym(char const *s);
extern char * symname(int sym_id);
extern int parse_int(char const *s);

/* Here we don't have INT in TYPE as we can give the INT a type_id 1, thus there is no need to record in TYPE */
enum TYPE {STRUCTURE, ARRAY, FUNC};

struct field_list
{
	int sym_id;
	int index;
	struct field_list *next;
};

struct type_node
{
  int type_id;
  enum TYPE ty;
  union
  {
    struct
    {
      int sym_name;
      struct field_list *fields;
    } as_struct;
    struct 
    {
      int elem_type_id;
      int size;
    } as_array;
    struct
    {
      int ret_type;
      int para_num; 
      int para_type[1000];
    } as_func;
  };
  int mem_space;
  struct type_node *next;
};


extern int int_type(void);
extern int float_type(void);
extern int char_type(void);
extern int struct_type(ast_node *stspec);
extern int array_type(ast_node *subvar, int elem_type_id);
extern int func_type(ast_node *funchead);
extern int builtin_func_type(int);

extern struct type_node* find_type_node(int type_id);
extern int get_memspace(int type_id);
extern int get_struct_offset(int type_id, int sym_id);

extern struct vscope_node * find_vnode(int sym_id);
extern int lookup_ttype(int sym_id);

extern ast_list *list_new(int type, ast_node *head, ast_list *tail);
extern void list_append(ast_list *first, ast_list *second);

// extern ast_node *vardef_new(int var_type, ast_list *extvars);
extern ast_node *funcdef_new(int ret_type, ast_node *funchead, ast_stmt *funcbody);
extern ast_node *funchead_new(int sym_name, ast_list *paras);
extern ast_node *para_new(int para_type, ast_node *var);

extern ast_node *stdef_new(int sym_name, ast_list *defs);

extern ast_node *var_new(int sym_name);
extern ast_node *subvar_new(ast_node *var, int index);

extern ast_stmt *compound_stmt_new(ast_list *defs, ast_list *stmts);
extern ast_stmt *expr_stmt_new(ast_expr *expr);
extern ast_stmt *if_stmt_new(ast_expr *cond, ast_stmt *then, ast_stmt *els);
extern ast_stmt *for_stmt_new(ast_expr *init, ast_expr *cond, ast_expr *incr, ast_stmt *body);
extern ast_stmt *while_stmt_new(ast_expr *cond, ast_stmt *body);
extern ast_stmt *return_stmt_new(ast_expr *retval);
extern ast_stmt *continue_stmt_new();
extern ast_stmt *break_stmt_new();

extern ast_node *def_new(int def_type, ast_list *decs);
extern ast_node *dec_new(ast_node *var, ast_node *init);

extern ast_expr *binop_new(int op, ast_expr *lhs, ast_expr *rhs);
extern ast_expr *prefix_new(int op, ast_expr *unary);
extern ast_expr *postfix_new(int op, ast_expr *unary);
extern ast_expr *indexing_new(ast_expr *postfix, ast_expr *expr);
extern ast_expr *func_call_new(ast_expr *postfix, ast_list *args);
extern ast_expr *member_new(ast_expr *postfix, int sym_name);
extern ast_expr *id_new(int sym_name);
extern ast_expr *const_new(int number);

extern ast_node *init_arg_new(int sym_name, ast_expr *expr);

/** Declarations **/

extern void set_parse_tree(ast_node *tree);
extern void print_ast(ast_node *n);
extern void report_error(const char *fmt, ...);
extern void check_ast(ast_node *n);
extern void trans_ast(ast_node *ast);
extern void transtext_ast(ast_node *ast, char *name);

extern int binop_reuse(int op);

#endif
