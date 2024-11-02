#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int reverse(const char *str)
{
    if(*str == '\0')
    {
        return 0;
    }
    else
    {
        reverse(str + 1);
        putchar(*str);
    }
    return 0;
}
#define MAX 255

int main (void)
{
  if (setlocale (LC_ALL, "") == NULL)
    {
      perror ("setlocale");
      return EXIT_FAILURE; 
    }
  char phrase[MAX]="\0";

  puts("Entrez une phrase et je l'afficherais inversée avec une fonction recursive");

  fgets(phrase,MAX-1,stdin);
  char *pt = phrase;
 
  for(pt = phrase; *pt != '\0'; pt++)
      if(*pt == '\n') *pt = '\0';
  
  reverse(phrase);
  putchar('\n');

  return 0;
}
