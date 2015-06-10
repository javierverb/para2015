#!/bin/bash
# data file
INPUT="test.txt"
function get_word {
    # while loop
    local acumulator=""
    while IFS= read -r -n1 char
    do
        # check if is valid
        if ! [[ "$char" =~ [^a-zA-Z0-9\ ] ]]; then
            acumulator+=$char
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