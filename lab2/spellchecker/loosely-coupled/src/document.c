#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct Document {
    FILE *doc = NULL;
    char **buffer = NULL;
    unsigned int size_buffer = 0;
};

int doc_get_word(char *word, doc_s doc_in) {
    
    char *end_of_str = "\0";
    fpos_t last_position;

    int character_readed, i = 0;
    while (!feof(doc_in->doc)) {
        character_readed = fgetc(doc_in->doc);

        if (isalpha(character_readed)) {
            word[i] = character_readed;
        } else {
            word[i] = *end_of_str;
            if (character_readed != EOF) {
                if (i == 0) {
                    doc_in->buffer[doc_in->size_buffer] = character_readed;
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

doc_s doc_open(char *doc_to_open) {
    assert(doc_to_open != NULL);
    doc_s document = calloc(1, sizeof(struct Document));
    document->buffer = calloc(1, sizeof(char*));
    document->size_buffer++;
    document->doc = fopen(doc_to_open);

    if (!document->doc) {
        printf("ERROR: couldn't open document\n");
        free(document);
        exit(EXIT_FAILURE);
    }
}

void doc_close(doc_s document, char *fname) {
    assert(document != NULL);
    fclose(document);
}

void doc_put_word(doc_s document, char* word) {
    assert(word != NULL);
    assert(document != NULL);
    fprintf(document, "%s", word);
}