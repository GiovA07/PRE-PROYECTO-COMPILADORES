#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#ifndef AST_H
#define AST_H

enum TYPES {
    VAR,
    FUNC,
    CONS,
    OTHERS
};

typedef struct AST {
    char* varname;
    enum TYPES nodetype;
    struct Tsymbol *table;
    struct AST *left;
    struct AST *right;
} AST;

AST createTree(enum TYPES type, char* c, struct AST *l, struct AST *r);

void showTree(AST tree);

#endif
