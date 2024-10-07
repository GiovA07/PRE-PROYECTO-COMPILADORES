#include "../include/PseudoASM.h"


PseudoASM* instructions = NULL;


PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res) {

    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));

    sequense->op1 = op1->symbol;
    sequense->op1 = op2->symbol;
    sequense->result = res->symbol;

    if (tag == ASIG) {
        sequense->tag = T_ASIGN;
        sequense->result->value = op1->symbol->value;
    } else if (tag == SUMA) {
        sequense->tag = T_SUM;
        sequense->result->value = op1->symbol->value + op2->symbol->value;
    } else if (tag == RESTA) {
        sequense->tag = T_RES;
        sequense->result->value = op1->symbol->value - op2->symbol->value;
    } else if (tag == PROD) {
        sequense->tag = T_PROD;
        sequense->result->value = op1->symbol->value * op2->symbol->value;
    } else if (tag == EDIV) {
        sequense->tag = T_DIV;
        if (op2->symbol->value != 0)
            sequense->result->value = op1->symbol->value / op2->symbol->value;
        else
            printf("Error en la division, division por cero no permitido");
    } else if (tag == ERESTO) {
        sequense->tag = T_MOD;
        sequense->result->value = op1->symbol->value % op2->symbol->value;
    } else if (tag == ENOT) {
        sequense->tag = T_NOT;
        if (op1->symbol->value == 0)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == EAND) {
        sequense->tag = T_AND;
        if (op1->symbol->value == op2->symbol->value && op1->symbol->value == 1)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == EOR) {
        sequense->tag = T_OR;
        if (1 == op2->symbol->value || op1->symbol->value == 1)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == EMAYORQUE) {
        sequense->tag = T_MAYOR;
        sequense->result->value = op1->symbol->value > op2->symbol->value? 1 : 0;
    } else if (tag == EMENORQUE) {
        sequense->tag = T_MENOR;
        sequense->result->value = op1->symbol->value < op2->symbol->value? 1 : 0;
    } else if (tag == EEQ) {
        sequense->tag = T_IGUAL;
        sequense->result->value = op1->symbol->value == op2->symbol->value? 1 : 0;
    } else if (tag == EIF) {
        sequense->tag = T_IF;
        if (op1->symbol->value == 1)
            sequense->result = op2->left->symbol;
        else
            sequense->result = op2->right->symbol;
    } else if (tag == EWHILE) {
        sequense->tag = T_WHILE;
        if (op1->symbol->value == 1)
            sequense->result = op2;
        else
            sequense->result = NULL;
    } else {
        return instructions;
    }
    
    
    return sequense;
}

void generateCode(AST* ar) {

    PseudoASM* subSequense = traslate(ar->left->symbol->type, ar->left->left, ar->left->right, ar->left);
    subSequense->next = traslate(ar->right->symbol->type, ar->right->left, ar->right->right, ar->right);

    subSequense->next = traslate(ar->symbol->type, ar->left, ar->right, ar);

    instructions = subSequense;
}

void deleteInstructions() {
    PseudoASM* current = instructions;
    PseudoASM* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void printAsembler() {
    PseudoASM* current = instructions;

    printf("\nInstructions\n");
    while (current != NULL) {
        printf("%s %s %s %s\n", tagName[current->tag], current->op1->id, current->op2->id, current->result->id);
        current = current->next;
    }   
}