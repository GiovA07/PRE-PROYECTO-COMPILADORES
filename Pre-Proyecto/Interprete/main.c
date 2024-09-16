
#include "AST.h"
#include <stdbool.h>

int main(){
    bool aux;
    char *num3 = "3";
    char *sum = "+";
    char *resta = "resta";
    char *igu = "=";
    char *x = "vax";
    char *var = "var";
    char *var1 = "var1";

    //tabla de simbolos solo las variables
    Tsymbol * new = CreateSymbol(var, 1,1,1);
     Install(new);
     new = CreateSymbol(x,1,1,2);
     Install(new);
     Install(new);
     prinTable();

    // //Busqueda en la tabla
    // struct Tsymbol *var1 = Lookup(var);
    // struct Tsymbol *valor = Lookup(x);

    // if(valor == NULL) {
    //     printf("Revisar tabla!!!!");
    //     DeleteList();
    //} else {
        // AST izq2 = createTree(20,var1->type,var1->name,NULL,NULL);
        // AST der2 = createTree(30,1,num3,NULL,NULL);

        // AST izq1 = createTree(20,valor->type,valor->name,NULL,NULL);
        // AST der1 = createTree(30,1,sum,&izq2,&der2);
        struct Tsymbol *symbolo;
        struct Tsymbol *symboloDer;
        struct Tsymbol *symboloIzq;

        struct Tsymbol *symboloDer1;
        struct Tsymbol *symboloIzq1;
        
        symboloDer1 = CreateSymbol(var,VAR,1,3);
        symboloIzq1 = CreateSymbol(var,VAR,1,3);

        symbolo = CreateSymbol(igu,ASIG,1,4);
        symboloDer = CreateSymbol(sum,SUMA,1,4);
        symboloIzq = CreateSymbol(var1,VAR,1,4);
                
        AST *der1 = createTree(symboloDer1,NULL,NULL);
        AST *izq1 = createTree(symboloIzq1,NULL,NULL);
        
        AST *der = createTree(symboloDer,izq1,der1);
        AST *izq = createTree(symboloIzq,NULL,NULL);
        showTree(createTree(symbolo,izq,der));
        printDot(createTree(symbolo,izq,der),"prueba.dot");
        DeleteList();
    return 0;
}
