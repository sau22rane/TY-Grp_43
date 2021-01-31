/****************************************************************************

 print_ast.c:
 Implements functions required for printing the AST in HTML format.
 For the sake of printing the parse tree in a hierarchical style, list representation
 in HTML with tags < ul > and < li > is leveraged.

*****************************************************************************/


#include <stdio.h>
#include "converter_java.h"
#include <stdarg.h>


typedef void (*ast_printer)(ast_node *n);
static int tabs = -1;
static ast_printer g_ast_printers[AST_TYPE_LIMIT];




static void print_spaces()
{
	for(int i = 0 ; i < tabs ; i++ )
	{
		printf("   ");
	}
}


static void printt (const char *format, ...)
{
    print_spaces();
   va_list arg;
   int done;

   va_start (arg, format);
   done = vfprintf (stdout, format, arg);
   va_end (arg);


}
static void print_list(ast_node *n)
{
    // printf("\n");
    for (; n; n = n->list.tail)
    {
        printf("\n");
        printt("----------------\n");
        print_ast(n->list.head);
        // printt("----------------");
        printf("\n");
    }
    // printf("\n");
}
static void print_funcdef(ast_node *n)
{   
    
    printf("=======================================================");
    printt("\n");
    printt("funcdef\n");
    printt("ret_type: %d\n", n->funcdef.ret_type);
    printt("funchead:\n");
    print_ast(n->funcdef.funchead);
    printt("\n");
    printt("funcbody:\n");
    print_ast(n->funcdef.funcbody);
    // printf("----------------------------------");
    
}

static void print_funchead(ast_node *n)
{
    
    printt("funchead\n");
    printt("sym_name: %d\n", n->funchead.sym_name);
    printt("paras:\n");
    print_spaces(tabs++);
    print_ast(n->funchead.paras);
    tabs--;
    
    
}

static void print_para(ast_node *n)
{
    
    printt("para\n");
    printt("para_type: %d\n", n->para.para_type);
    printt("var:\n");
    print_ast(n->para.var);
    
    
}

static void print_stdef(ast_node *n)
{
    
    printt("stdef\n");
    printt("sym_name: %d\n", n->stdef.sym_name);
    printt("defs:\n");
    print_ast(n->stdef.defs);
    
    
}

static void print_var(ast_node *n)
{
    
    printt("var\n");
    printt("sym_name: %d\n", n->var.sym_name);
    
}

static void print_subvar(ast_node *n)
{
    
    printt("subvar\n");
    printt("index: %d\n", n->subvar.index);
    printt("var:\n");
    print_ast(n->subvar.var);
    
    
}

static void print_compound_stmt(ast_node *n)
{
    
    printt("compound_stmt\n");
    printt("defs:\n");
    print_ast(n->compound_stmt.defs);
    
    printt("stmts:\n");
    print_ast(n->compound_stmt.stmts);
    
    
}

static void print_expr_stmt(ast_node *n)
{
    
    printt("expr_stmt\n");
    printt("expr:\n");
    print_ast(n->expr_stmt.expr);
    
    
}

static void print_if_stmt(ast_node *n)
{
    
    printt("if_stmt\n");
    printt("cond:\n");
    print_ast(n->if_stmt.cond);
    
    printt("then:\n");
    print_ast(n->if_stmt.then);
    
    printt("els:\n");
    print_ast(n->if_stmt.els);
    
    
}

static void print_for_stmt(ast_node *n)
{
    
    printt("for_stmt\n");
    printt("init:\n");
    print_ast(n->for_stmt.init);
    
    printt("cond:\n");
    print_ast(n->for_stmt.cond);
    
    printt("incr:\n");
    print_ast(n->for_stmt.incr);
    
    printt("body:\n");
    print_ast(n->for_stmt.body);
    
    
}

static void print_return_stmt(ast_node *n)
{
    
    printt("return_stmt\n");
    printt("retval:\n");
    print_ast(n->return_stmt.retval);
    
    
}

static void print_continue_stmt(ast_node *n)
{
    
    printt("continue_stmt\n");
    
}

static void print_break_stmt(ast_node *n)
{
    
    printt("break_stmt\n");
    
}

