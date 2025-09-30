#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

/* 3. Dessinez l'arbre syntaxique de l'expression (A+B)*C+(D+E) */

int main ()
{
  char tab[] = "( ( A + B ) *  C ) + (D + E )";
  node x, y;
  char *pt = tab;
  
  while(*pt != '\0')
  {
      if((*pt >= 'A') && (*pt <= 'Z'))
      {
          empiler(nd(*pt,NULL,NULL));
      }
      
      if(*pt == '+') 
      {
          x = nd(*pt,NULL,NULL);
          x->L = depiler();
          empiler(x);
      }

      if(*pt == '*') 
      {
          x = nd(*pt,NULL,NULL);
          x->L = depiler();
          empiler(x);
      }
      if(*pt == ')') 
      {
          x = depiler();
          y = depiler();
          y->R = x;
          empiler(y);
      }
      pt++; 
  }
  
  x = depiler();
  y = depiler();
  y->R = x;

  printtree(y);
  printf("\n\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

                                                                                                                        
                                                           (+)                                                          
                               +----------------------------+----------------------------+                              
                              (*)                                                       (+)                             
                +--------------+-------------+                            +--------------+-------------+                
               (+)                          (C)                          (D)                          (E)               
         +------+------+                                                                                                
        (A)           (B)                                                                                               
                                                                                                                        


*/
