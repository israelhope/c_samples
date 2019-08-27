#include <stdio.h>

int atoi(char s[]);
double atof(char s[]);

int main()
{
    char i[] = {'1','0','9'};
    char f[] = "153.412541";
    int n = atoi(i);
    double n2 = atof(f);
    printf("%d\n", n);
    printf("%.10f\n", n2);
    return 0;
}

int atoi(char s[])
{
    int i, n;
    for (i = n = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
double atof(char s[])
{
    int i;
    int d;
    double n;
    for (i = 0, n = 0.0; s[i] >= '0' && s[i] <= '9'; ++i){
        n = 10.0 * n + (s[i] - '0');
    }
    if (s[i] = '.') ++i;
    for (d = 0; s[i] >= '0' && s[i] <= '9'; ++i, ++d){
        n = 10.0 * n + (s[i] - '0');
    }
    for (i = 0; i < d; ++i)
        n = n/10.0;
    return n;
}