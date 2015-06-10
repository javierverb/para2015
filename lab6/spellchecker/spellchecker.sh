#!/bin/bash
# data file
INPUT="test.txt"
function get_word {
    # while loop
    local acumulator=""
    while IFS= read -r -n1 character
    do
        # check if is valid
        if ! [[ "$char" =~ [^a-zA-Z0-9\ ] ]]; then
            acumulator+=$character
        fi
    # display one character at a time
    done < "$INPUT"
    echo $acumulator
}

function is_contains {
    local is_kwnow=`grep $1 $2`
    return is_kwnow 
}

result=is_contains hola test.txt

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