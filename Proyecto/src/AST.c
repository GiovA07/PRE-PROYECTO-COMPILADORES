#include "../include/AST.h"
#include "../include/symbol.h"
#include "../include/Errors.h"

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
    enum TYPES tipoActual = (ar->symbol)->type;
    if(tipoActual == RETINT || tipoActual == RETBOL || tipoActual == RETVOID) {
        Install(ar->symbol);
    }
    if (tipoActual == VARBOOL || tipoActual == VARINT )  {       
        Tsymbol* aux = LookupTable(ar->symbol->size);
        if(aux) {
            InstallTable(ar->symbol,aux);
        }else {
            Install(ar->symbol);
        }
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
            errorAsig(ar, &err);
        }
        else if(operArit || operBool || operCondi) {
            errorOpera(ar, tipoActual, &err);
        }else if(tipoActual == EIF || tipoActual == EWHILE) {
           errorCond(ar, &err);
        
        // posible violacion retorno
        // if(strcmp(ar->symbol->varname, "if_then") == 0){
        //     if(ar->right->left->left){
        //         if( ar->right->left->left->symbol->type == ERETURN){
        //             printf("existe");
        //         }
        //     }else if(ar->right->right->left){
        //         printf("exixte44");
        //     }
        //    }else if(strcmp(ar->symbol->varname, "if_else") == 0){
        //     if(ar->right->left->right->left->symbol->type == ERETURN){
        //         printf("existe2");
        //     }
        //     if(ar->right->right->left->right->left){
        //         printf("existe3");
        //     }
        //    }
        // 
        // }else if(tipoActual == CALL_F){
        //     errorCallF(ar,&err);
        }
    }
    if((ar->symbol->type == RETVOID)){
        aux = ar->symbol->type;
    }
    if(ar->symbol->type == RETINT || ar->symbol->type == RETBOL){
        
        aux = ar->symbol->type;
        errRet = true;
    }
    if (ar->left != NULL) {
        if(ar->symbol->type == ERETURN){
            errRet = false;
            errorRet(ar, aux, &err);
        }
        if(ar->symbol->type == ENOT){
            errorNot(ar, &err);
        }
        typeError(ar->left);
    }

    if (ar->right != NULL) {
        typeError(ar->right);
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
