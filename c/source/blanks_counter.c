#include <stdio.h>

/* 1-8 Exercise Write a program to count blanks, tabs, and newlines.*/
main()
{
    int bc, tc, nc, c;
    bc = tc = nc = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++bc;
        else if (c == '\t')
            ++tc;
        else if (c == '\n')
            ++nc;
    }
    printf("Blanks: %d, tabs: %d, newlines: %d", bc, tc, nc);
}