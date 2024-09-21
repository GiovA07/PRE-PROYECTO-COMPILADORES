#include "AST.h"
#include "symbol.h"
#include "stdio.h"
#include <stdbool.h>
// Variables globales

// cheker error
bool err = false;
//Guardar tipo por defecto del main
enum TYPES aux = RETVOID;
//chekear error retorno
bool errRet = false;



struct AST* createTree(Tsymbol* symbol, struct AST *l, struct AST *r) {
    AST *arbol = (AST *)malloc(sizeof(AST));
    arbol->symbol = symbol;
    arbol->left = l;
    arbol->right = r;
    return arbol;
}

void elimArbol(AST* tree) {
    if (tree != NULL) {
        if (tree->symbol != NULL) {
            free(tree->symbol);
        }
        if (tree->left != NULL) {
            elimArbol(tree->left);
        }
        if (tree->right != NULL) {
            elimArbol(tree->right);
        }
        free(tree);
    }
}

void showTreeDot(AST* tree,FILE* file) {
    if (tree == NULL) return;
    if(tree->left && tree->right ) {
        fprintf(file, "\"%d|  %s\" -> \"%d|  %s\", \"%d|  %s\";\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->left)->symbol)->id, ((tree->left)->symbol)->varname,((tree->right)->symbol)->id,((tree->right)->symbol)->varname);
        showTreeDot(tree->left, file);
        showTreeDot(tree->right, file);
    }else {
        if (tree->left) {
            fprintf(file, "\"%d|  %s\" -> \"%d|  %s\" ;\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->left)->symbol)->id, ((tree->left)->symbol)->varname);
            showTreeDot(tree->left, file);
        }
        if (tree->right) {
            fprintf(file, "\"%d|  %s\" -> \"%d|  %s\" ;\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->right)->symbol)->id, ((tree->right)->symbol)->varname);
            showTreeDot(tree->right, file);
        }
    }

}

void printDot(AST* tree, const char* filename) {
    if (tree == NULL) {
        printf("arbol borrado");
        exit(1);
    }
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error al abrir el archivo %s\n", filename);
        return;
    }
    fprintf(file, "digraph{\n\n");
    fprintf(file, "rankdir=TB;\n\n");
    fprintf(file, "node[shape=box];\n");
    showTreeDot(tree, file);
    fprintf(file, "}\n");
    fclose(file);
}

void createTable(AST* ar) {
    if ((ar->symbol)->type == VARBOOL || (ar->symbol)->type == VARINT )  {
        Install(ar->symbol);
    }
    if (ar->left != NULL) {
        createTable(ar->left);
    }
    if (ar->right != NULL) {
        createTable(ar->right);
    }
}
//AST* axuRet = NULL; 
void typeError(AST* ar) {
    if (ar->right != NULL && ar->left != NULL) {
        enum TYPES tipoActual = (ar->symbol)->type;
        bool operArit = (tipoActual == SUMA || tipoActual == RESTA || tipoActual == PROD || tipoActual == EDIV || tipoActual == ERESTO);
        bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT ); 
        bool operCondi = (tipoActual == EMAYORQUE || tipoActual == EMENORQUE || tipoActual == EEQ);
        if (tipoActual == ASIG) {
            errorAsig(ar);
        }else if(operArit || operBool || operCondi) {
            errorOpera(ar, tipoActual);
        }else if(tipoActual == EIF || tipoActual == EWHILE) {
           errorCond(ar);
        //    // posible violacion
        //    if(strcmp(ar->symbol->varname, "if_then") == 0){
        //     if(ar->right->left->left){
        //         if( ar->right->left->left->symbol->type == "ERETURN"){
        //             printf("existe");
        //         }
        //     }else if(ar->right->right->left){
        //         printf("exixte44");
        //     }
        //    }else if(strcmp(ar->symbol->varname, "if_else") == 0){
        //     if(ar->right->left->right->left->symbol->type == "ERETURN"){
        //         printf("existe2");
        //     }
        //     if(ar->right->right->left->right->left){
        //         printf("existe3");
        //     }
        //    }
        }
    }
    if(strcmp(ar->symbol->varname, "MAIN") == 0){
        aux = ar->symbol->type;
        if(aux == RETBOL ||aux == RETINT) {
            // axuRet = ar->right->right->left
            errRet = true;
        }
    }
    if (ar->left != NULL) {
        if(ar->symbol->type == ERETURN){
            errRet = false;
            errorRet(ar, aux);
        }
        if(ar->symbol->type == ENOT){
            errorNot(ar);
        }
        typeError(ar->left);
    }
    if (ar->right != NULL) {
        typeError(ar->right);
    }    
}

void errorCond(AST *ar) {
    Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq){
        if(tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ ){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;
        }  
    }else{
        if(auxIzq->type != VARBOOL){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;  
        } 
    }
    
}
    //creo que no hace falta esto
    // else if(type == ETHEN) {
    //     //Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
    //     enum TYPES tipoDer = ((ar->right)->symbol)->type;
    //     if(tipoDer != EELSE){
    //         printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
    //         err = true;   
    //     }
    // }

