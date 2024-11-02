#include "../include/ASM.h"
#include "../include/PseudoASM.h"
#include <ctype.h>


FILE* file;
int labNum = 0;
int cantParamFunc = -1;
char params[7][20] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};

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
    if(currentTag == T_FUNC) {
        writeFunc(instruction);
        cantParamFunc = -1;
    }
    if(currentTag == T_ASIGN)
        writeAsign(instruction);
    if(currentTag == T_IFF || currentTag == T_WF)
        writeIFF(instruction);
    if(currentTag == T_LABEL)
        writeLabel(instruction);
    if(currentTag == T_JUMP)
        writeJump(instruction);
    if(currentTag == T_LOAD_PARAM) {
        int cantParam = 0;
        writeLoadParam(instruction, cantParam);
        return;
    }
    if(currentTag == T_REQUIRED_PARAM)
        writeLoadParamInFunc(instruction);
    if(currentTag == T_CALL)
        writeCallFunc(instruction);

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
    if(strcmp(instruction->result->varname,"main") == 0){
        sprintf(buffer, ".global %s\n ",instruction->result->varname);
        writeArchive(buffer);
    } 
    sprintf(buffer, "%s:\n    pushq   %%rbp\n    movq    %%rsp, %%rbp\n",instruction->result->varname);
    writeArchive(buffer);
}

void writeLoadParamInFunc(PseudoASM* instruction) {
    char buffer[256];
    char* por = "%";
    cantParamFunc +=1;
    //writeArchive("     ;Cargando parametro\n");
    Tsymbol* param = instruction->result;
            // movl    %edi, -4(%rbp)

    sprintf(buffer, "    movl %s%s, %d(%%rbp)\n", por, params[cantParamFunc], param->offset);
    writeArchive(buffer);
   // writeArchive("     ;TERMINO CARGAR parametro\n");
}
// elegir una forma
//1-rdi, 2-rsi, 3-rdx, 4-rcx, 5-r8, 6-r9 => 64 bits
//1-edi, 2-esi, 3-edx, 4-ecx, 5-r8d, 6-r9d => 32 bits 
// 32 bits usa movl
// 64 bits usa movq

//Si cantParam es > 6, se debe pushear a la pila....
void writeLoadParam(PseudoASM* instruction, int cantParam) {
    char buffer[256];
    char por[3] = "%";
    Tsymbol *result = instruction->result;
    //writeArchive("    ;CARGANDO PARAMETRO\n");
    if(result->type == CONSINT || result->type == CONSBOOL) {
        sprintf(buffer, "    movl $%s, %s%s\n", result->varname, por, params[cantParam]);
        writeArchive(buffer);
    }
    if(result->type == EID) {
        sprintf(buffer, "    movl %d(%%rbp), %seax\n",result->offset, por);
        writeArchive(buffer);
        sprintf(buffer, "    movl %%eax, %s%s\n", por, params[cantParam]);
        writeArchive(buffer);
    }
   // writeArchive("    ;FIN DEL CARGO DE PARAMETRO\n");
    cantParam += 1;

    if(instruction->next->tag ==  T_LOAD_PARAM) {
        instruction = instruction->next;
        writeLoadParam(instruction, cantParam);
    } else {
        createWriteASM(instruction->next);
    }

}

void writeAsign(PseudoASM* instruction) {
    Tsymbol* op1 = instruction->result;
    Tsymbol* op2 = instruction->op2;
    enum TYPES typeOp2 = op2->type;
    char buffer[256];
    char* por = "%%";
    //writeArchive("    ;PRINCIPIO ASIGN\n");
    if(typeOp2 == CONSINT){
        sprintf(buffer, "    movl $%s, %d(%%rbp)\n", op2->varname, op1->offset);
    } else if(typeOp2 == CONSBOOL ){
        if(strcmp("true",op2->varname) == 0){
			sprintf(buffer, "    movl $1, %d(%%rbp)\n", op1->offset);
		}else {
			sprintf(buffer, "    movl $0, %d(%%rbp)\n", op1->offset);	
		}
    }else {
        //Primero paso el valor de la otra variable al eax
        sprintf(buffer, "    movl %d(%%rbp), %%eax\n\n", op2->offset);
        writeArchive(buffer);
        //Despues paso el valor del eax a la variable de la asignacion.
        sprintf(buffer, "    movl %%eax, %d(%%rbp)\n\n", op1->offset);
    }
    writeArchive(buffer);
    //writeArchive("    ;FINAL ASIGN\n");
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
    //cambien esto me tirava error sprintf(buffer, "    cmpl  %d(%rbp),  1\n", op1->offset);
    sprintf(buffer, "    cmpl  $1,  %d(%rbp)\n", op1->offset);
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
    sprintf(buffer, "    jmp %s\n", nameLabel);
    writeArchive(buffer);
}


