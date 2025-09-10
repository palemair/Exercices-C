#include <stdio.h>

int main (void)
{
    puts ("Exercice 2 : modulo valeur négative");
    int x, y;

    x = -60;
    y = 11;

    printf ("%3d %% %3d => %3d\n", x, y, x % y);

    return 0;
}
