#include <stdio.h>
#define MAX 50

int convertir (void)
{
    char str[MAX + 1];

    fgets (str, MAX, stdin);

    char c;
    int i = 0;
    int n = 0;

    while ((i < MAX))
    {
        c = *(str + i);
        if ((c == ' ') || (c < '0') || (c > '9')) break;
        n = 10 * n + (c - '0');
        i++;
    }
    return n;
}

int main (void)
{
    printf ("%s", "Entrez un nombre : ");
    int ret = convertir ();

    printf ("le nombre converti est : %d ou %#0X\n", ret, ret);
    return 0;
}
