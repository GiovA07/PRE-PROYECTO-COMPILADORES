
#include "AST.h"


AST createTree(int val, int type, char* c, struct AST *l, struct AST *r) {
    AST arbol;
    arbol.val = val;
    arbol.type = type;
    strcpy(arbol.id, c);
    arbol.left = l;
    arbol.right = r;
    return arbol;
}

void showTree(AST tree) {
    if (&tree != NULL) {
        printf("< %d %s >\n", (tree.val), tree.id);
        showTree(*tree.left);
        showTree(*tree.right);
    }

    printf("---");
}
