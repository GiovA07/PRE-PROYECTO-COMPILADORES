#include "../include/ASM.h"
#include "../include/PseudoASM.h"
#include <ctype.h>


FILE* file;
int labNum = 0;

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
    enum ASM_TAG currentTag = instruction->tag;
    if(currentTag == T_FUNC)
        writeFunc(instruction);
    if(currentTag == T_ASIGN)
        writeAsign(instruction);
    if(currentTag == T_IFF)
        writeIFF(instruction);
    if(currentTag == T_LABEL)
        writeLabel(instruction);

    if(currentTag == T_JUMP)
        writeJump(instruction);


    if(currentTag == T_SUM || currentTag == T_RES || currentTag == T_DIV || currentTag == T_PROD || currentTag == T_MOD)
        writeOperation(instruction->op1, instruction->op2, instruction->result, currentTag);
    else if (currentTag == T_NOT || currentTag == T_AND || currentTag == T_OR)
        writeBooleanOp(instruction->op1, instruction->op2, instruction->result, currentTag);
    else if(instruction->tag == T_IGUAL || instruction->tag == T_MENOR || instruction->tag == T_MAYOR) {
        writeComparation(instruction->op1, instruction->op2, instruction->result, instruction->tag);
    }else if(instruction->tag == T_RETURN) {
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
    writeArchive("    ;PRINCIPIO ASIGN\n");
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
    writeArchive("    ;FINAL ASIGN\n");
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


void writeIFF(PseudoASM* instruction) {

    Tsymbol* op1 = instruction->op1;
    Tsymbol* result = instruction->result;
    char buffer[256];
    char* por = "%%";
    //Compara si es true
    sprintf(buffer, "    cmpl %d(%rbp), 1\n", op1->offset);
    writeArchive(buffer);
    //salto por falso
    char* nameLabel = result->varname;
    sprintf(buffer, "    jne %s\n", nameLabel);
    writeArchive(buffer);
}

void writeLabel(PseudoASM* instruction) {
    char buffer[256];
    writeArchive("\n\n");
    char* nameLabel = instruction->result->varname;
    sprintf(buffer, "%s: \n", nameLabel);
    writeArchive(buffer);
}


void writeJump(PseudoASM* instruction) {
    char buffer[256];
    char* nameLabel = instruction->result->varname;
    sprintf(buffer, "    jump %s\n", nameLabel);
    writeArchive(buffer);
}

//1-rdi, 2-rsi, 3-rdx, 4-rcx, 5-r8, 6-r9
char static params[6][3] = {"rdi","rsi","rdx","rcx","r8","r9"};
int cantParam = 0;
void writeLoadParam(PseudoASM* instruction) {

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


void writeBooleanOp(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag){

    char aux[100];
    char* por = "%%";

    if (tag == T_AND || tag == T_OR){

        if(op1->type == CONSBOOL)
            sprintf(aux, "    comb $0, $%d\n", op2->offset);
        else
            sprintf(aux, "    comb $0 %d(%srbp)\n", op2->offset, por);

        writeArchive(aux);

        if (tag == T_AND)
            sprintf(aux, "    je .LA%d \n", labNum);
        else
            sprintf(aux, "    je .LO%d \n", labNum);
        writeArchive(aux);
        labNum++;

        if(op1->type == CONSBOOL)
            sprintf(aux, "    comb $0, $%d\n", op1->offset);
        else
            sprintf(aux, "    comb $0 %d(%srbp)\n", op1->offset, por);
        writeArchive(aux);

        if (tag == T_AND)
            sprintf(aux, "    je .LA%d \n", labNum-1);
        else
            sprintf(aux, "    je .LO%d \n", labNum);
        writeArchive(aux);

        if (tag == T_OR) {
            sprintf(aux, ".LO%d: \n", labNum);
            writeArchive(aux);
        }

        sprintf(aux, "    movl $1, %seax\n", por);
        writeArchive(aux);

        if (tag == T_AND) {
            labNum++;
            sprintf(aux, "    jmp .LA%d \n", labNum);
            writeArchive(aux);
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            labNum+=2;
            sprintf(aux, "    jmp .LO%d \n", labNum);
            writeArchive(aux);
            sprintf(aux, ".LO%d: \n", labNum);
        }
        writeArchive(aux);
        sprintf(aux, "    movl $0, %seax\n", por);
        writeArchive(aux);

        labNum++;
        if (tag == T_AND) {
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            sprintf(aux, ".LO%d: \n", labNum);
            writeArchive(aux);
            sprintf(aux, "    movb %sal, %d(%srbp) \n",por, op2->offset, por);
        }
        writeArchive(aux);

    } else {
        sprintf(aux, "    cmpl  $0, %d(%srbp)\n", op1->offset, por);
        writeArchive(aux);
        sprintf(aux, "    sete  %sal\n", por);
        writeArchive(aux);
        sprintf(aux, "    movzbl  %sal, %seax\n", por, por);
        writeArchive(aux);
    }

    sprintf(aux, "     movl %sal, %d(%srbp)\n", por, final->offset, por);
    writeArchive(aux);
    sprintf(aux, "     movl %d(%srbp), %seax\n", op1->offset, por, por);
    writeArchive(aux);
}


void writeComparation(Tsymbol* op1, Tsymbol* op2, Tsymbol* final, enum ASM_TAG tag){
    file = fopen("result.s","a");
    if (file == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    
    char aux[30];
    char* por = "%%";


    if(op1->type == CONSBOOL || op1->type == CONSINT)
        sprintf(aux, "    movl $%s , %seax \n", op1->varname,por);
    else
        sprintf(aux, "    movl %d(%srbp) , %seax\n ", op1->offset, por,por);

    fprintf(file, aux);

    if(op2->type == CONSBOOL || op2->type == CONSINT)
        sprintf(aux, "   cmpl  $%s , %seax \n", op2->varname,por);
    else
        sprintf(aux, "   cmpl %d(%srbp) , %seax\n", op2->offset, por,por);

    fprintf(file, aux);

    if(tag == T_IGUAL)
        fprintf(file, "    sete %%al\n");
    if(tag == T_MAYOR)
        fprintf(file, "    setg %%al\n");
    if(tag == T_MENOR)
        fprintf(file, "    setl %%al\n");
    //movb    %al, -5(%rbp)
    
    sprintf(aux, "    movzbl %sal, %seax\n", por, por);
    fprintf(file, aux);
    sprintf(aux, "    movl  %seax %d(%srbp)\n",por, final->offset, por);
    fprintf(file, aux);
    fclose(file);

}
