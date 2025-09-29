#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

/* 3. Dessinez l'arbre syntaxique de l'expression (A+B)*C+(D+E) */

int main ()
{
  struct Node *x,*y,*z, *root;
  
  x = nd('+',nd('A',NULL,NULL),nd('B',NULL,NULL));
  y = nd('+',nd('D',NULL,NULL),nd('C',NULL,NULL));
  z = nd('*',x,nd('C',NULL,NULL));
 
  root = nd('+',z,y); 

  printtree(root);
  printf("\n\n");

  return (EXIT_SUCCESS);
}

 /* Resultats : 

                                                                                                                        
                                                           (+)                                                          
                               +----------------------------+----------------------------+                              
                              (*)                                                       (+)                             
                +--------------+-------------+                            +--------------+-------------+                
               (+)                          (C)                          (D)                          (C)               
         +------+------+                                                                                                
        (A)           (B)                                                                                               
                                                                                                                        


*/
