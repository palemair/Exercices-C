#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <argz.h>
#include <locale.h>
#include <wchar.h>
#include "hmorse.h"

int
main ()
{
  
  if (setlocale (LC_ALL, "") == NULL)
    {
      perror ("setlocale");
      return EXIT_FAILURE; 
    }

  puts("Entrez une phrase à convertir en codage morse, terminez par Ctrl-D");
  char **ptr = NULL;
  
  ssize_t read ;
  char *line =NULL;
  size_t n = 0;
  size_t i = 0;
  char * pt = NULL;

  while ((read = getline(&line, &n,stdin))!= -1) 
          {
            ptr = reallocarray(ptr, i+2 ,sizeof(*ptr));
            pt = line;
            if(pt[0] == '\n') 
            {
                break;
            }

            while(*pt != '\n') pt++;
            *pt = '\0';
            ptr[i] = strdupa(line);       
                    if (ptr == NULL)
            { 
                perror("reallocarray");
                free(ptr);
            }
            i++;
          }
  ptr[i] = NULL; 
  free(line);
  
  char **copy = ptr;
  
  while(*copy)
  {
   int u;
   pt = *copy;
   while(*pt)
   {
       for(u = 0;*pt != morse[u].carac && u<40;u++);
       if (u<40) printf("%5s ",morse[u].code);
       else printf(" | ");
       pt++;
   }

   copy++;
  }
  putchar('\n');
  free(ptr);
  
  return (EXIT_SUCCESS);
}