void writeCallFunc(PseudoASM* instruction) {
    char buffer[256];
    char* nameLabel = instruction->op1->varname;
    sprintf(buffer, "    call %s\n", nameLabel);
    writeArchive(buffer);

    Tsymbol* result = instruction->result;
    sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
    writeArchive(buffer);
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
        
        if(op1->type == CONSBOOL){
            if(strcmp("true",op1->varname) == 0){
                sprintf(aux, "    movl $1, %%eax\n");
                writeArchive(aux);
		    	sprintf(aux, "    cmpl $0, %%eax\n");
		    }else {
                sprintf(aux, "    movl $0, %%eax\n");
                writeArchive(aux);
			    sprintf(aux, "    cmpl $0, %%eax\n");	
		    }
        }else{
            sprintf(aux, "    cmpl $0, %d(%%rbp)\n", op1->offset);
        }
        
        writeArchive(aux);

        if (tag == T_AND)
            sprintf(aux, "    je .LA%d \n", labNum+1);
        else
            sprintf(aux, "    jne .LO%d \n", labNum+1);
       
        writeArchive(aux);

        if(op2->type == CONSBOOL){
            if(strcmp("true",op2->varname) == 0){
		    	sprintf(aux, "    movl $1, %%eax\n");
                writeArchive(aux);
		    	sprintf(aux, "    cmpl $0, %%eax\n");
		    }else {
			    sprintf(aux, "    movl $0, %%eax\n");
                writeArchive(aux);
			    sprintf(aux, "    cmpl $0, %%eax\n");		
		    }
        }else{
            sprintf(aux, "    cmpl $0, %d(%%rbp)\n", op2->offset);
        }
        writeArchive(aux);

        if (tag == T_AND){
            labNum++;
            sprintf(aux, "    je .LA%d \n", labNum);
        }else{
            labNum++;
            sprintf(aux, "    je .LO%d \n", labNum+1);
        }
        writeArchive(aux);


        if (tag == T_OR) {
            sprintf(aux, ".LO%d: \n", labNum);
            writeArchive(aux);
        }

        sprintf(aux, "    movl $1, %%eax\n");
        writeArchive(aux);

        
        
        if (tag == T_AND) {
            labNum++;
            sprintf(aux, "    jmp .LA%d \n", labNum);
            writeArchive(aux);
            labNum --;
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            labNum++;
            sprintf(aux, "    jmp .LO%d \n", labNum+1);
            writeArchive(aux);
            //labNum --;
            sprintf(aux, ".LO%d: \n", labNum);
        }
        writeArchive(aux);
        sprintf(aux, "    movl $0, %%eax\n");
        writeArchive(aux);

        labNum++;
        if (tag == T_AND) {
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            sprintf(aux, ".LO%d: \n", labNum);
            //writeArchive(aux);
            //sprintf(aux, "    movb %sal, %d(%srbp) \n",por, op2->offset, por);
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

    sprintf(aux, "    movl %%eax, %d(%%rbp)\n",final->offset);
    writeArchive(aux);
    //sprintf(aux, "    movl %d(%srbp), %seax\n", op1->offset, por, por);
   // writeArchive(aux);
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
    sprintf(aux, "    movl  %seax, %d(%srbp)\n",por, final->offset, por);
    fprintf(file, aux);
    fclose(file);

}
