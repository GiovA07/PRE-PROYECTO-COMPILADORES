#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol.h"
#ifndef AST_H
#define AST_H

typedef struct AST {
    struct Tsymbol *symbol;
    struct AST *left;
    struct AST *right;
} AST;

struct AST* createTree(Tsymbol* symbol, struct AST *l, struct AST *r);

void showTreeDot(AST* tree,FILE* file);
void printDot(AST* tree, const char* filename);
void elimArbol(AST* tree);

void createTable(AST* ar);
void typeError(AST* ar);
void evaluate(AST* ar);

bool getError();
void retError();

#endif
