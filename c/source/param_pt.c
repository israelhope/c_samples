#include <stdio.h>

/* echo de los argumentos de la línea de órdenes; 2a. versión */
int main(int argc, char *argv[]){
    while(--argc > 0)
        printf("%s%s", *++argv, (argc > 0)?" " : "\n");
    return 0;
}
