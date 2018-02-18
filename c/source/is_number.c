#include <stdio.h>

main()
{
    int c;
    printf("Ingrese un caracter, verificaremos si es numero o no\n");
    printf("Presione q para salir\n");
    printf(">");
    while((c = getchar()) != 'q')
    {
        if (c != '\n')
        {
            if (c >= '0' && c <= '9')
            {
                printf("[%c] es numero\n", c);
            }
            else
            {
                printf("[%c] no es numero\n", c);
            }
            printf(">");
        }
    }
}