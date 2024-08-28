
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

    //tabla de simbolos solo las variables
     Install(var,1,1);
     Install(x,1,1);
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
        
        symboloDer1 = CreateSymbol(var,VAR,1);
        symboloIzq1 = CreateSymbol(var,VAR,1);

        symbolo = CreateSymbol(igu,ASIG,1);
        symboloDer = CreateSymbol(sum,SUMA,1);
        symboloIzq = CreateSymbol(var,VAR,1);
                
        AST *der1 = createTree(symboloDer,NULL,NULL);
        AST *izq1 = createTree(symboloIzq,NULL,NULL);
        
        AST *der = createTree(symboloDer,izq1,der1);
        AST *izq = createTree(symboloIzq,NULL,NULL);
        showTree(createTree(symbolo,NULL,der));
        DeleteList();
  //  }
 /* y = 2 + 1;
    x = x + var + 3
                =
              /    \
           varX      +
                    /  \
                varX    +
                       / \
                    var    nu3
 */
    return 0;
}
