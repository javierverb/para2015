#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct Document {
    FILE *doc;
    char **buffer;
};

int doc_get_word(char* word, doc_s document) {
    char *end_of_str = "\0";
    fpos_t last_position;

    int character_readed, i = 0;
    while (!feof(doc_in)) {
        character_readed = fgetc(doc_in);

        if (isalpha(character_readed)) {
            word[i] = character_readed;
        } else {
            word[i] = *end_of_str;
            if (character_readed != EOF) {
                if (i == 0) {
                    fprintf(doc_out, "%c", character_readed);
                }
                else {
                    fseek(doc_in, -1, SEEK_CUR);
                }
                return 1;
            }
        }
        i++;
    }
    return 0;
}

}

doc_s doc_open(FILE doc_to_open, char *fname, char *permissions) {
    
    document = fopen(fname, permissions);
    if (!document) {
        printf("ERROR: couldn't open document\n");
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