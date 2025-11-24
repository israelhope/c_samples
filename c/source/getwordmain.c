/*
cd c\source
gcc getwordmain.c getword.c -o a.exe; .\a.exe
*/
#include <stdio.h>
#include "getword.h"

#define MAXWORD 100

int main(void){
    int i = 0;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF)
        printf("%3d %s\n", i++, word);
}