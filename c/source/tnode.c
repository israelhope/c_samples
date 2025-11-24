/*
cd c\source
gcc tnode.c getword.c -o a.exe; .\a.exe
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "getword.h"

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

/* conteo de frecuencia de palabras */
int main (){
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *mystrdup(char *);

/* addtree: agrega un nodo con w, en o bajo p */
struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    if (p == NULL){
        // Llegó una nueva palabra
        p = talloc(); // nuevo nodo
        p->word = mystrdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++; // palabra repetida
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: imprime el arbol p en orden */
void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>
/* talloc: crea un tnode */
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}
char *mystrdup(char *s){
    char *p;
    p = (char *) malloc(strlen(s) + 1); /* +1 para '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}
