// main() function which drives the whole parsing process.

#include <stdio.h>
#include "converter_java.h"
#include "y.tab.h"


static ast_node *g_parse_tree;

void yyerror(char const *s)
{
    fprintf(stdout, "Error.\n");
    fprintf(stderr, "%s\n", s);
}

void set_parse_tree(ast_node *tree)
{
    g_parse_tree = tree;
}

int main(int argc, char **argv)
{
    yyparse();

    if (g_parse_tree)
    {
        if( argc>1 && !strcmp(argv[1],"p"))
        	print_ast(g_parse_tree);
        else
            transtext_ast(g_parse_tree, argv[1]);
    }
	
    return 0;
}
