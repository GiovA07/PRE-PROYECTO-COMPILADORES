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
        printf("< %s >",tree.varname);
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