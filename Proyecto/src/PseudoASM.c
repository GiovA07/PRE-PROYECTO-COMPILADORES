#include "../include/PseudoASM.h"


PseudoASM* instructions = NULL;


struct PseudoASM* traslate(enum TYPES tag, AST* op1, AST* op2, AST* res) {

    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));

    sequense->op1 = op1->symbol;
    
    if(op2 != NULL) {
        sequense->op2 = op2->symbol;
    }else {
        sequense->op2 = NULL;
    }
    sequense->result = res->symbol;    
    
    if(op2 == NULL){
        // solo lo creo para que se ve en el printf sino tira error 
        char * name = "NULL";
        sequense->op2 = CreateSymbol(name,OTHERS,0,0);
        if (tag == ENOT) {
            sequense->tag = T_NOT;
            Tsymbol *auxLeft = LookupVar(op1->symbol->varname);
            if (auxLeft != NULL) {
                 sequense->result->value =  (!auxLeft->value);
            } else {
                //generateCode(op1);
                sequense->result->value = (!(op1->symbol->value));
            }
        }
    }else {

    Tsymbol *auxLeft = LookupVar(op1->symbol->varname);
    Tsymbol *auxRigth = LookupVar(op2->symbol->varname);

    if (tag == ASIG) {
        sequense->tag = T_ASIGN;
        //guardo todo el nodo arbol
        if(auxRigth){
            sequense->op1->value = auxRigth->value;
            sequense->result = sequense->op1;
        }else {
            sequense->op1->value = sequense->op2->value;
            sequense->result = sequense->op1;
        }

    } else if (tag == SUMA) {
        sequense->tag = T_SUM;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value = auxRigth->value + auxLeft->value;
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value = op2->symbol->value + auxLeft->value;
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = auxRigth->value + op1->symbol->value;
        } else {
            sequense->result->value = op2->symbol->value  + op1->symbol->value;
        }
    } else if (tag == RESTA) {
        
        sequense->tag = T_RES;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  auxLeft->value - auxRigth->value;
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  auxLeft->value - op2->symbol->value;
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value - auxRigth->value;
        } else {
             sequense->result->value = op1->symbol->value - op2->symbol->value;
        }
    } else if (tag == PROD) {
        sequense->tag = T_PROD;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  auxLeft->value * auxRigth->value;
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  auxLeft->value * op2->symbol->value;
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value * auxRigth->value;
        } else {
            sequense->result->value = op1->symbol->value * op2->symbol->value;
        }
    } else if (tag == EDIV) {
        sequense->tag = T_DIV;
        if (auxRigth != NULL && auxLeft != NULL) {
            if(auxRigth->value == 0) {
                printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                exit(1);
            }else {
                sequense->result->value =  auxLeft->value / auxRigth->value;
            }
        } else if (auxRigth == NULL && auxLeft != NULL) {
            if(op2->symbol->value == 0) {
                printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                exit(1);
            }else {
                sequense->result->value =  auxLeft->value / op2->symbol->value;
            }
        } else if(auxRigth != NULL && auxLeft == NULL){
            if(auxRigth->value == 0) {
                printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->symbol->line);
                exit(1);
            }else {
                sequense->result->value = op1->symbol->value / auxRigth->value ;
            }
        } else {
            if(op2->symbol->value == 0) {
                printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->symbol->line);
                exit(1);
            }else {
                sequense->result->value = op1->symbol->value / op2->symbol->value;
            }
        }
    } else if (tag == ERESTO) {
        sequense->tag = T_MOD;
        if (auxRigth != NULL && auxLeft != NULL) {
            if(auxRigth->value == 0) {
                printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                exit(1);
            }else {
                sequense->result->value =  auxLeft->value % auxRigth->value;
            }
        } else if (auxRigth == NULL && auxLeft != NULL) {
            if(op2->symbol->value == 0) {
                printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                exit(1);
            }else {
                sequense->result->value =  auxLeft->value % op2->symbol->value;
            }
        } else if(auxRigth != NULL && auxLeft == NULL){
            if(auxRigth->value == 0) {
                printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->symbol->line);
                exit(1);
            }else {
                sequense->result->value = op1->symbol->value % auxRigth->value ;
            }
        } else {
            if(op2->symbol->value == 0) {
                printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->symbol->line);
                exit(1);
            }else {
                sequense->result->value = op1->symbol->value % op2->symbol->value;
            }
        }
    } else if (tag == EAND) {
        sequense->tag = T_AND;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value = (auxLeft->value && auxRigth->value);
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value && op2->symbol->value);
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value && auxRigth->value;
        } else {
            sequense->result->value = (op1->symbol->value && op2->symbol->value);
        }
    } else if (tag == EOR) {
        sequense->tag = T_OR;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value || auxRigth->value);
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value || op2->symbol->value);
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value || auxRigth->value;
        } else {
            sequense->result->value = (op1->symbol->value || op2->symbol->value);
        }
    } else if (tag == EMAYORQUE) {
        sequense->tag = T_MAYOR;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value > auxRigth->value);
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value > op2->symbol->value);
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value > auxRigth->value;
        } else {
            sequense->result->value = (op1->symbol->value > op2->symbol->value);
        }
    } else if (tag == EMENORQUE) {
        sequense->tag = T_MENOR;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value < auxRigth->value);
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value < op2->symbol->value);
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value < auxRigth->value;
        } else {
            sequense->result->value = (op1->symbol->value < op2->symbol->value);
        }
    } else if (tag == EEQ) {
        sequense->tag = T_IGUAL;
        if (auxRigth != NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value == auxRigth->value);
        } else if (auxRigth == NULL && auxLeft != NULL) {
            sequense->result->value =  (auxLeft->value == op2->symbol->value);
        } else if(auxRigth != NULL && auxLeft == NULL){
            sequense->result->value = op1->symbol->value == auxRigth->value;
        } else {
            sequense->result->value = (op1->symbol->value == op2->symbol->value);
        }
        sequense->tag = T_WHILE;
    } else if (tag == EWHILE) {
        if (op1->symbol->value == 1)
        //ver
            sequense->result = op2->right->symbol;
        else
            sequense->result = NULL;
    } else {
        return instructions;
    }
}
    return sequense;
}
/* No hace falta
 else if (tag == EIF) {
        sequense->tag = T_IF;
        if(auxLeft){
            sequense->result->value = auxLeft->value;
        }else {
            sequense->result->value = op1->symbol->value;

        }

        
    }*/

