
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AST {
    int val;
    int type;
    char id[50];
    int nodetype; //valor de los no hojas
    struct AST *left;
    struct AST *right;
} AST;


AST createTree(int val, int type, char* c, struct AST *l, struct AST *r);
void showTree(AST tree);

