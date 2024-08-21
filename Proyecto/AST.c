
#include "AST.h"


AST* createTree(int val, int type, char* c, struct AST *l, struct AST *r) {
    AST arbol;
    arbol.val = val;
    arbol.type = type;
    arbol.id = c;
    arbol.left = l;
    arbol.right = r;
    return &arbol;
}