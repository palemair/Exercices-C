#!/bin/bash
# Compile le fichier C et imprime le résultats en commentaire à la fin.

if [ "$#" -ne 1 ]; 
    then
    echo "Le nombre d'arguments est invalide"
    else
        if test "$1 == "*.c""
        then
            gcc -Wall -Wextra -pedantic $1
            echo -e "\n /* Resultats : \n" >> $1
            ./a.out >> $1 
            echo -e "*/" >> $1
        else
            echo "Not a C program !!"
        fi
    fi
