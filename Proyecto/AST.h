#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#ifndef AST_H
#define AST_H

enum TYPES {
    VARINT,
    VARBOOL,
    EMAIN,
    CONSINT,
    CONSBOOL,
    SUMA,
    RESTA,
    PROD,
    EOR,
    EAND,
    ENOT,
    ASIG,
    DECLA,
    SENTEN,
    ERETURN,
    OTHERS
};

typedef struct AST {
    char* varname;
    enum TYPES nodetype;
    struct Tsymbol *table;
    struct AST *left;
    struct AST *right;
} AST;

struct AST* createTree(enum TYPES type, char* c, struct AST *l, struct AST *r);

void showTree(AST* tree);

#endif
