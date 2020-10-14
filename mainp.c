#include <stdio.h>
#include <stdlib.h>
#include "ParsePascal.h"
#include "ErrVars.h"
#include "ParseTree/tree.h"
#include "ParseTree/tree_types.h"
#include "List/List.h"
#include "LexAndYacc/y.tab.h"

int main(int argc, char **argv)
{
	Tree_t * parse_tree;
	parse_tree = ParsePascal(argv[1]);
	FILE *f;
	f=fopen("parse_t1.txt", "w+");
	if(parse_tree!=NULL)
	{
		tree_print(parse_tree, f, 0);
		fprintf(stdout,"Hey, it worked\n");
	}
	fclose(f);
	return 0;
}