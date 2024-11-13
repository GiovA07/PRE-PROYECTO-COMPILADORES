#include "../include/PseudoASM.h"
#include "../include/ASM.h"
#include <string.h>

//para cargar los paramteros que tienen mas de 6
PseudoASM* ParamsMayorSeis = NULL;
PseudoASM* instructions = NULL;

int labID = 1;
int paramReq  = 0;
// para llevar cada funcion con el slato que le corresponde

void createInstallSequence(enum ASM_TAG tag, Tsymbol* op1, Tsymbol* op2, Tsymbol* result){
    PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));
    sequense->tag = tag;
    sequense->op1 = op1;
    sequense->op2 = op2;
    sequense->result = result;
    sequense->next = instructions;
    instructions = sequense;
}

void operComparate(enum TYPES tag,Tsymbol* op1, Tsymbol* op2, Tsymbol* res){
    Tsymbol *auxLeft = LookupVar(op1->varname);
    Tsymbol *auxRigth = LookupVar(op2->varname);
    switch(tag){
        case  EMAYORQUE:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value =  (auxLeft->value > auxRigth->value);
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value =  (auxLeft->value > op2->value);
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value > auxRigth->value;
            } else {
                res->value = (op1->value > op2->value);
            }
            createInstallSequence(T_MAYOR,op1, op2,res);
            break;
        case  EMENORQUE:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value =  (auxLeft->value < auxRigth->value);
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value =  (auxLeft->value < op2->value);
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value < auxRigth->value;
            } else {
                res->value = (op1->value < op2->value);
            }
            createInstallSequence(T_MENOR,op1, op2, res);
            break;
        case  EEQ:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = (auxLeft->value == auxRigth->value);
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = (auxLeft->value == op2->value);
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value == auxRigth->value;
            } else {
                res->value = (op1->value == op2->value);
            }
            createInstallSequence(T_IGUAL,op1,  op2, res);
            break;
        }
}

void operBoolean(enum TYPES tag,Tsymbol* op1, Tsymbol* op2, Tsymbol* res){
    Tsymbol *auxLeft = LookupVar(op1->varname);
    Tsymbol *auxRigth = LookupVar(op2->varname);
    switch(tag){   
        case  EAND:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = (auxLeft->value && auxRigth->value);
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = (auxLeft->value && op2->value);
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value && auxRigth->value;
            } else {
                res->value = (op1->value && op2->value);
            }
            createInstallSequence(T_AND,op1,  op2, res);
            break;
        case  EOR:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = (auxLeft->value || auxRigth->value);
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = (auxLeft->value || op2->value);
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value || auxRigth->value;
            } else {
                res->value = (op1->value || op2->value);
            }
            createInstallSequence(T_OR,op1, op2, res);
            break;
    }

}

void operAritmetic(enum TYPES tag,Tsymbol* op1, Tsymbol* op2, Tsymbol* res){
    Tsymbol *auxLeft = LookupVar(op1->varname);
    Tsymbol *auxRigth = LookupVar(op2->varname);
    switch(tag){
        case SUMA:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = auxRigth->value + auxLeft->value;
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = op2->value + auxLeft->value;
            } else if(auxRigth != NULL && auxLeft == NULL) {
                res->value = auxRigth->value + op1->value;
            } else {
                res->value = op2->value  + op1->value;
            }
            createInstallSequence(T_SUM,op1, op2, res);
            break;
        case RESTA:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = auxLeft->value - auxRigth->value;
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = auxLeft->value - op2->value;
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value - auxRigth->value;
            } else {
                res->value = op1->value - op2->value;
            } 
            createInstallSequence(T_RES,op1, op2, res);
            break;
        case PROD:
            if (auxRigth != NULL && auxLeft != NULL) {
                res->value = auxLeft->value * auxRigth->value;
            } else if (auxRigth == NULL && auxLeft != NULL) {
                res->value = auxLeft->value * op2->value;
            } else if(auxRigth != NULL && auxLeft == NULL){
                res->value = op1->value * auxRigth->value;
            } else {
                res->value = op1->value * op2->value;
            }
            createInstallSequence(T_PROD,op1, op2, res);
            break;
        case  EDIV:
            if (auxRigth != NULL && auxLeft != NULL) {
                if(auxRigth->value == 0 && auxRigth->type == CONSINT) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }else {
                    res->value =  auxLeft->value / auxRigth->value;
                }
            } else if (auxRigth == NULL && auxLeft != NULL) {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }else {
                    res->value =  auxLeft->value / op2->value;
                }
            } else if(auxRigth != NULL && auxLeft == NULL){
                if(auxRigth->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }else {
                    res->value = op1->value / auxRigth->value ;
                }
            } else {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }else {
                    res->value = op1->value / op2->value;
                }
            }
            createInstallSequence(T_DIV,op1, op2, res);
            break;
        case  ERESTO:
            if (auxRigth != NULL && auxLeft != NULL) {
                if(auxRigth->value == 0 && auxRigth->type == CONSINT) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }else {
                    res->value =  auxLeft->value % auxRigth->value;
                }
            } else if (auxRigth == NULL && auxLeft != NULL) {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }else {
                    res->value =  auxLeft->value % op2->value;
                }
            } else if(auxRigth != NULL && auxLeft == NULL){
                if(auxRigth->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }else {
                    res->value = op1->value % auxRigth->value ;
                }
            } else {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }else {
                    res->value = op1->value % op2->value;
                }
            }
            createInstallSequence(T_MOD,op1, op2, res);
            break;
        }
}

