#!/bin/sh

function main {
    
    # Verificamos el nro de argumentos.
    if (("$#" < 1)); then
        echo "spellchecker.c: nro de argumentos erroneo. Deben ser <documento> [<diccionario>].\n"
        exit
    fi

    # si se especifico un diccionario lo usamos,  
    # caso contrario usamos el diccionario por defecto
    #if (("$#" >= 2)); then
    #    dict = $2
    #else
    #    dict = "dict.txt"
    #fi


}


main doc.tx

#> grep "hola" file.txt
#hola
#eso en terminal

#en script usar echo $, va a imprimir 0 o 1(si la palabra existe o no)
# otra forma seria:
# var = 'grep "hola" file.txt' (las comillas simples son comillas q apuntan a la izq)
# $var = hola