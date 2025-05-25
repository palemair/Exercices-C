#include "stdio.h"

#define MAX 100
static char tp[MAX + 1];
static int sp = 0;

void empiler(char v)
{
    if (sp < MAX)
    {
       tp[sp++] = v;
    }

    else 
    {
        puts("Pile pleine !!");
    }
}

int depiler(void)
{
    if(sp >= 0)
    {
        int tmp = tp[sp];
        sp--;
        return tmp;
    }
    else 
    {
        puts("Pile vide !!");
        return -1;
    }
}

int main(void)
{
    char str[]= "Q*UES***TI*ON*FAC***IL***E**";
    puts(str); 
    char *p = str;
    while(*p != '\0')
    {
        if(*p != '*') 
        {
            empiler(*p);
        }
        else  
        {
            depiler();
        }
        for(int u = sp-1; u>=0;u--) printf("%2c\n",tp[u]);
        printf("  --  \n");
        p++;
    }

    return 0;
}
