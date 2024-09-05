#include "AST.h"
#include "symbol.h"
#include <stdbool.h>

struct AST* createTree(Tsymbol* symbol, struct AST *l, struct AST *r) {
    AST *arbol = (AST *)malloc(sizeof(AST));
    arbol->symbol = symbol;
    arbol->left = l;
    arbol->right = r;
    return arbol;
}

void showTree(AST* tree) {
    if (tree != NULL) {
        printf("< %s >",(tree->symbol)->varname);
        if((tree->left) != NULL){
            printf("(LEFT:");
            showTree(tree->left);
            printf(")");
        }else {
            printf("Ø");
        }
        if((tree->right) != NULL){
            printf("(RHIGT:");
            showTree(tree->right);
            printf(")");
        }else {
            printf("Ø ");
        }
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

bool err = false;

void typeError(AST* ar) {
    if (ar->right != NULL && ar->left != NULL) {
        
        Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
        Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
        
        enum TYPES tipoDer = ((ar->right)->symbol)->type;
        enum TYPES tipoIzq = ((ar->left)->symbol)->type;

        bool errorIntDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT);
        bool errorIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT);

        bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL);
        bool errorBoolIzq = (tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL);

        // errores de asignacion

        if ((ar->symbol)->type == ASIG) {
            if(auxIzq == NULL && tipoIzq == EID) {
                printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                err = true;
            } else if(auxIzq != NULL && auxDer != NULL && auxIzq->type != auxDer->type) {
                printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
                err = true;
            } else if(auxIzq != NULL && auxDer == NULL) {
                if (tipoDer == EID){
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(auxIzq->type == VARINT && errorIntDer) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                } else if(auxIzq->type == VARBOOL && errorBoolDer) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }   
        }
            
        // errores de tipos con operacion enteras
        else if((ar->symbol)->type == SUMA || (ar->symbol)->type == RESTA || (ar->symbol)->type == PROD) {
            if(auxIzq != NULL && auxDer != NULL){
                if(auxIzq->type != VARINT || auxDer->type != VARINT) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
                    err = true;
                }
            } else if(auxIzq != NULL && auxDer == NULL) { 
                if (tipoDer == EID){
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(auxIzq->type != VARINT || errorIntDer) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            } else if(auxIzq == NULL && auxDer != NULL) {
                if (tipoIzq == EID) {
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(auxDer->type != VARINT || errorIzq) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;  
                }
            } else  if(auxIzq == NULL && auxDer == NULL){ 
                if (tipoIzq == EID || tipoDer == EID){
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(errorIntDer || errorIzq){
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }
        }
        // errores de tipos con operacion bool
        else if((ar->symbol)->type == EOR || (ar->symbol)->type == EAND || (ar->symbol)->type == ENOT) {
            if(auxIzq != NULL && auxDer != NULL){
                if(auxIzq->type != VARBOOL || auxDer->type != VARBOOL){
                    printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
                    err = true;
                }
            } else if(auxIzq != NULL && auxDer == NULL) {
                if (tipoDer == EID) {
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(auxIzq->type != VARBOOL || errorBoolDer) {
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            } else if(auxIzq == NULL && auxDer != NULL){
                if (tipoIzq == EID){
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(auxDer->type != VARBOOL || errorBoolIzq){
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            } else if(auxIzq == NULL && auxDer == NULL){ 
                if (tipoIzq == EID || tipoDer == EID){
                    printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
                    err = true;
                } else if(errorBoolIzq|| errorBoolDer){
                    printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
                    err = true;
                }
            }
        }
    } 

    if (ar->left != NULL) {
        typeError(ar->left);
    }
    
    if (ar->right != NULL) {
        typeError(ar->right);
    }
    
}


/* void typeError(AST* ar) {
//     if (ar->right != NULL && ar->left != NULL) {
        
//         Tsymbol* auxDer = Lookup(((ar->right)->symbol)->varname);
//         Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
        
//         enum TYPES tipoDer = ((ar->right)->symbol)->type;
//         enum TYPES tipoIzq = ((ar->left)->symbol)->type;

//         bool errorDer = (tipoDer != SUMA && tipoDer != RESTA && tipoDer != PROD && tipoDer != CONSINT);
//         bool errorIzq = (tipoIzq != SUMA && tipoIzq != RESTA && tipoIzq != PROD && tipoIzq != CONSINT);

//         bool errorBoolDer = (tipoDer != EOR && tipoDer != EAND && tipoDer != ENOT && tipoDer != CONSBOOL);
//         bool errorBoolIzq = (tipoIzq != EOR && tipoIzq != EAND && tipoIzq != ENOT && tipoIzq != CONSBOOL);

//         // errores de asignacion

//         if ((ar->symbol)->type == ASIG) {
//             if(auxIzq == NULL && tipoIzq == EID){
//                 printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                 err = true;
//             }else{
//                 if(auxIzq != NULL && auxDer != NULL){
//                     if(auxIzq->type != auxDer->type){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
//                         err = true;
//                     }
//                 }
//                 if(auxIzq != NULL && auxDer == NULL) {
//                     if (tipoDer == EID){
//                         printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                         err = true;
//                     } else {
//                         if(auxIzq->type == VARINT) {
//                             if(errorDer){
//                                     printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                                     err = true;
//                             }
//                         }
//                         if(auxIzq->type == VARBOOL) {
//                                 if(errorBoolDer){
//                                     printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                                     err = true;
//                             }
//                         } 
//                     }

//                 }   
//             }
//         }
            
//         // errores de tipos con operacion enteras
//         if((ar->symbol)->type == SUMA || (ar->symbol)->type == RESTA || (ar->symbol)->type == PROD) {
//             if(auxIzq != NULL && auxDer != NULL){
//                 if(auxIzq->type != VARINT || auxDer->type != VARINT){
//                     printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
//                     err = true;
//                 }
//             }
//             if(auxIzq != NULL && auxDer == NULL){ 
//                 if (tipoDer == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else {
//                     if(auxIzq->type != VARINT || errorDer){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;
//                     }
//                 }
//             }
//             if(auxIzq == NULL && auxDer != NULL){
//                 if (tipoIzq == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else {
//                     if(auxDer->type != VARINT || errorIzq){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;  
//                     }
//                 }
//             }
//             if(auxIzq == NULL && auxDer == NULL){ 
//                 if (tipoIzq == EID || tipoDer == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else {
//                     if(errorDer || errorIzq){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;
//                     }
//                 }
//             }
//         }
//         // errores de tipos con operacion bool
//         if((ar->symbol)->type == EOR || (ar->symbol)->type == EAND || (ar->symbol)->type == ENOT) {
//             if(auxIzq != NULL && auxDer != NULL){
//                 if(auxIzq->type != VARBOOL || auxDer->type != VARBOOL){
//                     printf("Error de tipo, linea de error: %d\n", ((ar->left)->symbol)->line);
//                     err = true;
//                 }
//             }
//             if(auxIzq != NULL && auxDer == NULL){ 
//                 if (tipoDer == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else {
//                     if(auxIzq->type != VARBOOL || errorBoolDer){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;
//                     }
//                 }
//             }
//             if(auxIzq == NULL && auxDer != NULL){
//                 if (tipoIzq == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else { 
//                     if(auxDer->type != VARBOOL || errorBoolIzq){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;

//                     }
//                 }
//             }
//             if(auxIzq == NULL && auxDer == NULL){ 
//                 if (tipoIzq == EID || tipoDer == EID){
//                     printf("Variable no declarada, linea de error: %d\n", ((ar->left)->symbol)->line); 
//                     err = true;
//                 } else {
//                     if(errorBoolIzq|| errorBoolDer){
//                         printf("Error de tipo, linea de error: %d\n", ((ar->right)->symbol)->line);
//                         err = true;
//                     }
//                 }
//             }
//         }
//     }
//     if (ar->left != NULL) {
//         typeError(ar->left);
//     }
//     if (ar->right != NULL) {
//         typeError(ar->right);
//     }
    
*/


bool getError() {
    return err;
}