static void print_def(ast_node *n)
{
    
    printt("def\n");
    printt("def_type: %d\n", n->def.def_type);
    printt("decs:\n");
    print_ast(n->def.decs);
    
    
}

static void print_dec(ast_node *n)
{
    
    printt("dec\n");
    printt("var:\n");
    print_ast(n->dec.var);
    
    printt("init:\n");
    print_ast(n->dec.init);
    
    
}

static void print_binop(ast_node *n)
{
    
    printt("binop\n");
    printt("op: %d\n", n->binop.op);
    printt("lhs:\n");
    print_ast(n->binop.lhs);
    
    printt("rhs:\n");
    print_ast(n->binop.rhs);
    
    
}

static void print_prefix(ast_node *n)
{
    
    printt("prefix\n");
    printt("op: %d\n", n->prefix.op);
    printt("unary:\n");
    print_ast(n->prefix.unary);
    
    
}

static void print_postfix(ast_node *n)
{
    
    printt("postfix\n");
    printt("op: %d\n", n->postfix.op);
    printt("unary:\n");
    print_ast(n->postfix.unary);
    
    
}

static void print_indexing(ast_node *n)
{
    
    printt("indexing\n");
    printt("postfix:\n");
    print_ast(n->indexing.postfix);
    
    printt("expr:\n");
    print_ast(n->indexing.expr);
    
    
}

static void print_func_call(ast_node *n)
{
    
    printt("func_call\n");
    printt("postfix:\n");
    print_ast(n->func_call.postfix);
    
    printt("args:\n");
    print_ast(n->func_call.args);
    
    
}

static void print_member(ast_node *n)
{
    
    printt("member\n");
    printt("sym_name: %d\n", n->member.sym_name);
    printt("postfix:\n");
    print_ast(n->member.postfix);
    
    
}

static void print_id(ast_node *n)
{
    
    printt("id\n");
    printt("sym_name: %d\n", n->id.sym_name);
    
}

static void print_const(ast_node *n)
{
    
    printt("const\n");
    printt("number: %d\n", n->constant.number);
    
}

/*
static void print_init_arg(ast_node *n)
{
    
    printt("init_arg\n");
    printt("sym_name: %d\n", n->init_arg.sym_name);
    printt("expr:\n");
    print_ast(n->init_arg.expr);
    
    
}
*/

static void init_ast_printers()
{
    if (g_ast_printers[0]) return;
    g_ast_printers[AST_LIST] = print_list;
    g_ast_printers[AST_FUNCDEF] = print_funcdef;
    g_ast_printers[AST_FUNCHEAD] = print_funchead;
    g_ast_printers[AST_PARA] = print_para;
    g_ast_printers[AST_STDEF] = print_stdef;
    g_ast_printers[AST_VAR] = print_var;
    g_ast_printers[AST_SUBVAR] = print_subvar;
    g_ast_printers[AST_COMPOUND_STMT] = print_compound_stmt;
    g_ast_printers[AST_EXPR_STMT] = print_expr_stmt;
    g_ast_printers[AST_IF_STMT] = print_if_stmt;
    g_ast_printers[AST_FOR_STMT] = print_for_stmt;
    g_ast_printers[AST_RETURN_STMT] = print_return_stmt;
    g_ast_printers[AST_CONTINUE_STMT] = print_continue_stmt;
    g_ast_printers[AST_BREAK_STMT] = print_break_stmt;
    g_ast_printers[AST_DEF] = print_def;
    g_ast_printers[AST_DEC] = print_dec;
    g_ast_printers[AST_BINOP] = print_binop;
    g_ast_printers[AST_PREFIX] = print_prefix;
    g_ast_printers[AST_POSTFIX] = print_postfix;
    g_ast_printers[AST_INDEXING] = print_indexing;
    g_ast_printers[AST_FUNC_CALL] = print_func_call;
    g_ast_printers[AST_MEMBER] = print_member;
    g_ast_printers[AST_ID] = print_id;
    g_ast_printers[AST_CONST] = print_const;
    // g_ast_printers[AST_INIT_ARG] = print_init_arg;
}

void print_ast(ast_node *n)
{
    tabs++;
    init_ast_printers();
    if (n)
    {
        g_ast_printers[n->type](n);
    }
    else
    {
        printt("NULL");
    }
    tabs--;
}
