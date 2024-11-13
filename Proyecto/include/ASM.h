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
void writeBooleanOp(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag);
void writeComparation(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag);

void writeVarGlobal(PseudoASM* instruction);
void writeIFF(PseudoASM* instruction);
void writeLabel(PseudoASM* instruction);
void writeJump(PseudoASM* instruction);
void writeLoadParam(PseudoASM* instruction, int cantParam);
void writeEndFunc(PseudoASM* instruction);
void writeLoadParamInFunc(PseudoASM* instruction);
void writeCallFunc(PseudoASM* instruction);
#endif
