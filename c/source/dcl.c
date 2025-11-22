#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype; /* tipo del último token */
char token[MAXTOKEN]; /* cadena del último token */
char name[MAXTOKEN]; /* nombre del último token */
char datatype[MAXTOKEN]; /* tipo de dato = char, int, etc. */
char out[1000]; /* cadena de salida */

int main(void){
    while (gettoken() != EOF) { /* 1er token en la línea*/
        strcpy(datatype, token); /* es el tipo de dato */
        out[0] = '\0';
        dcl(); /* reconoce el resto de la línea */
        if (tokentype != '\n')
            printf("error de sintaxis\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* gettoken: regresa el siguiente token */
int gettoken(void){
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    while ((c=getch()) == ' ' || c == '\t')
        ;
    if (c == '('){
        if ((c=getch()) == ')'){
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for(*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)){
        for (*p++ = c; isalnum(c=getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else {
        return tokentype = c;
    }
}

/* dcl: reconoce una declaración */
void dcl(void){
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* cuenta *s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " apuntador a");
}
/* dirdcl: reconoce un declarador directo */
void dirdcl(void){
    int type;
    if(tokentype == '('){ /* (dcl) */
        dcl();
        if (tokentype != ')')
            printf("error: falta )\n");
    } else if (tokentype == NAME) /* nombre de variable */
        strcpy(name, token);
    else
        printf("error: nombre o (dcl) esperado\n");
    while ((type=gettoken())==PARENS || type==BRACKETS)
        if (type == PARENS)
            strcat(out, "función que regresa");
        else {
            strcat(out, " arreglo");
            strcat(out, token);
            strcat(out, " de");
        }
}

/*********************** getch y ungetch ************************/
#define BUFSIZE 100
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