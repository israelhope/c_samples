#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_custom(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);

int main(int argc, char *argv[])
{
    int nlines;      /* número de lineas de entrada leídas */
    int numeric = 0; /* 1 si es ordenamiento numérico */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_custom((void **) lineptr, 0, nlines-1, 
            (int (*) (void*, void*)) (numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("entrada demasiado grande para ser ordenada\n");
        return 1;
    }
}

#define MAXLEN 1000 /* longitud maxima por linea */
char *alloc(int);
int getline(char *s, int lim);
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
void qsort_custom(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right){
        return; /* no hace nada si el arreglo contiene menos de 2 elementos */
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp) (v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_custom(v, left, last-1, comp);
    qsort_custom(v, last+1, right, comp);
}
/* swap: intercambia v[i] y v[j] */
void swap(void *v[], int i, int j){
    void *temp;
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

/* numcmp: compara s1 y s2 numéricamente */
int numcmp(const char *s1, const char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}