
#include "../include/Errors.h"

void errorCond(AST *ar, bool* err) {
    int size = (ar->symbol)->size;
    Tsymbol* tableAuxIzq = LookupTable(size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);
    //printf("%s\n", tableAuxIzq->varname);
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq){
        if(tipoIzq == CALL_F){
            Tsymbol *typeFunc = Lookup((ar->left)->left->symbol->varname);
            if(typeFunc->type != RETBOL){
                printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ ){
            printf("\033[31mError de tipo en la condicion \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }else{
        if(auxIzq->type != VARBOOL){
            printf("\033[31mError de tipo en la variable usada en la condicion \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorNot(AST* ar, bool* err) {
    // Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq){
        
        if(tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ ){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }else{
        if(auxIzq->type != VARBOOL){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorRet(AST* ar,enum TYPES type, bool* err){
    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    //Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    enum TYPES tipoActualIzq = ((ar->left)->symbol)->type;
    if(type == RETVOID ){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
    } else {
        if(!auxIzq){
            if(tipoActualIzq == CALL_F){
                    Tsymbol *typeFunc = Lookup((ar->left)->left->symbol->varname);
                if(type == RETINT && typeFunc->type != RETINT){
                    printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    *err = true;
                }else if(type == RETBOL && typeFunc->type != RETBOL){
                    printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    *err = true;
                }
            }else if(type == RETINT && tipoActualIzq != SUMA && tipoActualIzq != RESTA && tipoActualIzq != PROD && tipoActualIzq != ERESTO && tipoActualIzq != EDIV && tipoActualIzq != CONSINT) {
                printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }else if(type == RETBOL && tipoActualIzq != EOR && tipoActualIzq != EAND && tipoActualIzq != ENOT && tipoActualIzq != CONSBOOL && tipoActualIzq != EMAYORQUE && tipoActualIzq != EMENORQUE && tipoActualIzq != EEQ) {
                printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(auxIzq && auxIzq->type != VARBOOL && type == RETBOL){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }else if(auxIzq && auxIzq->type != VARINT && type == RETINT){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    }
}

void errorAsig(AST *ar, bool *err){
    // cuadno asignouna funcion buscar en tabla para ver el tipo que devuelve
    // Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
    // Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    // printf(" ==>> %s ", ((ar->right)->symbol)->varname);
    // printf(" ==>> %d ", ((ar->right)->symbol)->size);
    // printf(" ==>> %d\n", ((ar->right)->symbol)->id);
    Tsymbol* tableAuxDer = LookupTable(((ar->right)->symbol)->size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);

    Tsymbol* tableAuxIzq = LookupTable(((ar->left)->symbol)->size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;

    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
            
    bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT && tipoDer != ERESTO && tipoDer != EDIV );
    bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL && tipoDer != EMAYORQUE && tipoDer != EMENORQUE && tipoDer != EEQ);

    // if(tipoDer == CALL_F){
    //     if(((ar->right)->left->symbol)->type != RETINT){
    //         printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
    //         *err = true;
    //     }
    // }
    if(auxIzq == NULL && tipoIzq == EID) {
        printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer != NULL && auxIzq->type != auxDer->type) {
        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
        *err = true;
    } else if(auxIzq != NULL && auxDer == NULL) {
        if (tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }else if(tipoDer == CALL_F){
            Tsymbol *typeFunc = Lookup((ar->right)->left->symbol->varname);
            if(auxIzq->type == VARINT && typeFunc->type != RETINT){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }else if(auxIzq->type == VARBOOL &&((ar->right)->left->symbol)->type != RETBOL){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        }else if(auxIzq->type == VARINT && errorIntDer) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }else if(auxIzq->type == VARBOOL && errorBoolDer) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    }
}

void errorOpera(AST *ar, enum TYPES type, bool* err){
    // Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
    // //Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,LookupTable((ar->right)->symbol)->size);

    // Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    // //Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,LookupTable((ar->left)->symbol)->size);
    int size = (ar->symbol)->size;
    Tsymbol* tableAuxDer = LookupTable(size);
    Tsymbol* auxDer = LookupInTable(((ar->right)->symbol)->varname,tableAuxDer);

    Tsymbol* tableAuxIzq = LookupTable(size);
    Tsymbol* auxIzq = LookupInTable(((ar->left)->symbol)->varname,tableAuxIzq);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT && tipoDer != ERESTO && tipoDer != EDIV);
    bool errorIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT && tipoIzq != ERESTO && tipoIzq != EDIV);


    if(type == SUMA || type == RESTA || type == PROD || type == ERESTO || type == EDIV) {

        evaluate_op_aritmeticos(ar, auxIzq, auxDer, err);

    } else if(type == EOR || type == EAND || type == ENOT){

        evaluate_op_booleanos(ar, auxIzq, auxDer, err);

    }else {
        //chequer que los hijos de un comparador < > sean distinto de algo bool
        // chequear que los hijos de comparadores sean distintos a comparadores si o si
        bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT);
        bool errorSintacticoDer = (tipoDer == EMAYORQUE || tipoDer == EMENORQUE || tipoDer == EEQ );

        bool errorIntIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT);
        bool errorSintacticoIzq = (tipoIzq == EMAYORQUE || tipoIzq == EMENORQUE || tipoIzq == EEQ );

        if(auxIzq && auxDer){
            if(auxIzq->type != VARINT || auxDer->type != VARINT){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        } else if(auxIzq != NULL && auxDer == NULL) {
            if (tipoDer == EID) {
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(auxIzq->type != VARINT || errorIntDer) {
                if(errorSintacticoDer){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }else{
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }
            }
        } else if(auxIzq == NULL && auxDer != NULL){
            if (tipoIzq == EID){
                printf("\033[33mVariable no declarada12 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(auxDer->type != VARBOOL || errorIntIzq){
                if(errorSintacticoIzq){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }else{
                    printf("\033[31mError de tipo1 \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }
            }
        } else if(auxIzq == NULL && auxDer == NULL){
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariable no declarada12 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(errorIntDer || errorIntIzq){
                if(errorSintacticoIzq || errorSintacticoDer){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }else{
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    *err = true;
                }
            }
        }
    }
}


void evaluate_op_booleanos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err) {
        enum TYPES tipoDer = ((ar->right)->symbol)->type;
        enum TYPES tipoIzq = ((ar->left)->symbol)->type;
        bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL && tipoDer != EMAYORQUE && tipoDer != EMENORQUE && tipoDer != EEQ);
        bool errorBoolIzq = (tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ);
        // agregar a operaciones
        if(auxIzq != NULL && auxDer != NULL){
            if(auxIzq->type != VARBOOL || auxDer->type != VARBOOL){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            }
        } else if(auxIzq != NULL && auxDer == NULL) {
            if (tipoDer == EID) {
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(auxIzq->type != VARBOOL || errorBoolDer ) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                *err = true;
            }
        } else if(auxIzq == NULL && auxDer != NULL){
            if (tipoIzq == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(auxDer->type != VARBOOL || errorBoolIzq){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                *err = true;
            }
        } else if(auxIzq == NULL && auxDer == NULL){
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                *err = true;
            } else if(errorBoolIzq|| errorBoolDer){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                *err = true;
            }
        }
}


void evaluate_op_aritmeticos(AST* ar, Tsymbol* auxIzq, Tsymbol* auxDer, bool* err) {

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT && tipoDer != ERESTO && tipoDer != EDIV);
    bool errorIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT && tipoIzq != ERESTO && tipoIzq != EDIV);


    if(auxIzq != NULL && auxDer != NULL){
        if(auxIzq->type != VARINT || auxDer->type != VARINT) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        }
    } else if(auxIzq != NULL && auxDer == NULL) {
        if (tipoDer == EID){
            printf("\033[33mVariablezzz no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        } else if(auxIzq->type != VARINT || errorIntDer) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    } else if(auxIzq == NULL && auxDer != NULL) {
        if (tipoIzq == EID) {
            printf("\033[33mVariableeeee no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        } else if(auxDer->type != VARINT || errorIzq) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    } else  if(auxIzq == NULL && auxDer == NULL){
        if (tipoIzq == EID || tipoDer == EID){
            printf("\033[33mVariablexxx no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            *err = true;
        } else if(errorIntDer || errorIzq){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            *err = true;
        }
    }
}
