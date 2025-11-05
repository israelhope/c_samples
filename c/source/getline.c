#include <stdio.h>

/* getline: lee una línea en s, regresa su longitud */
int getline(char *s, int lim){
    int c, i;
    for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i){
        *(s+i) = c;
    }
    if (c == '\n'){
        *(s + i++) = c;
    }
    *(s+i) = '\0';
    return i;
}
