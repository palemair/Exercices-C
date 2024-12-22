#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* calcul de la suite de fibonacci, ultra classique */
int main (int argc, char** argv)
{
    char* nbl;
    int nb;

    if (argc == 2)
    {
        nbl = strdupa (argv[1]);
        sscanf (nbl, "%d", &nb);
    }
    else
    {
        nb = 10;
    }

    int som = 0;
    int u, v;
    u = 0;
    v = 1;

    while (nb-- > 0)
    {
        som = u + v;
        printf ("%d + %d = %d\n", u, v, som);
        u = v;
        v = som;
    }

    return 0;
}
