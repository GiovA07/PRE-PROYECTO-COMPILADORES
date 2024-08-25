
#include "AST.h"

int main(){
    char *num = "num";
    char *sum = "sum";
    //2+2
    
    //tabla de simbolos
    Install(num,1,1);
    Install(sum,1,1);
     
    //Busqueda en la tabla
    struct Tsymbol *valor = Lookup(num);
    struct Tsymbol *operador = Lookup(sum);


    //arbol
    AST der = createTree(30,valor->type,valor->name,NULL,NULL);
    AST izq = createTree(20,valor->type,valor->name,NULL,NULL);
    showTree(createTree(1,operador->type,operador->name,&izq,&der));
    
    //limpio table
    DeleteList();
    return 0;
}