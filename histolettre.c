#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <argz.h>
#include <locale.h>
#include <wchar.h>

int
main ()
{
  
  if (setlocale (LC_ALL, "") == NULL)
    {
      perror ("setlocale");
      return EXIT_FAILURE; 
    }

  puts("Entrez une phrase et un histogramme du nombre de lettres s'affichera");
  
  char *copy = NULL;
  char *line =NULL;
  size_t n = 0;
  ssize_t read;
  char * pt = NULL;

  while ((read = getline(&line, &n,stdin)) != -1)
          {
            copy = strdup(line);

            if (copy == NULL) 
            { 
                perror("reallocarray");
                free(copy);
            }
          }
  free(line);
  
  int tab[26];
  memset(tab,0,sizeof(tab));
  int c = 0;

   pt = copy;
   while(*pt)
   {
     c = *pt;
     c = *pt -'a'; 
     if( c >= 0 && c <= 25 ) tab[c] +=1;  
     pt++;
   }

  int max = tab[0];

  for(int u = 0; u<26; u++) 
  {
      max = (max<=tab[u]) ? tab[u] : max;
  }
  
  printf("%c",'\n');

  for(int f = max; f>0; f--) 
  {
    printf("%2d |",f);

    for(int u = 0; u<26; u++) 
    {
        tab[u]<f ? printf("   ") : printf(" X ");
    }
    putchar('\n');
  }

    printf("%s","    ");
    for(int u = 0; u<26; u++) printf(" %c ", 'a' + u); 
    putchar('\n');
  
  free(copy);
  
  return (EXIT_SUCCESS);
}
