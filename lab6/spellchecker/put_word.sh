#!/bin/sh

function is_know {
    var = grep "$1" "dict.txt"
    echo "$var"
}

function put_word {

    local file="dict.txt"

    if [ ! -f "$file" ] ; then
         # if not create the file
         touch "$file"
     fi

     echo "$1" >> "$file"
}
put_word hola
put_word esto
put_word es
put_word un
put_word diccionario
is_know cassandra
is_know hola
is_know franco
is_know javi
is_know diccionario