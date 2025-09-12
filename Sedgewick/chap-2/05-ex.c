#include <stdio.h>

unsigned int bin2 (unsigned int x)
{
    if (x / 2 == 0)
    {
        printf ("%u", x % 2);
        return 0;
    }
    else
    {
        bin2 (x / 2);
        printf ("%u", x % 2);
    }
    return 0;
}

void bin (int x)
{
    unsigned int b = ~(~0U >> 1);
    int u = 0;

    while (b > 0)
    {
        if (u % 4 == 0 && u != 0) putchar (' ');

        putchar ((b & x) ? '1' : '0');

        b = b >> 1;
        u++;
    }
    printf ("\n");
}

int main (void)
{
    for (int x = 1; x < 50; x++)
    {
        printf ("%5d : ", x);
        bin (x);
    }
    for (int u = 2; u < 8; u++)
    {
        bin2 (u);
        putchar ('\n');
    }
    return 0;
}