void errorNot(AST* ar) {  
    Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;
    if(!auxIzq){
        if(tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ ){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;
        }   
    }else{
        if(auxIzq->type != VARBOOL){
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;  
        }
    }
}

void errorRet(AST* ar,enum TYPES type){
    Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
    enum TYPES tipoActualIzq = ((ar->left)->symbol)->type;
    if(type == RETVOID ){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;
    } else {
        if(!auxIzq){
            if(type == RETINT && tipoActualIzq != SUMA && tipoActualIzq != RESTA && tipoActualIzq != PROD && tipoActualIzq != ERESTO && tipoActualIzq != EDIV && tipoActualIzq != CONSINT) {
                printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            }else if(type == RETBOL && tipoActualIzq != EOR && tipoActualIzq != EAND && tipoActualIzq != ENOT && tipoActualIzq != CONSBOOL && tipoActualIzq != EMAYORQUE && tipoActualIzq != EMENORQUE && tipoActualIzq != EEQ) {
                printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            }
        }else if(auxIzq && auxIzq->type != VARBOOL && type == RETBOL){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;
        }else if(auxIzq && auxIzq->type != VARINT && type == RETINT){
            printf("\033[31mError de tipo de retorno \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
            err = true;
        }
    }
}

void errorAsig(AST *ar){
    Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
    Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT && tipoDer != ERESTO && tipoDer != EDIV);
    bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL && tipoDer != EMAYORQUE && tipoDer != EMENORQUE && tipoDer != EEQ);
    
    if(auxIzq == NULL && tipoIzq == EID) {
        printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
        err = true;
    } else if(auxIzq != NULL && auxDer != NULL && auxIzq->type != auxDer->type) {
        printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
        err = true;
    } else if(auxIzq != NULL && auxDer == NULL) {
        if (tipoDer == EID){
            printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
            err = true;
        } else if(auxIzq->type == VARINT && errorIntDer) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            err = true;
        } else if(auxIzq->type == VARBOOL && errorBoolDer) {
            printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
            err = true;
        }
    }
}




