#!/bin/bash
    
# Algunas fuentes:
# http://www.linuxjournal.com/content/return-values-bash-functions
# http://stackoverflow.com/questions/3236871/how-to-return-a-string-value-from-a-bash-function
# http://stackoverflow.com/questions/1878852/how-to-enter-data-from-keyboard-in-shell-programming

shopt -s expand_aliases # EXAMPLES:
alias is_contains='grep -ci' # return 1 if found, else 0
alias dict_new='touch' # touch $name_dict
alias dict_destroy='rm' # rm $dict_target
alias put_word='echo' # put_word '$word' >> '$destiny_file'
alias dict_add='echo' # dict_add '$word' >> '$destiny_file'

GLOBAL_WORD_ACUMULATOR=""

# dict added word
GLOBAL_DICTIONARY=""
# dict ignored word
GLOBAL_IGNORED_DICTIONARY=".dict_ignored.txt"

function get_len_file {
    du -b empty.txt | grep -oh [0-9]*
    echo $?
}


function get_word {
    
    local document=$1
    while IFS= read -r -n1 character
    do
        # check if is valid
        if ! [[ "$character" =~ [^a-zA-Z0-9\ ] ]]; then
            GLOBAL_WORD_ACUMULATOR+=$character
        else
            break;
        fi
        echo $GLOBAL_WORD_ACUMULATOR
    
    done < "$document"
    GLOBAL_WORD_ACUMULATOR="EOF"
}

function consult_user {
    local word=$1
    local document=$2
    echo "Palabra no reconocida: $word"
    echo "Agregar al diccionario (a) - 
          Ignorar (i) - 
          Reemplazar (r): "
    # get from stdin a option
    read option_selected
    
    case "$option_selected" in
        a)
            dict_add $word >> $GLOBAL_DICTIONARY
            ;;
        i)
            dict_add $word >> $GLOBAL_IGNORED_DICTIONARY
            ;;
        r)
            echo "Por favor, Ingrese la nueva palabra
                  con la que desea reemplazar $word"
            read new_word
            put_word $new_word >> document
    esac
}

function main {
    
    # Verificamos el nro de argumentos.
    if (($# < 1)); then
        echo "spellchecker.c: nro de argumentos erroneo. 
              Deben ser <documento> [<diccionario>].\n"
        exit
    fi

    # si se especifico un diccionario lo usamos,
    if (("$#" >= 2)); then
        GLOBAL_DICTIONARY=$2
    # caso contrario usamos el diccionario por defecto
    else
        dict_new "default_dict.txt" && dict_destroy "default_dict.txt"
        GLOBAL_DICTIONARY="default_dict.txt"
    fi

    # process_document
    document=$1
    while :
    do
        get_word $document
        if [[ $GLOBAL_WORD_ACUMULATOR="no" ]]; then
            echo "$GLOBAL_WORD_ACUMULATOR" # (debería mostrar exit) 
            break;
        else
            consult_user $GLOBAL_WORD_ACUMULATOR $document
            # favor reinicializar la variable acumador
        fi
    done
}

# run script
document=$1
dictionary=$2
main $document $dictionary