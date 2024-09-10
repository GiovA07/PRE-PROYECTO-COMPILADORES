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

void showTree(AST* tree);

void showTreeDot(AST* tree,FILE* file);
void printDot(AST* tree, const char* filename);

void createTable(AST* ar);
void typeError(AST* ar);
void errorOpera(AST *ar, enum TYPES type);
void errorAsig(AST *ar);
bool getError();
void evaluate(AST* ar);
void errorRet(AST* ar,enum TYPES type);
void retError();
#endif
