#include "../include/PseudoASM.h"
#include <string.h>


PseudoASM* instructions = NULL;
// PseudoASM* current2 = NULL;
// bool p = true;

int labID = 1;

// para llevar cada funcion con el slato que le corresponde

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
    } else if (tag == EIF) {
        sequense->tag = T_IF;
        if(auxLeft){
            sequense->result->value = auxLeft->value;
        }else {
            sequense->result->value = op1->symbol->value;

        }
    } else{
        return instructions;
    }
}
    return sequense;
}




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


void generateThreeDir(AST* ar) {
    generateCode(ar);
    invertASM();
}


void generateCode(AST* ar) {
    
    if(((ar->symbol)->type == RETINT || (ar->symbol)->type == RETBOL ||(ar->symbol)->type == RETVOID) && (strcmp((ar->symbol)->varname,"MAIN") != 0) ){
        handleGenerateFunc(ar);
        createRetTag(ar->symbol);
        createTagForFunction(T_END_FUN, ar->symbol);
    }else if((ar->symbol)->type == CALL_F){
        generateLoadParams(ar->right);
        generateCallFunc(ar);
    }else if((ar->symbol)->type  == EIF){
        handleGenerateIF(ar);
    } else if ((ar->symbol)->type  == EWHILE) {
        handleGenerateWhile(ar);
    }else if ((ar->right != NULL && ar->left != NULL)) {
        handleGenerateBinaryOperation(ar);
    }else if (ar->left != NULL) {
        handleUnaryOp(ar);
    }else if (ar->right != NULL) {
        generateCode(ar->right);
    }
}

void generateLoadParams(AST* ar) {
    if(ar->left != NULL)
        generateLoadParams(ar->left);
    if(ar->right != NULL)
        generateLoadParams(ar->right);

    // printf("Nombre: %s, Tipo: %s \n", ar->symbol->varname, string[ar->symbol->type]);

    if (ar->symbol->type == EID || ar->symbol->type == VARINT || ar->symbol->type == VARBOOL) {
        PseudoASM* param = (PseudoASM*)malloc(sizeof(PseudoASM));
        param->tag = T_LOAD_PARAM;
        char * name1 = "_";
        param->op1 = CreateSymbol(name1,OTHERS,0,0);
        param->op2 =  CreateSymbol(name1,OTHERS,0,0);
        param->result = CreateSymbol(ar->symbol->varname,OTHERS,0,0);

        param->next = instructions;
        instructions = param;
    }
}

 void handleGenerateFunc(AST* ar){
    createTagForFunction(T_FUNC,ar->symbol);
    // genero codigo de la funcion para funciones externas
    if(ar->right != NULL) {
        generateCode(ar->right);
    }
 }
 
 void createTagForFunction(enum ASM_TAG tag , Tsymbol* func){
    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));
    sequense->tag = tag;
    
    char * name1 = "_";
    sequense->op1 = CreateSymbol(name1,OTHERS,0,0);
    sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);
    sequense->result = CreateSymbol(func->varname,OTHERS,0,0);
    
    sequense->next = instructions;
    instructions = sequense;

 }
 
 void createRetTag(Tsymbol* func){
    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));
    sequense->tag = T_RETURN;
    
    char * name1 = " ";
    sequense->op1 = CreateSymbol(name1,OTHERS,0,0);
    sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);
    sequense->result = CreateSymbol(name1,OTHERS,0,0);
    
    sequense->next = instructions;
    instructions = sequense;

 }

void generateCallFunc(AST*ar){
    PseudoASM* callFunc = (PseudoASM*)malloc(sizeof(PseudoASM));
    char * name = "_";
    callFunc->tag = T_CALL;

    callFunc->op1 = CreateSymbol(name,OTHERS,0,0);
    callFunc->op2 =  CreateSymbol(name,OTHERS,0,0); 

    callFunc->result = ar->left->symbol;

    callFunc->next = instructions;
    instructions = callFunc;
}



