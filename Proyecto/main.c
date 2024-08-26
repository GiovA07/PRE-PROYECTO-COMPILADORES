
#include "AST.h"

int main(){
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

    //Busqueda en la tabla
    struct Tsymbol *var1 = Lookup(var);
    struct Tsymbol *valor = Lookup(x);

    if(valor == NULL) {
        printf("Revisar tabla!!!!");
        DeleteList();
    } else {
        AST izq2 = createTree(20,var1->type,var1->name,NULL,NULL);
        AST der2 = createTree(30,1,num3,NULL,NULL);

        AST izq1 = createTree(20,valor->type,valor->name,NULL,NULL);
        AST der1 = createTree(30,1,sum,&izq2,&der2);
        AST der = createTree(30,1,sum,&izq1,&der1);

        AST izq = createTree(20,valor->type,valor->name,NULL,NULL);

        showTree(createTree(1,1,igu,&izq,&der));
        DeleteList();
    }
 /*
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
