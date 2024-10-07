#include <stdio.h>
#include <stdlib.h>
#include <symbol.h>
#include "AST.h"

#ifndef PSEUDOASM_H
#define PSEUDOASM_H

enum ASM_TAG {
    ASIGN,
    IF, WHILE,
    OR, NOT, AND,
    IGUAL, MAYOR, MENOR,
    SUMA, RESTA, RESTO, PRODUCTO, DIVISION
};

typedef struct PseudoASM {
    ASM_TAG tag;
    Tsymbol* op1;
    Tsymbol* op2;
    Tsymbol* result;
    PseudoASM* next;
} PseudoASM;


PseudoASM* instructions;

PseudoASM* traslate(enum ASM_TAG tag, AST* op1, AST* op2);

#endif