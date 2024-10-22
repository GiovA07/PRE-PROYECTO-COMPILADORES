#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol.h"
#include "PseudoASM.h"
#ifndef ASM_H
#define ASM_H

void createFile();
void createWriteASM(PseudoASM* instruction);
void writeAsign(PseudoASM* instruction);
void writeReturn(PseudoASM* instruction);
void writeFunc(PseudoASM* instruction);
void writeOperation(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag);
void writeEq(Tsymbol* op1, Tsymbol* op2, Tsymbol* final);
#endif
