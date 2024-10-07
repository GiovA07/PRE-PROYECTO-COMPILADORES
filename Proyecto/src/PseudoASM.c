#include "../include/PseudoASM.h"


PseudoASM* traslate(enum ASM_TAG tag, AST* op1, AST* op2) {

    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));

    sequense->tag = tag;
    sequense->op1 = op1->symbol;
    sequense->op1 = op2->symbol;

    if (tag == ASIGN) {
        sequense->result->value = op1->symbol->value;
    } else if (tag == SUMA) {
        sequense->result->value = op1->symbol->value + op2->symbol->value;
    } else if (tag == RESTA) {
        sequense->result->value = op1->symbol->value - op2->symbol->value;
    } else if (tag == PRODUCTO) {
        sequense->result->value = op1->symbol->value * op2->symbol->value;
    } else if (tag == DIVISION) {
        if (op2->symbol->value != 0)
            sequense->result->value = op1->symbol->value / op2->symbol->value;
        else
            printf("Error en la division, division por cero no permitido");
    } else if (tag == RESTO) {
        sequense->result->value = op1->symbol->value % op2->symbol->value;
    } else if (tag == NOT) {
        if (op1->symbol->value == 0)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == AND) {
        if (op1->symbol->value == op2->symbol->value && op1->symbol->value == 1)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == OR) {
        if (1 == op2->symbol->value || op1->symbol->value == 1)
            sequense->result->value = 1;
        else
            sequense->result->value = 0;
    } else if (tag == MAYOR) {
        sequense->result->value = op1->symbol->value > op2->symbol->value? 1 : 0;
    } else if (tag == MENOR) {
        sequense->result->value = op1->symbol->value < op2->symbol->value? 1 : 0;
    } else if (tag == MAYOR) {
        sequense->result->value = op1->symbol->value == op2->symbol->value? 1 : 0;
    } else if (tag == IF) {
        if (op1->symbol->value == 1)
            sequense->result = op2->left->symbol;
        else
            sequense->result = op2->right->symbol;
    } else {
        if (op1->symbol->value == 1)
            sequense->result = op2;
        else
            sequense->result = NULL;
    }
    
    return sequense;
}