#include <stdio.h>
#include <stdlib.h>
#include "AST.h"
// #include "AsmFunc.h"

#ifndef PSEUDOASM_H
#define PSEUDOASM_H

enum ASM_TAG {
    T_ASIGN, T_RETURN,
    T_IF, T_WHILE,
    T_OR, T_NOT, T_AND,
    T_IGUAL, T_MAYOR, T_MENOR,
    T_SUM, T_RES, T_MOD, T_PROD, T_DIV,
    T_LABEL, T_JUMP, T_END_FUN, T_LOAD_PARAM,
    T_IFF, T_RET , T_WF, T_FUNC, T_CALL, T_INFO,T_REQUIRED_PARAM,T_GLOBAL
};

char static tagName[42][42] = {
    "ASIGN", "RETURN",
    "IF", "WHILE",
    "OR", "NOT", "AND",
    "IGUAL", "MAYOR", "MENOR",
    "SUM", "RES", "MOD", "PROD", "DIV",
    "T_LABEL", "T_JUMP", "END_FUN", "LOAD_PARAM",
    "T_IFF", "T_RET","T_WF","T_FUNC", "T_CALL","T_INFO","T_REQUIRED_PARAM","T_GLOBAL"
};

typedef struct PseudoASM {
    enum ASM_TAG tag;
    Tsymbol* op1;
    Tsymbol* op2;
    Tsymbol* result;
    struct PseudoASM* next;
} PseudoASM;

void invertASM();
void printAsembler();
void deleteInstructions();
void generateCode(AST* ar);
void handleGenerateIF(AST* ar);
void handleGenerateWhile(AST* ar);
void handleGenerateBinaryOperation(AST* ar);
void handleUnaryOp(AST* ar);
void handleGenerateFunc(AST* ar);
void generateThreeDir(AST* ar);
void createRetTag(Tsymbol* func);
void generateLoadParams(AST* ar);
void has_Call_Func(AST* ar);
void createSentenThreeDir(enum ASM_TAG tag , Tsymbol* func);
void handleGenerateMain(AST* ar);
void createTagLoad(Tsymbol* symbol);
void createCall_Func(Tsymbol* nameFunc, Tsymbol* tempResult);
PseudoASM* createTagForFalse(enum ASM_TAG tag, Tsymbol* condition);
PseudoASM* createJump();
void createAndAppendTagLabel(char* nameLabel);
char* generateNameLabel();
void handleGenerateOpReturn(AST* ar);
void requireParams(AST* ar);
void createCodRequiredParam(Tsymbol* param);


void addOffSetFuncParams(AST* ar);
void addOffSetFuncBody(AST* ar);
void addOffSet(AST* ar);

struct PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res);
struct Tsymbol *LookupVar(char * name);



void generateAssembler();

#endif
