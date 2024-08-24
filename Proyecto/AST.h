#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#ifndef AST_H
#define AST_H

typedef struct AST {
    int val;
    char* varname;
    int type;
    int nodetype;
    struct Tsymbol *table;
    struct AST *left;
    struct AST *right;
} AST;

AST createTree(int val, int type, char* c, struct AST *l, struct AST *r);

void showTree(AST tree);

#endif
