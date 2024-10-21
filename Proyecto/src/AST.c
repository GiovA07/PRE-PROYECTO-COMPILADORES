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

void updateNodeTree(AST* tree, Tsymbol* symbol){
    tree->symbol = symbol;
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

Tsymbol *auxFunc = NULL;
// bool correct = false;
void createTable(AST* ar) {
    enum TYPES tipoActual = (ar->symbol)->type;
    if(tipoActual == EPROGRAM){
       InstallScope();
       InstallInCurrentScope(ar->symbol);
    }
    if(tipoActual == RETINT || tipoActual == RETBOL || tipoActual == RETVOID ) {
        //printf("APILO -> %s\n",ar->symbol->varname);
        auxFunc = ar->symbol;
        InstallInCurrentScope(ar->symbol);
        InstallScope();
    }
    //si no se permite crear funciones dentro de funciones anda
    if( tipoActual == EIF || tipoActual == EWHILE || tipoActual == EELSE){
       // printf("PROBLEMA -> %s\n",ar->symbol->varname);
        InstallScope();
        InstallInCurrentScope(ar->symbol);
    }

    if (tipoActual == VARBOOL || tipoActual == VARINT){

        InstallInCurrentScope(ar->symbol);
    }
    if(tipoActual == PARAMINT || tipoActual == PARAMBOOL)  {

        InstallInCurrentScope(ar->symbol);
        InstallParam(ar->symbol, auxFunc);
    }

    if(tipoActual == BLOCK_FIN) {
        PopScope();
    }
    // type
    if (ar->right != NULL && ar->left != NULL) {
        enum TYPES tipoActual = (ar->symbol)->type;
        bool operArit = (tipoActual == SUMA || tipoActual == RESTA || tipoActual == PROD || tipoActual == EDIV || tipoActual == ERESTO);
        bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
        bool operCondi = (tipoActual == EMAYORQUE || tipoActual == EMENORQUE || tipoActual == EEQ);
        if (tipoActual == ASIG) {
            errorAsig(ar, &err);
        } else if(operArit || operBool || operCondi) {
             errorOpera(ar, tipoActual, &err);
        }else if(tipoActual == EIF || tipoActual == EWHILE) {
            errorCond(ar, &err);
        }
    }
    if((ar->symbol->type == RETVOID)){
        aux = ar->symbol->type;
    }
    if(ar->symbol->type == RETINT || ar->symbol->type == RETBOL){
        aux = ar->symbol->type;
        errRet = true;
    }

    if(ar->symbol->type == CALL_F) {
        Tsymbol* exist = LookupExternVar(ar->left->symbol->varname);
        if(exist){
            errorCall(ar, &err);
        }else {
           printf("\033[31mLa funcion no existe\033[0m, error en linea:%d\n",ar->left->symbol->line);
           err= true;
        }

    }

    if (ar->left != NULL) {
        // type
        if(ar->symbol->type == ERETURN){
            errRet = false;
            errorRet(ar, aux, &err);
        }
        if(ar->symbol->type == ENOT){
             errorNot(ar, &err);
        }
        createTable(ar->left);
    }

    if (ar->right != NULL) {
        createTable(ar->right);
    }



}

// void evaluate(AST* ar) {
//     if((ar->symbol)->type == ERETURN){
//         struct Tsymbol* auxIzqRet = Lookup(((ar->left)->symbol)->varname);
//         evaluate(ar->left);
//         if(auxIzqRet){
//             printf("\033[32mValor retornado : \033[0m%d \n", auxIzqRet->value);
//             exit(1);
//         }else {
//              printf("\033[32mValor retornado : \033[0m%d \n", ((ar->left)->symbol)->value);
//              exit(1);
//         }
//     }
//     // me rompe el retorno ver cual es el error
//     if((ar->symbol)->type  == EIF){
//         evaluate(ar->left);
//         struct Tsymbol* auxIzq = Lookup(((ar->left)->symbol)->varname);
//         if((strcmp((ar->symbol)->varname,"if_then") == 0)){
//             if(auxIzq){
//                 if(auxIzq->value){
//                     evaluate(ar->right);
//                 }
//             }else{
//                 if(((ar->left)->symbol)->value){
//                     evaluate(ar->right);
//                 }
//             }
//         }else if((strcmp((ar->symbol)->varname,"if_else") == 0)){
//             if(auxIzq){
//                 if(auxIzq->value){
//                     evaluate((ar->right)->left);
//                 }else{
//                     evaluate((ar->right)->right->left);
//                 }
//             }else{
//                 if(((ar->left)->symbol)->value){
//                     evaluate((ar->right)->left);
//                 }else {
//                     evaluate((ar->right)->right->left);
//                 }
//             }
//         }



void retError(){
    if(errRet){
       printf("\033[31mTe falta un return \033[0m\n");
       err= true;
    }
}

bool getError() {
    return err;
}
