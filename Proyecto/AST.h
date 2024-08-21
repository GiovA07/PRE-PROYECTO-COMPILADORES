
#include <stdio.h>
#include <stdlib.h>

typedef struct AST {
    int* val;
    int type;
    char* id;
    int nodetype;
    AST *left, *right;
} AST;


struct AST* createTree(int val, int type, char* c, struct AST *l, struct AST *r);