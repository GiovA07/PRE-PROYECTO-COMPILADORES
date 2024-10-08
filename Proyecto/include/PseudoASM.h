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

char static tagName[15][15] = {
    "ASIGN",
    "IF", "WHILE",
    "OR", "NOT", "AND",
    "IGUAL", "MAYOR", "MENOR",
    "SUM", "RES", "MOD", "PROD", "DIV"
};

typedef struct PseudoASM {
    enum ASM_TAG tag;
    Tsymbol* op1;
    Tsymbol* op2;
    Tsymbol* result;
    struct PseudoASM* next;
} PseudoASM;


void printAsembler();
void deleteInstructions();
void generateCode(AST* ar);
struct PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res);
struct Tsymbol *LookupVar(char * name);

#endif