#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

struct sDictionary {
    /* Completar aqui */
    char** dict;
    int size;
};
/******************************************************************************/

void dict_load(*char filename, Dictionary d){

    assert(d != NULL);

    FILE* dict_to_load;
    dict_to_load = fopen(filename, "r");
    char *line_to_read = NULL;
    char* end_of_str = "\0";
    int i = 0;
    size_t len = 0;

    if(dict_to_load == NULL){
        printf("ERROR: no se pudo abrir el archivo %s",filename);
        exit(EXIT_FAILURE);
    }
    else{
        while (feof(dict_to_load) == 0) {
        
            if (getline(&line_to_read, &len, dict_to_load) != -1) {
                
                if (i >= d->size) {
                    d->size *= 2; // increased my limit of words
                    d->dict = realloc(d->dict, 
                                        (d->size)*sizeof(char*));
                }

                d->dict[i] = line_to_read;
                d->dict[i][strlen(line_to_read)-1] = *end_of_str;
                // lost a reference for my pointer
                line_to_read = NULL;
                i++;
            }
        }
    }
    // realloc to exact total words save in dict 
    d->size = i;
    d->dict = realloc(d->dict, d->size*sizeof(char*));
    
    fclose(dict_to_load);
}
/******************************************************************************/

void dict_save(char* fnamem, Dictionary d){
    
    assert(d != NULL);

    FILE *dict_to_save;
    dict_to_save = fopen(fname, "w");

    if (dict_to_save != NULL) {
        int i = 0;
        for (i; i < d->size; ++i) {
            fprintf(dict_to_save, "%s", d->dict[i]);
        }
    }
    else {
        printf("Error al abrir archivo\n");
        exit(EXIT_FAILURE);
    }
    fclose(dict_to_save);
}
/******************************************************************************/

void dict_add(char* word, Dictionary d){
    
    assert(word != NULL);
    assert(d != NULL);
    
    char *new_word_to_add = NULL;
    
    // space for new slot in dict
    d->size++;
    d->dict = realloc(d->dict, (d->size)*sizeof(char *));

    // space for new value in slot
    new_word_to_add = calloc(strlen(word)+1, sizeof(char));
    // add
    d->dict[d->size-1] = strcpy(new_word_to_add, word);
}
/******************************************************************************/

ignored_add(char* word, Dictionary d){
    
    assert(word != NULL);
    assert(d != NULL);

    char *new_word_to_add = NULL;
    // create new dict_ignored if have a null space
    if (d->dict == NULL) {
        // and add the new word
        d->dict = calloc(1, sizeof(char*));
        new_word_to_add = calloc(strlen(word) + 1, sizeof(char));
        d->dict[0] = strcpy(new_word_to_add, word);
    }
    else {
        // space for my new value in slot
        new_word_to_add = calloc(strlen(word) + 1, sizeof(char));
        // add
        int i = 0;
        while (d->dict[i] != NULL) {
            i++;
        }
        d->dict = realloc(d->dict, (i+1)*sizeof(char*));
        d->dict[i] = strcpy(new_word_to_add, word);
    }
}
/*****************************************************************************/

int dict_contains(char* word, Dictionary d){

    assert(d != NULL);
    assert(word != NULL);

    int found = 1;
    int not_found = 0;

    if(d->dict != NULL){
        int pos = 0;
        while(pos < d->size){
            if(d->dict[pos] != NULL){
                if(strcmp(d->dict[pos], word) == 0){
                    return found;
                }
                pos++;
            }
        }
    }

    return not_found;
}

/*****************************************************************************/

Dictionary dict_new(void){
    
    Dictionary new_dict = NULL;
    new_dict = calloc(1,sizeof(struct (Dictionary)));

    new_dict->dict = NULL;
    new_dict->size = 10;

    return new_dict;
}
/******************************************************************************/

Dictionary dict_destroy(Dictionary d){

    int pos = 0;
    /* liberamos todo el dict */
    for(pos; pos < d->size; i++){
        free(d->dict[pos])
        d->dict[pos] = NULL;
        pos++;
    }
    
    free(dict);
    dict = NULL;
    
    free(d);
    d = NULL;

    return d;
}
/******************************************************************************/