void errorOpera(AST *ar, enum TYPES type){

    Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
    Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);

    enum TYPES tipoDer = ((ar->right)->symbol)->type;
    enum TYPES tipoIzq = ((ar->left)->symbol)->type;

    bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT && tipoDer != ERESTO && tipoDer != EDIV);
    bool errorIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT && tipoIzq != ERESTO && tipoIzq != EDIV);
    
    
    if(type == SUMA || type == RESTA || type == PROD || type == ERESTO || type == EDIV) {
        if(auxIzq != NULL && auxDer != NULL){
            if(auxIzq->type != VARINT || auxDer->type != VARINT) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            }
        } else if(auxIzq != NULL && auxDer == NULL) { 
            if (tipoDer == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxIzq->type != VARINT || errorIntDer) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;
            }
        } else if(auxIzq == NULL && auxDer != NULL) {
            if (tipoIzq == EID) {
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxDer->type != VARINT || errorIzq) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;  
            }
        } else  if(auxIzq == NULL && auxDer == NULL){ 
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(errorIntDer || errorIzq){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;
            }
        }
    } else if(type == EOR || type == EAND || type == ENOT){   
        bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL && tipoDer != EMAYORQUE && tipoDer != EMENORQUE && tipoDer != EEQ);
        bool errorBoolIzq = (tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL && tipoIzq != EMAYORQUE && tipoIzq != EMENORQUE && tipoIzq != EEQ);
        
        if(auxIzq != NULL && auxDer != NULL){
            if(auxIzq->type != VARBOOL || auxDer->type != VARBOOL){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            }
        } else if(auxIzq != NULL && auxDer == NULL) {
            if (tipoDer == EID) {
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxIzq->type != VARBOOL || errorBoolDer ) {
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;
            }
        } else if(auxIzq == NULL && auxDer != NULL){
            if (tipoIzq == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxDer->type != VARBOOL || errorBoolIzq){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;
            }
        } else if(auxIzq == NULL && auxDer == NULL){ 
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(errorBoolIzq|| errorBoolDer){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                err = true;
            }
        }
    }else {
        //chequer que los hijos de un comparador < > sean distinto de algo bool
        // chequear que los hijos de comparadores sean distintos a comparadores si o si
        bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT);
        bool errorSintacticoDer = (tipoDer == EMAYORQUE || tipoDer == EMENORQUE || tipoDer == EEQ );

        bool errorIntIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT);
        bool errorSintacticoIzq = (tipoIzq == EMAYORQUE || tipoIzq == EMENORQUE || tipoIzq == EEQ );
        
        if(auxIzq != NULL && auxDer != NULL){
            if(auxIzq->type != VARINT || auxDer->type != VARINT){
                printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            }
        } else if(auxIzq != NULL && auxDer == NULL) {
            if (tipoDer == EID) {
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxIzq->type != VARINT || errorIntDer) {
                if(errorSintacticoDer){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }else{
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }
        } else if(auxIzq == NULL && auxDer != NULL){
            if (tipoIzq == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxDer->type != VARBOOL || errorIntIzq){
                if(errorSintacticoIzq){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }else{
                    printf("\033[31mError de tipo1 \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }
        } else if(auxIzq == NULL && auxDer == NULL){ 
            if (tipoIzq == EID || tipoDer == EID){
                printf("\033[33mVariable no declarada \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(errorIntDer || errorIntIzq){
                if(errorSintacticoIzq || errorSintacticoDer){
                    printf("\033[31mError Sintactico \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }else{
                    printf("\033[31mError de tipo \033[0m, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }
        }
    }
}

void evaluate(AST* ar) {        
    if((ar->symbol)->type == ERETURN){
        struct Tsymbol* auxIzqRet = Lookup(((ar->left)->symbol)->varname);
        evaluate(ar->left);
        if(auxIzqRet){
            printf("\033[32mValor retornado : \033[0m%d \n", auxIzqRet->value);
            exit(1);
        }else {
             printf("\033[32mValor retornado : \033[0m%d \n", ((ar->left)->symbol)->value);
             exit(1);
        }
    }
    if ((ar->symbol)->type  == ENOT) {
            struct Tsymbol* auxIzqRet = Lookup(((ar->left)->symbol)->varname);
            evaluate(ar->left);
            if (auxIzqRet != NULL) {   
                (ar->symbol)->value =  (!auxIzqRet->value);
            } else {
                (ar->symbol)->value = (!(ar->left)->symbol->value);
            } 
    }
    // me rompe el retorno ver cual es el error
    if((ar->symbol)->type  == EIF){
        evaluate(ar->left);
        struct Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
        if((strcmp((ar->symbol)->varname,"if_then") == 0)){
            if(auxIzq){
                if(auxIzq->value){
                    evaluate(ar->right);
                }
            }else{
                if(((ar->left)->symbol)->value){
                    evaluate(ar->right);
                }
            }
        }else if((strcmp((ar->symbol)->varname,"if_else") == 0)){        
            if(auxIzq){
                if(auxIzq->value){
                    evaluate((ar->right)->left);
                }else{
                    evaluate((ar->right)->right->left);
                }
            }else{
                if(((ar->left)->symbol)->value){
                    evaluate((ar->right)->left);
                }else {
                    evaluate((ar->right)->right->left);
                }
            }
        }
    }else if ((ar->right != NULL && ar->left != NULL)) {
        struct Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
        struct Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
        enum TYPES tipoActual = (ar->symbol)->type;
    
        if (ar->left != NULL) {
            evaluate(ar->left);
        }
        if (ar->right != NULL) {
            evaluate(ar->right);
        }
        if (tipoActual == ASIG) {
            setValue(auxIzq, (ar->right)->symbol->value);
        }

        if (tipoActual == SUMA) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value = auxDer->value + auxIzq->value;
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value = (ar->right)->symbol->value + auxIzq->value;
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = auxDer->value + (ar->left)->symbol->value;
            } else {
                (ar->symbol)->value = (ar->right)->symbol->value + (ar->left)->symbol->value;
            }
            
        }
        if (tipoActual == RESTA) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  auxIzq->value - auxDer->value;
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  auxIzq->value - (ar->right)->symbol->value;
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value - auxDer->value;
            } else {
                (ar->symbol)->value = (ar->left)->symbol->value - (ar->right)->symbol->value;
            }
            
        }

        if (tipoActual == PROD) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  auxIzq->value * auxDer->value;
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  auxIzq->value * (ar->right)->symbol->value;
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value * auxDer->value;
            } else {
                (ar->symbol)->value = (ar->left)->symbol->value * (ar->right)->symbol->value;
            }
            
        }

        if (tipoActual == ERESTO) {
            if (auxDer != NULL && auxIzq != NULL) {
                if(auxDer->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxIzq->line);
                    exit(1);
                }else {
                    (ar->symbol)->value =  auxIzq->value % auxDer->value;
                }
            } else if (auxDer == NULL && auxIzq != NULL) {  
                if((ar->right)->symbol->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxIzq->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value =  auxIzq->value % (ar->right)->symbol->value;
                }
            } else if(auxDer != NULL && auxIzq == NULL){
                if(auxDer->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value = (ar->left)->symbol->value % auxDer->value ;
                }
            } else {
                if((ar->right)->symbol->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value = (ar->left)->symbol->value % (ar->right)->symbol->value;
                }
            }
            
        }

        if (tipoActual == EDIV) {
            if (auxDer != NULL && auxIzq != NULL) {
                if(auxDer->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxIzq->line);
                    exit(1);
                }else {
                    (ar->symbol)->value =  auxIzq->value / auxDer->value;
                }
            } else if (auxDer == NULL && auxIzq != NULL) {  
                if((ar->right)->symbol->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxIzq->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value =  auxIzq->value / (ar->right)->symbol->value;
                }
            } else if(auxDer != NULL && auxIzq == NULL){
                if(auxDer->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value = (ar->left)->symbol->value / auxDer->value ;
                }
            } else {
                if((ar->right)->symbol->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", ((ar->left)->symbol)->line);
                    exit(1);
                }else { 
                    (ar->symbol)->value = (ar->left)->symbol->value / (ar->right)->symbol->value;
                }
            }
            
        }
        
        if (tipoActual == EAND) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value = (auxIzq->value && auxDer->value);
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  (auxIzq->value && (ar->right)->symbol->value);
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value && auxDer->value;
            } else {
                (ar->symbol)->value = ((ar->left)->symbol->value && (ar->right)->symbol->value);
            }
            
        }

        if (tipoActual == EOR) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  (auxIzq->value || auxDer->value);
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  (auxIzq->value || (ar->right)->symbol->value);
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value || auxDer->value;
            } else {
                (ar->symbol)->value = ((ar->left)->symbol->value || (ar->right)->symbol->value);
            } 
        }

        if (tipoActual == EEQ) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  (auxIzq->value == auxDer->value);
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  (auxIzq->value == (ar->right)->symbol->value);
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value == auxDer->value;
            } else {
                (ar->symbol)->value = ((ar->left)->symbol->value == (ar->right)->symbol->value);
            } 
        }
        
        if (tipoActual == EMAYORQUE) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  (auxIzq->value > auxDer->value);
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  (auxIzq->value > (ar->right)->symbol->value);
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value > auxDer->value;
            } else {
                (ar->symbol)->value = ((ar->left)->symbol->value > (ar->right)->symbol->value);
            } 
        }
        
        if (tipoActual == EMENORQUE) {
            if (auxDer != NULL && auxIzq != NULL) {
                (ar->symbol)->value =  (auxIzq->value < auxDer->value);
            } else if (auxDer == NULL && auxIzq != NULL) {   
                (ar->symbol)->value =  (auxIzq->value < (ar->right)->symbol->value);
            } else if(auxDer != NULL && auxIzq == NULL){
                (ar->symbol)->value = (ar->left)->symbol->value < auxDer->value;
            } else {
                (ar->symbol)->value = ((ar->left)->symbol->value < (ar->right)->symbol->value);
            } 
        }
    }
}


void retError(){
    if(errRet){
       printf("\033[31mTe falta un return \033[0m\n");
       err= true;
    }
}

bool getError() {
    return err;
}




