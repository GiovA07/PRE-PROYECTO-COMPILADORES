#include "AST.h"
#include "symbol.h"

struct AST* createTree(Tsymbol* symbol, struct AST *l, struct AST *r) {
    AST *arbol = (AST *)malloc(sizeof(AST));
    arbol->symbol = symbol;
    arbol->left = l;
    arbol->right = r;
    return arbol;
}

void showTree(AST* tree) {
    if (tree != NULL) {
        printf("< %s >",(tree->symbol)->varname);
        if((tree->left) != NULL){
            printf("(LEFT:");
            showTree(tree->left);
            printf(")");
        }else {
            printf("Ø");
        }
        if((tree->right) != NULL){
            printf("(RHIGT:");
            showTree(tree->right);
            printf(")");
        }else {
            printf("Ø ");
        }
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

void print_tree(AST* ar, int level, int is_last) {
    // op5
    if (ar == NULL) return;
    for (int i = 0; i < level; i++) {
        printf("| ");
    }
    if (is_last) {
        printf("\\__ ");
    } else {
        printf("|-- ");
    }
    printf("%s\n", (ar->symbol)->varname);
    int num_children = 0;
    if (ar->left != NULL) num_children++;
    if (ar->right != NULL) num_children++;
    if (ar->left != NULL) {
        print_tree(ar->left, level + 1, num_children == 1);
    }
    if (ar->right != NULL) {
        print_tree(ar->right, level + 1, num_children == 1);
    }

}