void traslate(enum TYPES tag, AST* op1, AST* op2, AST* res) {
    Tsymbol * op1Symbol = op1->symbol;
    Tsymbol * op2Symbol = NULL;
    Tsymbol * resSymbol = res->symbol;
    
    Tsymbol *auxRigth = NULL;
    Tsymbol *auxLeft = LookupVar(op1->symbol->varname);

    if(op2 != NULL){
        op2Symbol = op2->symbol;
        auxRigth = LookupVar(op2->symbol->varname);
    }

    switch(tag){
        case ASIG:
            if(auxRigth){
                op1Symbol->value = auxRigth->value;
                resSymbol = op1Symbol;
            }else {
                op1Symbol->value = op2Symbol->value;
                resSymbol = op1Symbol;
            }
            createInstallSequence(T_ASIGN,op1Symbol,op2Symbol,resSymbol);
            break;
        case SUMA: case RESTA: case PROD: case EDIV: case ERESTO:
            operAritmetic(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case  EAND: case  EOR:
            operBoolean(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case  EMAYORQUE: case  EMENORQUE: case  EEQ:
            operComparate(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case EWHILE:
            if (op1Symbol->value == 1)
                resSymbol = op2->right->symbol;
            else
                resSymbol = NULL;
            break;
            createInstallSequence(T_WHILE,op1Symbol,op2Symbol,resSymbol);
        case EIF:
            if(auxLeft){
                resSymbol->value = auxLeft->value;
            }else {
                resSymbol->value = op1Symbol->value;
            }
            createInstallSequence(T_IF,op1Symbol,op2Symbol,resSymbol);
            break;
        case ENOT:
            if (auxLeft != NULL) {
                resSymbol->value =  (!auxLeft->value);
            } else {
                resSymbol->value = (!(op1Symbol->value));
            } 
            createInstallSequence(T_NOT,op1Symbol,op2Symbol,resSymbol);
            break;
    }
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
    invertASM(&instructions);
}

void generateVarGlobals(){
    Tsymbol * aux = getTable();
    while(aux != NULL) {
        Tsymbol * recorrert = aux->table;
        while(recorrert != NULL) {
            if(recorrert->type == VARINT || recorrert->type == VARBOOL ){
                char * name1 = "_";
                createInstallSequence(T_GLOBAL, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), recorrert);
            }
        recorrert = recorrert->next;
        }
        aux = aux->next;
    }
}

void generateCode(AST* ar) {
    enum TYPES tipoActual = ar->symbol->type;
    switch(tipoActual){
        case ERETURN:
            handleGenerateOpReturn(ar);
            createRetTag(ar->left->symbol);
            break;
        case RETINT: case RETBOL: case RETVOID:
            if (strcmp((ar->symbol)->varname,"main") == 0) {
                handleGenerateMain(ar);
                createSentenThreeDir(T_END_FUN, ar->symbol);
            } else {
                handleGenerateFunc(ar);
                paramReq = 0;
                createSentenThreeDir(T_END_FUN, ar->symbol);
            }
            break;
        case CALL_F:
            has_Operation(ar->right);
            has_Call_Func(ar->right);
            generateLoadParams(ar->right);
            createCall_Func(ar->left->symbol, ar->symbol);
            break;
        case EIF:
            handleGenerateIF(ar);
            break;
        case EWHILE:
            handleGenerateWhile(ar);
            break;
        default:
            if(strcmp((ar->symbol)->varname,"PROGRAM") == 0){
                generateVarGlobals();
            }
            if ((ar->right != NULL && ar->left != NULL)) {
                handleGenerateBinaryOperation(ar);
            }else if (ar->left != NULL) {
                handleUnaryOp(ar);
            }else if (ar->right != NULL) {
                generateCode(ar->right);
            }
            break;
    }
}

void handleGenerateOpReturn(AST* ar) {
    if (ar->left != NULL)
        generateCode(ar->left);
    if (ar->right != NULL)
        generateCode(ar->right);
}

void handleGenerateMain(AST* ar){
    createSentenThreeDir(T_FUNC,ar->symbol);
    if (ar->left != NULL)
        generateCode(ar->left);
    if (ar->right != NULL)
        generateCode(ar->right);
 }

void has_Operation(AST* ar){
    if(ar == NULL) return;

    if(ar->left)
        has_Operation(ar->left);    
    if(ar->right)
        has_Operation(ar->right);   
    enum TYPES tipoActual = ar->symbol->type;
    bool operArit = (tipoActual == SUMA || tipoActual == RESTA || tipoActual == PROD || tipoActual == EDIV || tipoActual == ERESTO);
    bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
    bool operCondi = (tipoActual == EMAYORQUE || tipoActual == EMENORQUE || tipoActual == EEQ);
    if(operArit || operBool || operCondi){
        generateCode(ar);
    }
}

void has_Call_Func(AST* ar) {
    if(ar == NULL) return;
   
    if(ar->left)
        has_Call_Func(ar->left);

    if(ar->right)
        has_Call_Func(ar->right);

    if (ar->symbol->type == CALL_F) {
        generateLoadParams(ar->right);
        createCall_Func(
            ar->left->symbol, ar->symbol);
    }    
}

void generateLoadParams(AST* ar) {
    if(ar == NULL) return;

    enum TYPES tipoActual = ar->symbol->type;

    if (tipoActual != ARGS) {
        createTagLoad(ar->symbol);
    }
    bool notOperArit = (tipoActual != SUMA && tipoActual != RESTA && tipoActual != PROD && tipoActual != EDIV && tipoActual != ERESTO);
    bool notOperBool = (tipoActual != EOR && tipoActual != EAND && tipoActual != ENOT );
    bool notOperCondi = (tipoActual != EMAYORQUE && tipoActual != EMENORQUE && tipoActual != EEQ);
    bool ifNotType = (tipoActual != CALL_F && (notOperArit && notOperBool && notOperCondi));
    if(ifNotType) {
        if(ar->left != NULL){
            generateLoadParams(ar->left);
        }
        if(ar->right != NULL){
            generateLoadParams(ar->right);
        }
    }

}

void createTagLoad(Tsymbol* symbol) {
    char * name1 = "_";
    createInstallSequence(T_LOAD_PARAM, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), symbol);
}

void concatenarListas(PseudoASM *lista1, PseudoASM *lista2) {
    if (lista2 == NULL) {
        return;
    }    
    PseudoASM * actual = lista2;
    while (actual->next != NULL) {
        actual = actual->next;
    }
    actual->next = lista1;
    instructions = lista2;
}

void handleGenerateFunc(AST* ar){
    createSentenThreeDir(T_FUNC,ar->symbol);
    if(ar->left != NULL) {
        requireParams(ar->left);
        invertASM(&ParamsMayorSeis);
        concatenarListas(instructions,ParamsMayorSeis);
        ParamsMayorSeis = NULL;
    }
    if(ar->right != NULL) {
        generateCode(ar->right);
    }
    if(ar->symbol->type == RETVOID){
        char * name1 = " ";
        createInstallSequence(T_RETURN, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), CreateSymbol(name1,OTHERS,0,0));
    }
 }


