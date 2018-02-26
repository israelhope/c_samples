#include <stdio.h>

int atoi(char s[]);

main()
{
    char i[] = {'1','0','9'};
    int n = atoi(i);
    printf("%d", n);
}

int atoi(char s[])
{
    int i, n;
    for (i = n = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}