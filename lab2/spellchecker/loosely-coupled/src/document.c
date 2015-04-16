#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "document.h"

struct sDocument {
    FILE *doc;
    char **buffer;
    unsigned int size_buffer;
};
/*****************************************************************************/

int doc_get_word(char *word, Document doc_in) {
    
    char *end_of_str = "\0";
    fpos_t last_position;

    int character_readed, i = 0;
    while (!feof(doc_in->doc)) {
        character_readed = fgetc(doc_in->doc);

        if (isalnum(character_readed)) {
            word[i] = character_readed;
        } else {
            word[i] = *end_of_str;
            if (character_readed != EOF) {
                if (i == 0) {
                    doc_in->buffer[doc_in->size_buffer] = (char)character_readed;
                    doc_in->size_buffer++;
                }
                else {
                    fseek(doc_in->doc, -1, SEEK_CUR);
                }
                return 1;
            }
        }
        i++;
    }
    return 0;
}
/*****************************************************************************/

Document doc_open(char *doc_to_open) {
    assert(doc_to_open != NULL);
    Document document = calloc(1, sizeof(struct sDocument));
    document->buffer = calloc(1, sizeof(char*));
    document->size_buffer++;
    document->doc = fopen(doc_to_open, "rw");

    if (!document->doc) {
        printf("ERROR: couldn't open document\n");
        free(document);
        exit(EXIT_FAILURE);
    }
}
/*****************************************************************************/

void doc_close(Document document){

    assert(document != NULL);
    for (int i = 0; i < document->size_buffer; ++i){
        fprintf(document->doc, "%s", document->buffer[i]);
        free(document->buffer[i]);
        document->buffer[i] = NULL;
        i++;
    }

    free(document->buffer);
    document->buffer = NULL;
    
    fclose(document->doc);

    free(document);
    document = NULL;
}
/*****************************************************************************/

void doc_put_word(Document document, char* word) {
    
    assert(word != NULL);
    assert(document != NULL);
    
    if(document->buffer == NULL){
        document->buffer = calloc(1, sizeof(char*));
        document->buffer[0] = word;
    }

    else{
        document->buffer = realloc(document->buffer, (document->size_buffer + 1) * sizeof(char*))
        document->buffer[document->size_buffer] = word;
        document->size_buffer++;
    }
}
/*****************************************************************************/