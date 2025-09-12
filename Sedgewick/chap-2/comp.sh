#!/bin/bash
# compiler selon le numero de chapitre

if [ $1 -gt 1 ]
    then
        for file in *.c
            do
                f=${file/*\//}
                f=${f/.c/}
                gcc -Wall -Wextra -pedantic $file -o chap-$1/bin/$f 
            done
            echo 'compilation terminée !!'
    else
        echo 'Entrez un numero de chapitre !!'
fi
