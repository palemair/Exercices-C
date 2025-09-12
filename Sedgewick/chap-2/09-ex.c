#include <stdio.h>
#include <limits.h>

/* PGCD % */
unsigned long long pgcd (unsigned long long u, unsigned long long v)
{
    if (u < v)
    {
        unsigned long long temp = u;

        u = v;
        v = temp;
    }
    int r;

    while ((r = u % v) > 0)
    {
        u = v;
        v = r;
    }
    return v;
}

int main (void)
{

    unsigned long long x = LLONG_MAX;
    unsigned long long y = x;

    while (pgcd (x, y--) != 1);

    printf ("pgcd : %llu \n ", pgcd (x, y));
    printf ("x: %llu y: %llu \n", x, y);

    return 0;
}
