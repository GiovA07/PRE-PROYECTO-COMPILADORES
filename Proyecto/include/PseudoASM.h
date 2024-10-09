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
    T_SUM, T_RES, T_MOD, T_PROD, T_DIV,
    T_LABEL, T_JUMP,
    T_IFF, T_RET
};

char static tagName[25][25] = {
    "ASIGN",
    "IF", "WHILE",
    "OR", "NOT", "AND",
    "IGUAL", "MAYOR", "MENOR",
    "SUM", "RES", "MOD", "PROD", "DIV",
    "T_LABEL", "T_JUMP",
    "T_IFF", "T_RET"
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
PseudoASM* createTagForFalse(enum ASM_TAG tag, Tsymbol* condition);
PseudoASM* createJump();
PseudoASM* createTagLabel(char* nameLabel);

struct PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res);
struct Tsymbol *LookupVar(char * name);

#endif