void requireParams(AST* ar) {
    if(ar->symbol->type == PARAMBOOL || ar->symbol->type == PARAMINT){
        paramReq += 1;
        createCodRequiredParam(ar->symbol);
    }
    if(ar->left)
        requireParams(ar->left);
    if(ar->right)
        requireParams(ar->right);
 }

 void createCall_Func(Tsymbol* nameFunc, Tsymbol* tempResult){
    char * name1 = "_";
    createInstallSequence(T_CALL, nameFunc,CreateSymbol(name1,OTHERS,0,0), tempResult);
 }

 void createSentenThreeDir(enum ASM_TAG tag , Tsymbol* func){
    char * name1 = "_";
    createInstallSequence(tag, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), func);
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
    generateCode(ar->left);
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
        traslate(tipoActual, ar->left, ar->right, ar);
    }
}

void handleUnaryOp(AST* ar) {
    generateCode(ar->left);
    if ((ar->symbol)->type  == ENOT) {
       // printf("Entro offset %d\n",ar->symbol->offset);
        traslate((ar->symbol)->type, ar->left,NULL, ar);
    }
}

void invertASM(PseudoASM ** list) {
    PseudoASM* prev = NULL;
    PseudoASM* current = *list;
    PseudoASM* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}
void deleteInstructions() {
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
    char * name1 = "_";
    createInstallSequence(T_LABEL,CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0),CreateSymbol(nameLabel,OTHERS,0,0));
}

void createRetTag(Tsymbol* func){
    char * name1 = " ";
    createInstallSequence(T_RETURN,CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0),func);
}

void createCodRequiredParam(Tsymbol* param){
    if( paramReq > 6) {
        PseudoASM* sequense = (PseudoASM*)malloc(sizeof(PseudoASM));
        sequense->tag = T_REQUIRED_PARAM;
        char * name1 = " ";
        sequense->op1 = CreateSymbol(name1,OTHERS,0,0);
        sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);
        sequense->result = param;
        sequense->next = ParamsMayorSeis;
        ParamsMayorSeis = sequense;
    }else {
        char * name1 = " ";
        createInstallSequence(T_REQUIRED_PARAM,CreateSymbol(name1,OTHERS,0,0), CreateSymbol(name1,OTHERS,0,0), param);
    }
}

void generateAssembler() {
    createFile();
    createWriteASM(instructions);
}
