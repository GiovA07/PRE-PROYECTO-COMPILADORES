#include <stdio.h>
#include <stdlib.h>
#include "AST.h"

#ifndef PSEUDOASM_H
#define PSEUDOASM_H

enum ASM_TAG {
    T_ASIGN,
    T_IF, T_WHILE,
    T_OR, T_NOT, T_AND,
    T_IGUAL, T_MAYOR, T_MENOR,
    T_SUM, T_RES, T_MOD, T_PROD, T_DIV
};

typedef struct PseudoASM {
    enum ASM_TAG tag;
    Tsymbol* op1;
    Tsymbol* op2;
    Tsymbol* result;
    PseudoASM* next;
} PseudoASM;


PseudoASM* instructions = NULL;


void deleteInstructions();
void generateCode(AST* ar);
PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res);

#endif