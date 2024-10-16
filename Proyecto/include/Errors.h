#include <stdio.h>
#include <stdbool.h>
#include "AST.h"
#include "symbol.h"

#ifndef ERRORS_H
#define ERRORS_H

void errorAsig(AST *ar, bool* err);
void errorNot(AST* ar, bool* err);
void errorCond(AST *ar, bool* err);
void errorOpera(AST *ar, enum TYPES type, bool* err);
void errorRet(AST* ar, enum TYPES type, bool* err);
void evaluate_op_condiciones(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err);
void evaluate_op_booleanos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err);
void evaluate_op_aritmeticos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err);

void errorCall(AST *ar,  bool *err);
void recorrer(AST *ar, int tipos[], int* index, int maxArg, int size, bool *err);
#endif