void handleGenerateIF(AST* ar) {
    generateCode(ar->left);
    PseudoASM* IFF = createTagForFalse(T_IFF,  ar->left->symbol);
    char* labelIFF = (char*) malloc(10 * sizeof(char));
    strcpy(labelIFF, IFF->result->varname);

    IFF->next = instructions;
    instructions = IFF;

    enum TYPES tipoActual = (ar->symbol)->type;
    struct Tsymbol* auxLeft = LookupVar(ar->left->symbol->varname);

    if((strcmp((ar->symbol)->varname,"if_then") == 0)){
        generateCode(ar->right);
        createAndAppendTagLabel(labelIFF);

    } else if((strcmp((ar->symbol)->varname,"if_else") == 0)){
        generateCode((ar->right)->left);  //then
        //create jump
        PseudoASM* jump = createJump();
        jump->next = instructions;
        instructions = jump;
        //label_else
        createAndAppendTagLabel(labelIFF);
        generateCode((ar->right)->right->left); //else

        //create labelend_jump
        createAndAppendTagLabel(jump->result->varname);
    }
}
void handleGenerateWhile(AST* ar) {
    PseudoASM* jump = createJump();
    //label jump para volver a ejecutar el WHILE
    createAndAppendTagLabel(jump->result->varname);
    //IFF en caso que no se cumpla la condicion saltar a...
    PseudoASM* conditionFalse = createTagForFalse(T_WF,  ar->left->symbol);
    conditionFalse->next = instructions;
    instructions = conditionFalse;
    generateCode(ar->right);    //instrucciones dentro del while
    jump->next = instructions;
    instructions = jump;
    // create label IFF en caso que no se cumpla la condicion del WHILE
    createAndAppendTagLabel(conditionFalse->result->varname);
}
void handleGenerateBinaryOperation(AST* ar) {
    enum TYPES tipoActual = (ar->symbol)->type;

    if (ar->left != NULL) {
        generateCode(ar->left);
    }
    if (ar->right != NULL) {
        generateCode(ar->right);
    }


    bool isAsignBool = tipoActual == ASIG || tipoActual == EAND || tipoActual == EOR || tipoActual == EEQ || tipoActual == EMAYORQUE || tipoActual == EMENORQUE;
    bool isAritmet = tipoActual == SUMA || tipoActual == RESTA || tipoActual == PROD || tipoActual == ERESTO || tipoActual == EDIV;
    if (isAsignBool || isAritmet) {
        PseudoASM* pseudoAsm = traslate(tipoActual, ar->left, ar->right, ar);
        pseudoAsm->next = instructions;
        instructions = pseudoAsm;
    }
}

void handleUnaryOp(AST* ar) {
    generateCode(ar->left);
    if ((ar->symbol)->type  == ENOT) {
        PseudoASM* not = traslate((ar->symbol)->type, ar->left,NULL, ar);
        not->next = instructions;
        instructions = not;
    }
}
void invertASM() {
    PseudoASM* prev = NULL;
    PseudoASM* current = instructions;
    PseudoASM* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    instructions = prev;
}
void deleteInstructions() {
    //printFuncJum();
    PseudoASM* current = instructions;
    PseudoASM* next = NULL;

    while (current != NULL) {
        next = current->next;
        if (current->tag == T_IFF) {
            free(current->op2);
            free(current->result);
        } else if (current->tag == T_JUMP || current->tag == T_LABEL) {
            free(current->op1);
            free(current->op2);
            free(current->result);
        }
        free(current);
        current = next;
    }
    //deleteFuncTable();
}
void printAsembler() {
    PseudoASM* current = instructions;

    printf("\nInstructions\n");

    while (current != NULL) {
        if (current->op1 && current->op2) {
            printf("%s %s %s %s\n", tagName[current->tag], current->op1->varname, current->op2->varname, current->result->varname);
        }else if (!current->op1 && current->op2){
            printf("%s   %s %s\n", tagName[current->tag], current->op2->varname, current->result->varname);
        }else if (current->op1 && !current->op2){
            printf("%s %s   %s\n", tagName[current->tag], current->op1->varname, current->result->varname);
        }else{
            printf("%s     %s\n", tagName[current->tag], current->result->varname);
        }
        current = current->next;
    }
}

PseudoASM* createTagForFalse(enum ASM_TAG tag, Tsymbol* condition) {
    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));

    sequense->tag = tag;
    sequense->op1 = condition;

    char * name1 = "_";
    sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);

    char* name = generateNameLabel();

    sequense->result = CreateSymbol(name,OTHERS,0,0);

    return sequense;
}
PseudoASM* createJump() {
    PseudoASM* jump = (PseudoASM*)malloc(sizeof(PseudoASM));

    jump->tag = T_JUMP;
    char * name1 = "_";
    jump->op1 = CreateSymbol(name1,OTHERS,0,0);
    jump->op2 =  CreateSymbol(name1,OTHERS,0,0);

    char* name = generateNameLabel();

    jump->result = CreateSymbol(name,OTHERS,0,0);

    return jump;
}
char* generateNameLabel() {
    char* nameLabel = (char*) malloc(10 * sizeof(char));
    sprintf(nameLabel, "L%d", labID);
    labID++;
    return nameLabel;
}
void createAndAppendTagLabel(char* nameLabel) {
    PseudoASM* label = (PseudoASM*)malloc(sizeof(PseudoASM));
    char * name1 = "_";
    label->tag = T_LABEL;
    label->op1 =  CreateSymbol(name1,OTHERS,0,0);
    label->op2 =  CreateSymbol(name1,OTHERS,0,0);
    label->result = CreateSymbol(nameLabel,OTHERS,0,0);
    label->next = instructions;
    instructions = label;

}
