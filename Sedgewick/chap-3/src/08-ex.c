#include "stdio.h"

#define MAX 100
static char file[MAX + 1];
int debut = 0;
int fin = 0;

void enfiler(char v)
{
   file[fin++] = v;

   if(fin > MAX) fin = 0;
}

int defiler(void)
{
    int t = file[debut++];

    if(debut > MAX) debut = 0;
    return t;
}

int main(void)
{
    char str[]= "Q*UES***TI*ON*FAC***IL***E**";
    puts(str); 
    char *p = str;
    while(*p != '\0')
    {
        if(*p != '*') enfiler(*p);
        else  defiler();

        printf("%s :","file");

        for(int u = fin; u>=debut;u--) printf("%2c",file[u]);
        printf("\n");
        p++;
    }

    return 0;
}
