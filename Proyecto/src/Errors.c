
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
    // busco en la funcion
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    // busco global
    Tsymbol* auxIzqGlob = Lookup(((ar->left)->symbol)->varname);
    

    if(!auxIzq && auxIzqGlob){
        auxIzq = auxIzqGlob;
    }

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
        if(auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL){
            printf("\033[31mError de tipo en la variable usada en la condicion \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorNot(AST* ar, bool* err) {
    // Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    Tsymbol* auxIzqGlob = Lookup(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
        auxIzq = auxIzqGlob;
    }

    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq && !isTypeBool(tipoIzq) && !esComparador(tipoIzq)){
        printf("\033[31mError de tipo, operacion no definida, dentro del NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    }else if(auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL){
        printf("\033[31mError de tipo en el valor en la negacion con NOT\033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    }
}

void errorRet(AST* ar,enum TYPES type, bool* err){
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);    
    Tsymbol* auxIzqGlob = Lookup(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
        auxIzq = auxIzqGlob;
    }

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
        }else if((auxIzq && (auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL) && type == RETBOL) || (auxIzq && (auxIzq->type != VARINT && auxIzq->type != PARAMINT) && type == RETINT)){
            printf("\033[31mError de tipo de retorno, expresion de valor incorrecto \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}


void errorAsig(AST *ar, bool *err){
    Tsymbol* tableAuxDer = LookupTable(((ar->right)->symbol)->size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);    
    
    Tsymbol* auxDerGlob = Lookup(((ar->right)->symbol)->varname);
    if(!auxDer && auxDerGlob){
        auxDer = auxDerGlob;
    }

    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    Tsymbol* auxIzqGlob = Lookup(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
        auxIzq = auxIzqGlob;
    }

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
            if(((auxIzq->type == VARINT || auxIzq->type == PARAMINT) && typeFunc->type != RETINT) || ((auxIzq->type == VARBOOL || auxIzq->type == PARAMBOOL) && typeFunc->type != RETBOL)){
                printf("\033[31mError de tipo en la asignacion, tipo de la funcion incompatible \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(((auxIzq->type == VARINT || auxIzq->type == PARAMINT) && errorIntDer) || ((auxIzq->type == VARBOOL || auxIzq->type == PARAMBOOL) && errorBoolDer)) {
            printf("\033[31mError de tipo, error de tipo en la asignacion \033[0m, error en la linea: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    }
}

void errorOpera(AST *ar, enum TYPES type, bool* err){

    int size = (ar->symbol)->size;
    Tsymbol* tableAuxDer = LookupTable(size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);
    Tsymbol* auxDerGlob = Lookup(((ar->right)->symbol)->varname);
    if(!auxDer && auxDerGlob){
        auxDer = auxDerGlob;
    }


    Tsymbol* tableAuxIzq = LookupTable(size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    Tsymbol* auxIzqGlob = Lookup(((ar->left)->symbol)->varname);
    if(!auxIzq && auxIzqGlob){
        auxIzq = auxIzqGlob;
    }
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
        if((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || (auxDer->type != VARINT && auxDer->type != PARAMINT)){
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
                if(((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || typeFuncDer->type != RETINT)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }else {
                Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                if(((auxDer->type != VARINT && auxDer->type != PARAMINT) || typeFuncIzq->type != RETINT)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || errorIntDer) {
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
        if((auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL) || (auxDer->type != VARBOOL && auxDer->type != PARAMBOOL)){
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
                if(((auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL) || typeFuncDer->type != RETBOL)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }else {
                Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                if(((auxDer->type != VARBOOL && auxDer->type != PARAMBOOL) || typeFuncIzq->type != RETBOL)){
                    printf("\033[31mError de tipo, funcion invocada es de tipo incorrecto \033[0m, error en la linea: %d\n", lineErrLeft);
                    *err = true;
                }
            }
        }else if((!auxDer && ((auxIzq->type != VARBOOL && auxIzq->type != PARAMBOOL) || errorBoolDer)) ^ (!auxIzq && ((auxDer->type != VARBOOL && auxDer->type != PARAMBOOL) || errorBoolIzq))) {
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
        if((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || (auxDer->type != VARINT && auxDer->type != PARAMINT)) {
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
                    if(((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || typeFuncDer->type != RETINT)){
                        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                        *err = true;
                    }
                } else {
                    Tsymbol *typeFuncIzq = Lookup((ar->left)->left->symbol->varname);
                    if(((auxDer->type != VARINT && auxDer->type != PARAMINT) || typeFuncIzq->type != RETINT)){
                        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                        *err = true;
                    }
                }
            }else if(((auxIzq->type != VARINT && auxIzq->type != PARAMINT) || errorIntDer) ^ ((auxDer->type != VARINT && auxDer->type != PARAMINT) || errorIzq)) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", lineErrLeft);
                *err = true;
            }
        }
}

void errorCall(AST *ar,  bool *err) {

    Tsymbol* func1 = Lookup(ar->left->symbol->varname);
    Tsymbol* func = LookupTable(func1->size);
    int len = cantArguments(func);
    int index = 0;
    if (len != 0) {
        int typesArg[len];
        recorrer(ar->right,typesArg, &index, len, ar->symbol->size, err);
        int i = 0;
        int *typesParam = typeParam(func);
        if  ( len != (sizeof(typesParam) / sizeof(typesParam[0])) ) {
                printf("\033[31mError en la funcion llamada, cantidad de parametros invalida \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
        }

        for (int j = 0; j < len; j++) {
            // printf("Tipo de parametro: %s \n", string[typesParam[j]]);
            // printf("Tipo de argumento: %s \n", string[typesArg[j]]);
            bool bolCond1 = (typesParam[j] == PARAMBOOL) && (typesArg[j] == VARINT || typesArg[j] == CONSINT|| typesArg[j] == RETINT);
            bool bolCond2 = (typesParam[j] == PARAMINT ) && (typesArg[j] == VARBOOL || typesArg[j] == CONSBOOL || typesArg[j] == RETBOL);
            if  ( bolCond1 || bolCond2 ) {
                printf("\033[31mError de tipo en la funcion llamada \033[0m, error en la linea: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }
    }

}

void recorrer(AST *ar, int tipos[], int* index, int maxArg, int size, bool *err){
    if(ar->left != NULL){
        recorrer(ar->left, tipos, index, maxArg, size, err);
    }
    if(ar->right != NULL){
        recorrer(ar->right, tipos, index, maxArg, size, err);
    }
    if(ar->symbol->type != ARGS && ar->symbol->type != EFUNC ){
        //guardar el tipo
        if(*index < maxArg) {
            Tsymbol* func1 = LookupTable(size);
            Tsymbol* arg = LookupInTable(ar->symbol->varname,func1);        
            Tsymbol* argGlob = Lookup(ar->symbol->varname);
            if(!arg && argGlob){
                arg = argGlob;
            }
            if (arg == NULL) {
                if(ar->symbol->type == CALL_F) {
                    Tsymbol *typeFunc = Lookup(ar->left->symbol->varname);
                    tipos[*index] = typeFunc->type;
                    (*index)++;
                }else if (ar->symbol->type == CONSINT || ar->symbol->type == CONSBOOL ) {
                    tipos[*index] = ar->symbol->type;
                    (*index)++;
                }else {
                    printf("\033[31mArgumento no declarado \033[0m, error en la linea: %d\n", (ar->symbol)->line);
                    *err = true;
                }
            } else {
                tipos[*index] = arg->type;
                (*index)++;
            }
        } else {
            *err = true;
        }
    }
}


