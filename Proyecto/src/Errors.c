
#include "../include/Errors.h"


bool isTypeAritmetic(enum TYPES type) {
    return (type == SUMA || type == RESTA || type == PROD || type == CONSINT || type == ERESTO || type == EDIV );
}
bool isTypeBool(enum TYPES type) {
    return (type == EOR || type == EAND || type == ENOT || type == CONSBOOL || type == EMAYORQUE || type == EMENORQUE || type == EEQ);
}
bool esComparador(enum TYPES tipo) {
    return tipo == EMAYORQUE || tipo == EMENORQUE || tipo == EEQ;
}


void errorCond(AST *ar, bool* err) {
    int size = (ar->symbol)->size;
    Tsymbol* tableAuxIzq = LookupTable(size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq){
        if(tipoIzq == CALL_F){
            Tsymbol *typeFunc = Lookup((ar->left)->left->symbol->varname);
            if(typeFunc->type != RETBOL){
                printf("\033[31mError de tipo en la funcion llamada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(!isTypeBool(tipoIzq) && !esComparador(tipoIzq)){
            printf("\033[31mError de tipo en la condicion \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }else{
        if(auxIzq->type != VARBOOL){
            printf("\033[31mError de tipo en la variable usada en la condicion \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorNot(AST* ar, bool* err) {
    // Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq && !isTypeBool(tipoIzq) && !esComparador(tipoIzq)){
        printf("\033[31mError de tipo, operacion no definida, dentro del NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    }else if(auxIzq->type != VARBOOL){
        printf("\033[31mError de tipo en el valor en la negacion con NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    }
}

void errorRet(AST* ar,enum TYPES type, bool* err){
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    //Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    enum TYPES tipoActualIzq = ((ar->left)->symbol)->type;
    if(type == RETVOID ){
            printf("\033[31mError de tipo de retorno \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
    } else {
        if(!auxIzq){
            if(tipoActualIzq == CALL_F){
                    Tsymbol *typeFunc = Lookup((ar->left)->left->symbol->varname);
                if((type == RETINT && typeFunc->type != RETINT) || (type == RETBOL && typeFunc->type != RETBOL)){
                    printf("\033[31mError de tipo de retorno, tipo de funcion invalido \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                    *err = true;
                }
            }else if((type == RETINT && !isTypeAritmetic(tipoActualIzq)) || (type == RETBOL && !isTypeBool(tipoActualIzq) && !esComparador(tipoActualIzq))) {
                printf("\033[31mError de tipo de retorno, valor esperado de tipo incorrecto \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if((auxIzq && auxIzq->type != VARBOOL && type == RETBOL) || (auxIzq && auxIzq->type != VARINT && type == RETINT)){
            printf("\033[31mError de tipo de retorno, expresion de valor incorrecto \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}


void errorAsig(AST *ar, bool *err){
    Tsymbol* tableAuxDer = LookupTable(((ar->right)->symbol)->size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);

    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorBoolDer = !isTypeBool(tipoDer);
    bool errorCondDer = !esComparador(tipoDer);

    if(auxIzq == NULL && tipoIzq == EID) {
        printf("\033[33mVariable en asignacion no declarada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer != NULL && auxIzq->type != auxDer->type) {
        printf("\033[31mError de tipo en la asignacion, tipo incompatible \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer == NULL) {
        if (tipoDer == EID){
            printf("\033[33mVariable a asignar no declarada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }else if(tipoDer == CALL_F){
            Tsymbol *typeFunc = Lookup((ar->right)->left->symbol->varname);
            if((auxIzq->type == VARINT && typeFunc->type != RETINT) || (auxIzq->type == VARBOOL && typeFunc->type != RETBOL)){
                printf("\033[31mError de tipo en la asignacion, tipo de la funcion incompatible \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if((auxIzq->type == VARINT && errorIntDer) || (auxIzq->type == VARBOOL && errorBoolDer)) {
            printf("\033[31mError de tipo, error de tipo en la asignacion \033[0m, error en la linea: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    }
}

void errorOpera(AST *ar, enum TYPES type, bool* err){

    int size = (ar->symbol)->size;
    Tsymbol* tableAuxDer = LookupTable(size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);

    Tsymbol* tableAuxIzq = LookupTable(size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorIzq = !isTypeAritmetic(tipoIzq);


    if(type == SUMA || type == RESTA || type == PROD || type == ERESTO || type == EDIV) {

        evaluate_op_aritmeticos(ar, auxIzq, auxDer, err);

    } else if(type == EOR || type == EAND || type == ENOT){

        evaluate_op_booleanos(ar, auxIzq, auxDer, err);

    }else {
        evaluate_op_condiciones(ar, auxIzq, auxDer, err);
    }
}

void evaluate_op_condiciones(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err){
    int lineErrLeft = ((ar->left)->symbol)->line;
    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorSintacticoDer = esComparador(tipoDer);

    bool errorIntIzq = !isTypeAritmetic(tipoIzq);
    bool errorSintacticoIzq = esComparador(tipoIzq);

    if(auxIzq && auxDer){
        if(auxIzq->type != VARINT || auxDer->type != VARINT){
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
        if ((!auxDer && tipoDer == EID) ^ (!auxIzq && tipoIzq == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
            if(tipoDer == CALL_F){
                Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
                if((auxIzq->type != VARINT || typeFuncDer->type != RETINT)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }else {
                Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                if((auxDer->type != VARINT || typeFuncIzq->type != RETINT)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if(auxIzq->type != VARINT || errorIntDer) {
            if(errorSintacticoDer){
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }else{
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
    } else if(auxIzq == NULL && auxDer == NULL){
        if (tipoIzq == EID || tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if(tipoDer == CALL_F){
            Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
            if(typeFuncDer->type != RETINT){
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if(tipoIzq == CALL_F){
            Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
            if(typeFuncIzq->type != RETINT){
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n",lineErrLeft);
                *err = true;
            }
        }
        if((errorIntIzq && tipoIzq != CALL_F) || (errorIntDer &&  tipoDer != CALL_F)){
            if(errorSintacticoIzq || errorSintacticoDer){
                printf("\033[31mError Sintactico \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }else{
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
    }
}


void evaluate_op_booleanos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err) {
    int lineErrLeft = ((ar->left)->symbol)->line;
    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    bool errorBoolDer = !isTypeBool(tipoDer) && !esComparador(tipoDer);
    bool errorBoolIzq = !isTypeBool(tipoIzq) && !esComparador(tipoDer);
    if(auxIzq && auxDer){
        if(auxIzq->type != VARBOOL || auxDer->type != VARBOOL){
            printf("\033[31mError de tipo en operacion booleana \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
        if ((!auxDer && tipoDer == EID) || (!auxIzq && tipoIzq == EID)) {
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
            if(tipoDer == CALL_F){
                Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
                if((auxIzq->type != VARBOOL || typeFuncDer->type != RETBOL)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }else {
                Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                if((auxDer->type != VARBOOL || typeFuncIzq->type != RETBOL)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if((!auxDer && (auxIzq->type != VARBOOL || errorBoolDer)) ^ (!auxIzq && (auxDer->type != VARBOOL || errorBoolIzq))) {
            printf("\033[31mError de tipo, valores de condicion incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if(auxIzq == NULL && auxDer == NULL){
        if (tipoIzq == EID || tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
        if(tipoDer == CALL_F){
            Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
            if(typeFuncDer->type != RETBOL){
                printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if(tipoIzq == CALL_F){
            Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
            if(typeFuncIzq->type != RETBOL){
                printf("\033[31mError de tipo, funcion de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        }
        if((errorBoolIzq && tipoIzq != CALL_F) || (errorBoolDer &&  tipoDer != CALL_F)){
            printf("\033[31mError de tipo, tipos de valores incompatibles \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    }
}


void evaluate_op_aritmeticos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err) {
    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    bool errorIntDer = !isTypeAritmetic(tipoDer);
    bool errorIzq = !isTypeAritmetic(tipoDer);
    int lineErrLeft = ((ar->left)->symbol)->line;
    if(auxIzq && auxDer){
        if(auxIzq->type != VARINT || auxDer->type != VARINT) {
            printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
            *err = true;
        }
    } else if(auxIzq == NULL && auxDer == NULL){
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariablexxx no declarada \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
            if(tipoDer == CALL_F){
                Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
                if(typeFuncDer->type != RETINT){
                    printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
            if(tipoIzq == CALL_F){
                Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                if(typeFuncIzq->type != RETINT){
                    printf("\033[31mError de tipo \033[0m, error en la linea: %d\n",lineErrLeft);
                    *err = true;
                }
            }
            if((errorIzq && tipoIzq != CALL_F) || (errorIntDer &&  tipoDer != CALL_F)){
                printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", lineErrLeft);
                *err = true;
            }
        } else if((auxIzq != NULL && auxDer == NULL) ^ (auxIzq == NULL && auxDer != NULL)) {
            if ((!auxDer && tipoDer == EID) ^ (!auxIzq && tipoIzq == EID)){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", lineErrLeft);
                *err = true;
            } else if((!auxDer && tipoDer == CALL_F) ^ (!auxIzq && tipoIzq == CALL_F)){
                if(tipoDer == CALL_F) {
                    Tsymbol *typeFuncDer = Lookup((ar->right)->left->symbol->varname);
                    if((auxIzq->type != VARINT || typeFuncDer->type != RETINT)){
                        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                        *err = true;
                    }
                } else {
                    Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                    if((auxDer->type != VARINT || typeFuncIzq->type != RETINT)){
                        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }else if((auxIzq->type != VARINT || errorIntDer) ^ (auxDer->type != VARINT || errorIzq)) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                *err = true;
            }
        }
}

// void errorCallF(AST* ar, bool* err){
//     Tsymbol *typeFuncIzq = LookupTable((ar->left->)symbol->size);
//     Tsymbol *head = typeFuncIzq->table;
//     while(head != NULL) {
//         if(ar)
//         break;
//     }
//     if(!head){
//         printf("\033[31mError de tipo \033[0m, error en la linea: %d\n", ((ar->right)->symbol)->line);
//         *err = true;
//     }

// }
