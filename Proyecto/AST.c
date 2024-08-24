#include "AST.h"
#include "symbol.h"

AST createTree(int val, int type, char* c, struct AST *l, struct AST *r) {
    AST arbol;
    arbol.val = val;
    arbol.type = type;
    arbol.varname = c;
    arbol.left = l;
    arbol.right = r;
    return arbol;
}

void showTree(AST tree) {
    if (&tree != NULL) {
        printf("< %d %s >", (tree.val) , tree.varname);
        if(&(*tree.left) != NULL){
            printf("(LEFT:");
            showTree(*tree.left);
            printf(")");
        }else {
            printf("Ø");
        } 
        if(&(*tree.right) != NULL){
            printf("(RHIGT:");
            showTree(*tree.right);
            printf(")");
        }else {
            printf("Ø ");
        }
    }
}

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