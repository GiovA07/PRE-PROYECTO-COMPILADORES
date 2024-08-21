
#include "AST.h"

int main(int argc, char const *argv[])
{
    AST ar = createTree(1, 1, "raiz", NULL, NULL);

    showTree(ar);
    return 0;
}
