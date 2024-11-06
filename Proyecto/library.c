#include <stdio.h>
#include <stdbool.h>

int prinInt(int a){
    printf("%d\n",a);
    return 1;
}

void printAdvanced(int x) {
    printf("Val obtenido : %d\n", x);
}

int inputVal() {
    int valor;
    printf("Ingrese un valor: ");
    scanf("%d", &valor);
    return valor;
}
