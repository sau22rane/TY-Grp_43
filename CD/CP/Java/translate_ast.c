#include "converter_java.h"


typedef void (*ast_translator)(ast_node *n);

static ast_translator g_ast_translators[AST_WHILE_STMT];
static const char* g_ast_names[AST_WHILE_STMT];

int dec_init = 0;
int condition = 0;

void emit(const char *fmt, ...)
{
    va_list args;
    char buffer[1024], format[1024];

    va_start(args, fmt);
    vsnprintf(buffer, sizeof buffer, fmt, args);
    va_end(args);

    sprintf(format, "%s", buffer);

    fprintf(stdout, "%s", format);
}

char *split = "";
int tabn = 0;
void emit_tab() {
	for (int i = 0; i < tabn; ++i) {
		emit("\t");
	}
}

static void trans_list(ast_node *n)
{   static int count= 0;
    count++;
    int tcount = count;
    // printf("\nStarting %dth list\n",tcount);
    for (; n; n = n->list.tail)
    {
        trans_ast(n->list.head);
        if (n->list.tail) emit("%s", split);
    }
    // printf("\nClosing %dth list\n",tcount);
}

static void trans_funcdef(ast_node *n)
{
	char *s;
	if (n->funcdef.ret_type == 1) s = "int";
	else if (n->funcdef.ret_type == 2) s = "float";
	else if (n->funcdef.ret_type == 3) s = "char";
	
	emit_tab();
    emit("static %s ", s);
    trans_ast(n->funcdef.funchead);
    emit(" {\n");
	split = "";
	++tabn;
    trans_ast(n->funcdef.funcbody);
    --tabn;
    emit("\n");
    emit_tab();
    emit("}\n");
}

static void trans_funchead(ast_node *n)
{	
	char *s = symname(n->funchead.sym_name);
	if (!strcmp(s, "main")) {
		emit("main_(int argc, String[] args) ");
		return;
	}
    emit("%s (", s);
    split = ", ";
    trans_ast(n->funchead.paras);
	split = "";
    emit(") ");
}

static void trans_para(ast_node *n)
{
	char *s = "";
	if (n->para.para_type == 1) s = "int";
	else if (n->para.para_type == 2) s = "float";
	else if (n->para.para_type == 3) s = "char";
    emit("%s ", s);
    trans_ast(n->para.var);
}

int inclass = 0;

static void trans_stdef(ast_node *n)
{
	emit_tab();
	emit("static class %s {\n", symname(n->stdef.sym_name));
	split = ";\n";
	++tabn;
	inclass = 1;
    trans_ast(n->stdef.defs);
    --tabn;
    inclass = 0;
	split = "";
	emit_tab();
    emit("};\n");
}

int inarray = 0;
int array_depth = 0;
int index1[100];
int need_brac = 0;
char *cur_type = "";
char *cur_struct_varname = "";

static void trans_def(ast_node *n)
{	
	char *s = "";
    if (condition == 0)
    	emit_tab();
	if (n->fg == 'g') {
		emit("static ");
	}
	if (inclass) emit("public ");
	if (n->def.def_type == 1) {
		s = "int";
		cur_type = s;
	}
	else if (n->def.def_type == 2) {
		s = "float";
		cur_type = s;
	}
	else if (n->def.def_type == 3) {
		s = "char";
		cur_type = s;
	}
	else {
		 s = "[]";
	}
    emit("%s ", s);
	split = ", ";
	trans_ast(n->def.decs);
    split = "";
	emit(";");
    if (need_brac == 1) emit(" }");
    need_brac = 0;
    if (condition == 0)
        emit("\n");
    
}

static void trans_dec(ast_node *n)
{
	array_depth = 0;
	if (n->dec.init) dec_init = 1;
	else dec_init = 0;
    trans_ast(n->dec.var);
    
    if (n->dec.init)
    {	
    	emit(" = ");
        ast_node *p = n->dec.init;
        if (p->type == AST_LIST)
        {
            emit("{");
        	trans_ast(n->dec.init);
        	emit("}");
        }
        else
        {
        	trans_ast(n->dec.init);
        }
    }
}

