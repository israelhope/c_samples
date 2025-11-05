#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main(void){
    int nlines;
    printf("==> Escribe algunas lineas\n");
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        qsort(lineptr, 0, nlines-1);
        printf("\n==> Lineas ordenadas (%i):\n", nlines);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: entrada demasiado grande para ordenarla \n");
        return 1;
    }
}

#define MAXLEN 1000 /* longitud maxima por linea */
char *alloc(int);
int getline(char *, int);
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
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

/* writelines: escribe lineas de salida */
void writelines(char *lineptr[], int nlines){
    while (nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}

/* qsort: ordena v[left]..v[right] en orden ascendente */
void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right){
        return; /* no hace nada si el arreglo contiene menos de 2 elementos */
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
/* swap: intercambia v[i] y v[j] */
void swap(char *v[], int i, int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 1000           /* tamaño disponible */
static char allocbuf [ALLOCSIZE]; /* almacenamiento para alloc */
static char *allocp = allocbuf;   /* siguiente posición libre */

/* alloc: regresa un apuntador a n caracteres */
char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n; /* antigua p */
    } else {
        /* no hay suficiente espacio */
        return NULL;
    }
}
/* afree: libera almacenamiento a partir de *p */
void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
