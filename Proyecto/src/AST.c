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
int offset = -16;
int cantBloq = -1;
bool inBlockIf = false;
int cantReturns = 0;
int cantRetBlock = 0;

// bool correct = false;
void createTable(AST* ar) {
    enum TYPES tipoActual = (ar->symbol)->type;
    if(tipoActual == EPROGRAM){
       InstallScope();
       InstallInCurrentScope(ar->symbol);
    }

    if(tipoActual == RETINT || tipoActual == RETBOL || tipoActual == RETVOID) {
        //printf("APILO -> %s\n",ar->symbol->varname);
        offset = -16;
        cantBloq++;
        printf("CantBlock %d => %s\n",cantBloq,ar->symbol->varname );
        auxFunc = ar->symbol;
        InstallInCurrentScope(ar->symbol);
        InstallScope();
    }else if(tipoActual == EXTVOID || tipoActual == EXTINT || tipoActual == EXTBOL){
        auxFunc = ar->symbol;
        InstallInCurrentScope(ar->symbol);
        InstallScope();
    }

    // if(tipoActual == BLOCK) tendriamos que modificar esto
    //si no se permite crear funciones dentro de funciones anda
    if( tipoActual == EIF || tipoActual == EWHILE || tipoActual == EELSE){
       // printf("PROBLEMA -> %s\n",ar->symbol->varname);
        // para ver si estoy dentro de un if/while/else
        
        inBlockIf = true;
        cantBloq++;
        //printf("CantBlock %d => %s\n",cantBloq,ar->symbol->varname );
        InstallScope();
        InstallInCurrentScope(ar->symbol);
    }

    if (tipoActual == VARBOOL || tipoActual == VARINT){
        //Esto es para las variables globales, no tengan un scope  Ya que pertenecen al scope 1. (DESPUES FIJARNOS QUE M**** HACER CON ESTOS.)
        if (getScope() != 1) {
            ar->symbol->offset = offset;
            offset += -16;
        }
        InstallInCurrentScope(ar->symbol);
    }
    if(tipoActual == PARAMINT || tipoActual == PARAMBOOL)  {
        ar->symbol->offset = offset;
        offset += -16;
        InstallInCurrentScope(ar->symbol);
        InstallParam(ar->symbol, auxFunc);
    }

    //Esto es para que cada ocurrencia de una variable en el arbol tenga el mismo Tsymbol.
    if (tipoActual == EID) {
        Tsymbol* symbolStack = LookupExternVar(ar->symbol->varname);
        if (symbolStack != NULL) {
            ar->symbol->offset = symbolStack->offset;
        }
    }


    if(tipoActual == BLOCK_FIN) {
        if (cantBloq > 0)
            cantBloq--;
        if (cantBloq == 0 && !inBlockIf) {
            auxFunc->offset = offset;
            offset =  -16;
        }
           // printf("Final CantBlock %d\n\n",cantBloq);

        // printf("Cantidad de Retunrs detectados %d\n",cantRetBlock);

        if(inBlockIf){
            inBlockIf = false;
        }else if(errRet && cantReturns != 2){
            printf("\033[31mTe falta un return en la linea \033[0m %d\n",(ar->symbol)->line-1);
            err= true;
        }else if(errRet && cantReturns == 2) {
            errRet = false;
        }
        PopScope();
        cantRetBlock = 0;
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
              ar->symbol->offset = offset;
              offset += -16;
             errorOpera(ar, tipoActual, &err);
        }else if(tipoActual == EIF || tipoActual == EWHILE) {
            errorCond(ar, &err);
        }
    }
    if((ar->symbol->type == RETVOID)){
        aux = ar->symbol->type;
        errRet = false;
    }
    if(ar->symbol->type == RETINT || ar->symbol->type == RETBOL || ar->symbol->type == EXTBOL || ar->symbol->type == RETINT){
        aux = ar->symbol->type;
        errRet = true;
    }

    if(ar->symbol->type == CALL_F) {
        Tsymbol* exist = LookupExternVar(ar->left->symbol->varname);
        if(exist){
            ar->symbol->offset = offset;
            offset += -16;
            errorCall(ar, &err);
        }else {
           printf("\033[31mLa funcion no existe\033[0m, error en linea:%d\n",ar->left->symbol->line);
           err= true;
        }

    }

    if (ar->left != NULL) {
        // type
        if(ar->symbol->type == ERETURN && inBlockIf){          
            // es para que solo me cuante un return para evitar esto => 
            // return 10
            // reutnr 10
            if(cantRetBlock == 0)
                cantReturns +=1;
            
            cantRetBlock +=1;
            errorRet(ar, aux, &err);
        }else if(ar->symbol->type == ERETURN && cantReturns == 2){
            errRet = false;
            errorRet(ar, aux, &err);
        }else if(ar->symbol->type == ERETURN){
            errRet = false;
            errorRet(ar, aux, &err);
        }
        if(ar->symbol->type == ENOT){
           // printf("type %s => offset %d\n",string[ar->symbol->type],ar->symbol->offset);
            offset += -8;
            ar->symbol->offset = offset;
            errorNot(ar, &err);
        }
        createTable(ar->left);
    }

    if (ar->right != NULL) {
        createTable(ar->right);
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