static void trans_var(ast_node *n)
{
   emit("%s", symname(n->var.sym_name));
}

int cur_array_depth = 0;

static void trans_subvar(ast_node *n)
{
	inarray = 1;
	if (dec_init == 0) {
		++cur_array_depth;
		emit("[]");
		if (n->subvar.var->type != AST_SUBVAR) {
			emit(" ");
			trans_ast(n->subvar.var);
			emit(";\n");
			emit_tab();
			if (n->fg == 'g') emit("static { ");
			trans_ast(n->subvar.var);
			cur_struct_varname = symname(n->subvar.var->var.sym_name);
			emit(" = new %s", cur_type);
		}
		else trans_ast(n->subvar.var);
		emit("[");
		emit("%d", n->subvar.index);
		emit("]");
		index1[cur_array_depth] = n->subvar.index;
		if (!array_depth) array_depth = cur_array_depth;
		--cur_array_depth;
		if (n->fg == 'g' && cur_array_depth == 0) need_brac = 1;
	}
	else {
		trans_ast(n->subvar.var);
		emit("[]");
	}
}

static void trans_compound_stmt(ast_node *n)
{
	split = "";
	trans_ast(n->compound_stmt.defs);
    trans_ast(n->compound_stmt.stmts);
}

static void trans_expr_stmt(ast_node *n)
{	
	emit_tab();
    trans_ast(n->expr_stmt.expr);
    emit(";\n");
}

static const char * binop_instr(int op)
{
    switch (op)
    {
    case ADD_ASSIGN:
        return "+=";
    case SUB_ASSIGN:
        return "-=";
    case MUL_ASSIGN:
        return "*=";
    case DIV_ASSIGN:
        return "/=";
    case MOD_ASSIGN:
        return "%=";
    case AND_ASSIGN:
        return "&=";
    case OR_ASSIGN:
        return "|=";
    case XOR_ASSIGN:
        return "^=";
    case SHL_ASSIGN:
        return "<<=";
    case SHR_ASSIGN:
        return ">>=";
    case GE_OP:
        return ">=";
    case LE_OP:
        return "<=";
    case EQ_OP:
        return "==";
    case NE_OP:
        return "!=";
    case SHL_OP:
        return "<<";
    case SHR_OP:
        return ">>";
    case AND_OP:
		return "&&";
	case OR_OP:
		return "||";
	case '+':
        return "+";
    case '-':
        return "-";
    case '*':
        return "*";
    case '/':
        return "/";
    case '%':
        return "%";
    case '^':
        return "^";
    case '&':
        return "&";
    case '|':
        return "|";
    case '>':
        return ">";
    case '<':
        return "<";
	case '=':
		return "=";
    }
    return "Error??";
}

static int check_bool(int op) {
	switch (op)
	{
	case GE_OP:
        return 1;
    case LE_OP:
        return 1;  
	case '>':
        return 1;
    case '<':
        return 1;
    case EQ_OP:
        return 1;
    case NE_OP:
        return 1;
	case AND_OP:
		return 1;
	case OR_OP:
		return 1;
	}
	return 0;
}

int check_bool_lr_bool(int op) {
	switch (op)
	{
	case AND_OP:
		return 1;
	case OR_OP:
		return 1;
	}
	return 0;
}


