#include <stdio.h>
#include <ctype.h>
#include "getword.h"

int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

/*********************** getch y ungetch ************************/

char buf[BUFSIZE]; /* buffer para ungetch */
int bufp = 0; /* siguiente posición libre en buff */
/* getch: obtiene un caracter de la entrada estandar */
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}
/* ungetch: regresa un caracter a la entrada */
void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: demasiados caracteres\n");
    else
        buf[bufp++] = c;
}