struct Tsymbol *LookupVar(char * name){
  PseudoASM* head = instructions;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->result->varname)==0){
      return head->result;
    }
    head = head->next;
  }
  return NULL;
}

void generateCode(AST* ar) {

    //ver
    if((ar->symbol)->type  == EIF){
        generateCode(ar->left);
        enum TYPES tipoActual = (ar->symbol)->type;
        struct Tsymbol* auxLeft = LookupVar(ar->left->symbol->varname);

        if((strcmp((ar->symbol)->varname,"if_then") == 0)){
                if((auxLeft && auxLeft->value) || ar->left->symbol->value){
                    generateCode(ar->right);
                }
        }else if((strcmp((ar->symbol)->varname,"if_else") == 0)){
            if(auxLeft){
                if(auxLeft && auxLeft->value){
                    generateCode((ar->right)->left);
                }else{
                    generateCode((ar->right)->right->left);   
                }
            }else{
                if(ar->left->symbol->value){
                    generateCode((ar->right)->left);
                }else {
                    generateCode((ar->right)->right->left);
                }
            }
        }
    }else if ((ar->right != NULL && ar->left != NULL)) {
        enum TYPES tipoActual = (ar->symbol)->type;

        if (ar->left != NULL) {
            generateCode(ar->left);
        }
        if (ar->right != NULL) {
            generateCode(ar->right);
        }
        
        // if (tipoActual == EIF) {
        //     PseudoASM* eif= traslate(tipoActual, ar->left, ar->right, ar);
        //     eif->next = instructions;
        //     instructions = eif;
        // }

        if (tipoActual == ASIG) {
            PseudoASM* asig = traslate(tipoActual, ar->left, ar->right, ar);
            asig->next = instructions;
            instructions = asig;
        }

        if (tipoActual == SUMA) {
            PseudoASM* sum = traslate(tipoActual, ar->left, ar->right, ar);
            sum->next = instructions;
            instructions = sum;

        }
        
        if (tipoActual == RESTA) {
            PseudoASM* rest = traslate(tipoActual, ar->left, ar->right, ar);
            rest->next = instructions;
            instructions = rest;

        }
        if (tipoActual == PROD) {
            PseudoASM* prod = traslate(tipoActual, ar->left, ar->right, ar);
            prod->next = instructions;
            instructions = prod;
        }

        if (tipoActual == ERESTO) {
            PseudoASM* resto = traslate(tipoActual, ar->left, ar->right, ar);
            resto->next = instructions;
            instructions = resto;
        }

        if (tipoActual == EDIV) {
            PseudoASM* div = traslate(tipoActual, ar->left, ar->right, ar);
            div->next = instructions;
            instructions = div;
        }

        if (tipoActual == EAND) {
            PseudoASM* and = traslate(tipoActual, ar->left, ar->right, ar);
            and->next = instructions;
            instructions = and;
        }


        if (tipoActual == EOR) {
            PseudoASM* or = traslate(tipoActual, ar->left, ar->right, ar);
            or->next = instructions;
            instructions = or;
        }

        if (tipoActual == EEQ) {
            PseudoASM* eq = traslate(tipoActual, ar->left, ar->right, ar);
            eq->next = instructions;
            instructions = eq;

        }

        if (tipoActual == EMAYORQUE) {            
            PseudoASM* may = traslate(tipoActual, ar->left, ar->right, ar);
            may->next = instructions;
            instructions = may;
        }

        if (tipoActual == EMENORQUE) {
            PseudoASM* men = traslate(tipoActual, ar->left, ar->right, ar);
            men->next = instructions;
            instructions = men;

        }
    }else if (ar->left != NULL) {
            generateCode(ar->left);
            if ((ar->symbol)->type  == ENOT) {
                PseudoASM* not = traslate((ar->symbol)->type, ar->left,NULL, ar);
                not->next = instructions;
                instructions = not; 
            }
    }else if (ar->right != NULL) { 
            generateCode(ar->right);
    }
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
        printf("%s %s %s %s->%d\n", tagName[current->tag], current->op1->varname, current->op2->varname, current->result->varname,current->result->value);
        current = current->next;
    }   
}