static void trans_bool(ast_node *n, int mustbool) {
	if (!mustbool) {
		trans_ast(n);
		return;
	}
	if (n->type == AST_PREFIX) {
		if (n->prefix.op == '!') {
			emit("(");
			trans_bool(n->prefix.unary, 0);
			emit(") == 0");
			return;
		}
	}
	if (n->type == AST_CONST) {
		emit("%d != 0", n->constant.number);
	}	
	if (n->type == AST_ID) {
		char *s = symname(n->id.sym_name);
		emit("%s != 0", s);
	}
	if (n->type == AST_MEMBER) {
		emit("(");
		trans_ast(n->member.postfix);
    	emit(".");
    	emit(symname(n->member.sym_name));
    	emit(") != 0");
	}
	if (n->type == AST_FUNC_CALL) {
		emit("(");	
		trans_ast(n->func_call.postfix);
		emit("(");
		if (n->func_call.args) {
			split = ", ";
			trans_ast(n->func_call.args);
			split = "";
		}
		emit(")) != 0");
	}
	if (n->type == AST_INDEXING) {
		emit("(");
	    trans_ast(n->indexing.postfix);
		emit("[");
		trans_ast(n->indexing.expr);
		emit("]");
		emit(") != 0");
	}
	if (n->type == AST_POSTFIX) {
		emit("(");
	    trans_ast(n->postfix.unary);
		if (n->prefix.op == INC_OP) emit("++");
		else if (n->prefix.op == DEC_OP) emit("--");
		emit(") != 0");	
	}
	if (n->type == AST_BINOP) {
		int tobebool = check_bool_lr_bool(n->binop.op);
		int alreadybool = check_bool(n->binop.op);
		if (!alreadybool) emit("(");
		trans_bool(n->binop.lhs, tobebool);
		emit(" %s ", binop_instr(n->binop.op));
		trans_bool(n->binop.rhs, tobebool);
		if (!alreadybool) emit(") != 0");
	}
}


static void trans_if_stmt(ast_node *n)
{
	emit_tab();
	emit("if (");
    trans_bool(n->if_stmt.cond, 1);
    emit(") {\n");
    ++tabn;
    trans_ast(n->if_stmt.then);
    --tabn;
    emit_tab();
    emit("}\n");
    if (n->if_stmt.els) {
    	emit_tab();
    	emit("else {\n");
    	++tabn;
    	trans_ast(n->if_stmt.els);
    	--tabn;
    	emit_tab();
    	emit("}\n");
    }
}

static void trans_for_stmt(ast_node *n)
{
	emit_tab();
	emit("for (");
    condition = 1;
    trans_ast(n->for_stmt.init);
    // emit("; ");
    condition = 0;
    trans_bool(n->for_stmt.cond, 1);
    emit("; ");
    trans_ast(n->for_stmt.incr);
	emit(") {\n");
	++tabn;
    trans_ast(n->for_stmt.body);
    --tabn;
    emit_tab();
    emit("}\n");
}

static void trans_while_stmt(ast_node *n)
{
	emit_tab();
	emit("while (");
    trans_bool(n->while_stmt.cond, 1);
	emit(") {\n");
	++tabn;
    trans_ast(n->while_stmt.body);
    --tabn;
    emit_tab();
    emit("}\n");
}

static void trans_return_stmt(ast_node *n)
{
	emit_tab();
	emit("return ");
    trans_ast(n->return_stmt.retval);
    emit(";");
}

static void trans_continue_stmt(ast_node *n)
{
	emit_tab();
    emit("continue;\n");
}

static void trans_break_stmt(ast_node *n)
{
	emit_tab();
    emit("break;\n");
}


static void trans_binop(ast_node *n)
{	
    trans_ast(n->binop.lhs);
    emit(" %s ", binop_instr(n->binop.op));
    trans_ast(n->binop.rhs);
}

static void trans_prefix(ast_node *n)
{
    if (n->prefix.op == INC_OP) emit("++");
    else if (n->prefix.op == DEC_OP) emit("--");
	else emit("%c", n->prefix.op);
    trans_ast(n->prefix.unary);
}

static void trans_postfix(ast_node *n)
{	
    trans_ast(n->postfix.unary);
    if (n->prefix.op == INC_OP) emit("++");
    else if (n->prefix.op == DEC_OP) emit("--");
}

