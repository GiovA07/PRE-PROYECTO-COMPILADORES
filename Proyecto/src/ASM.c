#include "../include/ASM.h"
#include "../include/PseudoASM.h"
#include <ctype.h>


FILE* file;

void createFile() {
    file = fopen("result.s", "w");
    if (file == NULL) {
        printf("Error al crear el archivo result.s\n");
        return;
    }
    fclose(file);
}

void writeArchive(char* string) {
    file = fopen("result.s","a");
    if (file == NULL) {
        printf("Error Escribir archivo");
        return;
    }
    fprintf(file, "%s", string);
    fclose(file);
}

void createWriteASM(PseudoASM* instruction) {
    if(instruction->tag == T_FUNC)
        writeFunc(instruction);
    if(instruction->tag == T_ASIGN){
        writeAsign(instruction);
    }
    if(instruction->tag == T_SUM || instruction->tag == T_RES || instruction->tag == T_DIV || instruction->tag == T_PROD || instruction->tag == T_MOD)
        writeOperation(instruction->op1, instruction->op2, instruction->result, instruction->tag);
    if(instruction->tag == T_RETURN) {
        writeReturn(instruction);
    }
    if(instruction->next != NULL)
        createWriteASM(instruction->next);
}


void writeFunc(PseudoASM* instruction) {
    char buffer[256];
    sprintf(buffer, "%s:\n    pushq   %%rbp\n    movq    %%rsp, %%rbp\n",instruction->result->varname);
    writeArchive(buffer);
}

void writeAsign(PseudoASM* instruction) {
    Tsymbol* op1 = instruction->result;
    Tsymbol* op2 = instruction->op2;
    enum TYPES typeOp2 = op2->type; 
    char buffer[256];
    char* por = "%%";
    if(typeOp2 == CONSBOOL || typeOp2 == CONSINT){        
        sprintf(buffer, "    movl $%s, %d(%%rbp)\n", op2->varname, op1->offset);
    } else {
        //Primero paso el valor de la otra variable al eax
        sprintf(buffer, "    movl %d(%%rbp), %%eax\n\n", op2->offset);
        writeArchive(buffer);
        //Despues paso el valor del eax a la variable de la asignacion.
        sprintf(buffer, "    movl %%eax, %d(%%rbp)\n\n", op1->offset);
    }
    writeArchive(buffer);
}

void writeReturn(PseudoASM* instruction) {
    Tsymbol* result = instruction->result;
    enum TYPES typeResult = result->type; 
    char buffer[256];

    // writeArchive("    ;Return: \n"); //borrar [--][==] [ O ] ]--[
    // Guarda el valor de la variable a retornar en eax
    sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
    writeArchive(buffer);
    // Revierte el rbp de la pila antes a donde estaba antes de ser llamada.
    writeArchive("    popq    %rbp\n");
    // Finaliza la funion y regresa la ejecucion al punto donde fue llamada.
    writeArchive("    ret\n");
    // writeArchive("    ;FINAL del Return.\n"); //borrar
}


void writeOperation(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag){

    file = fopen("result.s","a");
    if (file == NULL) {
        printf("Error Escribir archivo");
        return;
    }

    char aux[100];
    char* por = "%%";

    if(op1->type == CONSINT)
        sprintf(aux, "    movl $%s, %sedx\n", op1->varname, por);
    else
        sprintf(aux, "    movl %d(%srbp), %sedx\n", op1->offset, por, por);
    
    fprintf(file,aux);
    
    if (tag == T_SUM || tag == T_RES || tag == T_PROD) {
        if(op2->type == CONSINT)
            sprintf(aux, "    movl $%s, %seax\n", op2->varname, por);
        else
            sprintf(aux, "    movl %d(%srbp), %seax\n", op2->offset, por, por);
        
        fprintf(file,aux);
    
        if (tag == T_SUM)
            fprintf(file, "    addl %%edx, %%eax\n");
        else if (tag == T_RES)
            fprintf(file, "    subl %%edx, %%eax\n");
        else
            fprintf(file, "    imull %%edx, %%eax\n");
        sprintf(aux, "    movl %seax, %d(%srbp)\n", por, final->offset, por);
        fprintf(file,aux);
    } else if (tag == T_DIV || tag == T_MOD) {
        fprintf(file, "    cltd\n");
        if(op2->type == CONSINT)
            sprintf(aux, "    idivl $%s\n", op2->varname);
        else
            sprintf(aux, "    idivl %d(%srbp)\n", op2->offset, por);
        fprintf(file,aux);

        if (tag == T_DIV)
            sprintf(aux, "    movl %seax, %d(%srbp)\n", por, final->offset, por);
        else
            sprintf(aux, "    movl %sedx, %d(%srbp)\n", por, final->offset, por);
        fprintf(file,aux);
        
        sprintf(aux, "    $0, %seax\n", por);
        fprintf(file, aux);
    }
    fclose(file);    
}
