#!/bin/bash
    
# Algunas fuentes:
# http://www.linuxjournal.com/content/return-values-bash-functions
# http://stackoverflow.com/questions/3236871/how-to-return-a-string-value-from-a-bash-function
# http://stackoverflow.com/questions/1878852/how-to-enter-data-from-keyboard-in-shell-programming

shopt -s expand_aliases # EXAMPLES:
# is_known "some_word" $file_to_found
alias is_known='grep -ci' # return 1 if found, else 0
alias put_word='echo -n' # put_word '$word' >> '$destiny_file'
alias dict_new='touch' # touch $name_dict
alias dict_add='echo' # dict_add '$word' >> '$destiny_file'
alias dict_destroy='rm' # rm $dict_target

GLOBAL_WORD_ACUMULATOR=""
GLOBAL_FILE_OUTPUT="document.output"
GLOBAL_ARRAY_WORDS=()

# dict added word
GLOBAL_DICTIONARY=""
# dict ignored word
GLOBAL_IGNORED_DICTIONARY=".dict_ignored.txt"

GLOBAL_WORD_TO_PUT=""

function get_all_words {
    
    local document=$1
    local valid_word=0
    local invalid_character=1

    IFS=''
    while read -r -n1 character
    do
        # check if is valid
        if ! [[ "$character" =~ [^a-zA-Z0-9] ]]; then
            GLOBAL_WORD_ACUMULATOR+=$character
        else
            GLOBAL_ARRAY_WORDS[$valid_word]=$GLOBAL_WORD_ACUMULATOR
            GLOBAL_ARRAY_WORDS[$invalid_character]=$character
            GLOBAL_WORD_ACUMULATOR=""
        fi
    let valid_word+=2
    let invalid_character+=2
    done < "$document"
}
function consult_user {
    # Ejecuta Agregar/Ignorar/Reemplazar
    # Según la opción seleccionada por el usuario
    
    local word=$1
    
    echo "Palabra no reconocida: $word"
    echo "Agregar al diccionario (a) - 
          Ignorar (i) - 
          Reemplazar (r): "
    # get from stdin a option

    read option_selected
    while true; do
        case "$option_selected" in
            a)
                dict_add $word >> $GLOBAL_DICTIONARY
                break
                ;;
            i)
                dict_add $word >> $GLOBAL_IGNORED_DICTIONARY
                break
                ;;
            r)
                echo "Ingrese la nueva palabra con la que desea reemplazar '$word'"
                read word_to_replace
                word=$word_to_replace
                break
                ;;
            *)
                echo "Opción inválida"
                consult_user $word
                break
                ;;
        esac
    done
    # 'return'
    GLOBAL_WORD_TO_PUT=$word
}

function clean_old_output {
    touch $GLOBAL_FILE_OUTPUT
    rm $GLOBAL_FILE_OUTPUT
}

function main {
    
    clean_old_output
    # Verificamos el nro de argumentos.
    if (($# < 1)); then
        echo "spellchecker.c: nro de argumentos erroneo. 
              Deben ser <documento> [<diccionario>].\n"
        exit
    fi

    # si se especifico un diccionario lo usamos,
    if (($# >= 2)); then
        GLOBAL_DICTIONARY=$2
    # caso contrario usamos el diccionario por defecto
    else
        echo "Diccionario no provisto. Usando diccionario por defecto"
        dict_new "default_dict.txt" && dict_destroy "default_dict.txt"
        GLOBAL_DICTIONARY="default_dict.txt"
    fi

    dict_new $GLOBAL_DICTIONARY
    dict_new $GLOBAL_IGNORED_DICTIONARY

    # process_document
    document=$1

    get_all_words $document
    for word in ${GLOBAL_ARRAY_WORDS[*]}; do
        echo "WORD:[$word]"
        GLOBAL_WORD_TO_PUT=$word

        already_in_dict_added=$(is_known $word $GLOBAL_DICTIONARY)
        already_in_dict_ignored=$(is_known $word $GLOBAL_IGNORED_DICTIONARY) 
        
        if ! [[ "$word" =~ [^a-zA-Z0-9] ]]; then
            # si no es conocida
            let is_known=already_in_dict_added+already_in_dict_ignored
            if [[ $is_known -eq 0 ]]; then
                consult_user $word
            fi
            put_word $GLOBAL_WORD_TO_PUT >> $GLOBAL_FILE_OUTPUT
        else
            put_word $word >> $GLOBAL_FILE_OUTPUT
        fi
    done

    dict_destroy $GLOBAL_IGNORED_DICTIONARY
    echo "El documento '$document' ha sido procesado. 
    Resultados en '$GLOBAL_FILE_OUTPUT'"
}

# run script
document=$1
dictionary=$2
main $document $dictionary