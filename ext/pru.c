#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    ++argv,--argc;
    if (argc == 0) {
        printf("No arguments, enter file\n");
        return 10;
    }
	if (argc == 1) {
        if (strcmp(argv[0],"-h") == 0) {
            printf("    -a entra por -a\n");
            printf("    -b entra por -b\n");
            printf("    -c entra por -c\n");
            printf("    -h ayuda muestra\n");
            return 0;
        }
        if (strstr(argv[0],".comp")) {
            printf("pasaron cosas\n");
        }
        
    } else {
        int i = 0;
        do {
             if (strcmp(argv[i],"-a") == 0) {
                printf("Entro por -a\n");
            }else if (strcmp(argv[i],"-b") == 0) {
                printf("Entro por -b\n");
                /* code */
            }else if (strcmp(argv[i],"-c") == 0) {
                printf("Entro por -c\n");
                /* code */
            } else if (strstr(argv[i],".comp")) {
                printf("Nombre del archivo\n");
            } else {
                printf("No se reconoce el argumento %s\n",argv[i]);
                perror("Asi no funciona esto");
                return -1;
            }
            /* code */
            i++;
        } while (i < argc);
    }
    
    printf("\nCompilacion terminada, me debe una mamada\n");        
        
    return 0;
}
