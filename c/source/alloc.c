#define ALLOCSIZE 10000           /* tamaño disponible */
static char allocbuf [ALLOCSIZE]; /* almacenamiento para alloc */
static char *allocp = allocbuf;   /* siguiente posición libre */

/* alloc: regresa un apuntador a n caracteres */
char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n; /* antigua p */
    } else {
        /* no hay suficiente espacio */
        return 0;
    }
}

/* afree: libera almacenamiento a partir de *p */
void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