static void trans_indexing(ast_node *n)
{	
    trans_ast(n->indexing.postfix);
    emit("[");
    trans_ast(n->indexing.expr);
    emit("]");
}

static void trans_func_call(ast_node *n)
{
    trans_ast(n->func_call.postfix);
    emit("(");
    if (n->func_call.args) {
    	split = ", ";
    	trans_ast(n->func_call.args);
    	split = "";
    }
    emit(")");
}

static void trans_member(ast_node *n)
{
    trans_ast(n->member.postfix);
    emit(".");
    emit(symname(n->member.sym_name));
}

static void trans_id(ast_node *n) {
	char *s = symname(n->id.sym_name);
	if (!strcmp(s, "write")) s = "System.out.println";
	else if (!strcmp(s, "read")) s = "in.nextInt";
	else if (!strcmp(s, "main")) s = "main_";
	emit("%s", s);
}

static void trans_const(ast_node *n) {
	emit("%d", n->constant.number);
}

int binop_reuse(int op)
{
    switch (op)
    {
    case '=':
    case ADD_ASSIGN:
    case SUB_ASSIGN:
    case MUL_ASSIGN:
    case DIV_ASSIGN:
    case MOD_ASSIGN:
    case AND_ASSIGN:
    case OR_ASSIGN:
    case XOR_ASSIGN:
    case SHL_ASSIGN:
    case SHR_ASSIGN:
        return 1;
    }
    return 0;
}


static void init_ast_translators()
{
    if (g_ast_translators[0]) return;

    g_ast_translators[AST_LIST] = trans_list;
    g_ast_translators[AST_FUNCDEF] = trans_funcdef;
    g_ast_translators[AST_FUNCHEAD] = trans_funchead;
    g_ast_translators[AST_PARA] = trans_para;
    g_ast_translators[AST_STDEF] = trans_stdef;
    g_ast_translators[AST_VAR] = trans_var;
    g_ast_translators[AST_SUBVAR] = trans_subvar;
    g_ast_translators[AST_COMPOUND_STMT] = trans_compound_stmt;
    g_ast_translators[AST_EXPR_STMT] = trans_expr_stmt;
    g_ast_translators[AST_IF_STMT] = trans_if_stmt;
    g_ast_translators[AST_FOR_STMT] = trans_for_stmt;
    g_ast_translators[AST_RETURN_STMT] = trans_return_stmt;
    g_ast_translators[AST_CONTINUE_STMT] = trans_continue_stmt;
    g_ast_translators[AST_BREAK_STMT] = trans_break_stmt;
    g_ast_translators[AST_DEF] = trans_def;
    g_ast_translators[AST_DEC] = trans_dec;
    g_ast_translators[AST_BINOP] = trans_binop;
    g_ast_translators[AST_PREFIX] = trans_prefix;
    g_ast_translators[AST_POSTFIX] = trans_postfix;
    g_ast_translators[AST_INDEXING] = trans_indexing;
    g_ast_translators[AST_FUNC_CALL] = trans_func_call;
    g_ast_translators[AST_MEMBER] = trans_member;
    g_ast_translators[AST_ID] = trans_id;
    g_ast_translators[AST_CONST] = trans_const;
    g_ast_translators[AST_WHILE_STMT] = trans_while_stmt;

}

void trans_ast(ast_node *n)
{
    init_ast_translators();
    if (n){
        g_ast_translators[n->type](n);
    }
}



int main_sym;

void transtext_ast(ast_node *n, char *name)
{	
	emit("import java.util.*;\n\n");
	char *s = symname(3);
	s = strtok(s, ".");
    emit("public class %s\n{\n", name);
    ++tabn;
    emit_tab();
    emit("static Scanner in = new Scanner(System.in);\n");   
    
    trans_ast(n);
    
    emit("\tpublic static void main(String[] args) {\n");
    emit("\t\tSystem.exit(main_(args.length, args));\n\t}\n");
    emit("}\n");
}
