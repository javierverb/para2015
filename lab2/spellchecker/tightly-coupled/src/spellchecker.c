#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//tamaño maximo de una palabra
#define MAX_WORD_SIZE 30

// tamaño máximo de un diccionario en PRIMERA INSTANCIA
#define MAX_LENGTH_DICT_MAIN 200
#define MAX_LENGTH_DICT_IGNORED 1

// posición actual del índice del diccionario
#define CURRENT_INDEX_DICT_MAIN 0


/* diccionario principal */
char **dict_main = NULL;
/*tamaño inicial del diccionario principal */
int main_size = 10;

/* diccionario de palabras ignoradas */
char **dict_ignored = NULL;
/*tamaño inicial del diccionario de palabras ignoradas*/
int ignored_size = 0;

/* Documento de entrada */
FILE *doc_in;
/* Documento de salida */
FILE *doc_out;

/* 
Sugerencia de los profes al comenzar: asignar tamaño de SOBRA en la
variable global dict_main y al finalizar el lab regular su longitud 
Al comienzo valdrá: 

dict_main = calloc(1000, sizeof(char*)); 
*/

/*******************************************************************
* NAME :            void dict_load(char *fname)
*
* DESCRIPTION :     Carga en memoria el diccionario principal desde 
*                   el archivo fname
*
* PARAMETERS:
*      INPUT:
*           char    *fname       Nombre del archivo que contiene el 
*                                diccionario
* RETURN :
*           Type: void
*
* OBSERVATIONS :
*    1) El tamaño de la lista que contiene representa al diccionario 
*       debe coincidir con el nro de palabras en el diccionario. 
*       Esto implica que si es necesario hay que "agrandar" la lista, 
*       y si sobra espacio en la lista hay que "achicarla".
*    2) Recordar borrar el \n y \r al final de cada palabra y que los 
*       strings en C terminan en \0.
*******************************************************************/
void dict_load(char *fname) {
    /* 
    IMPORTANT Note: Free memory when calling this function 
    */

    FILE *dict_to_load;
    dict_to_load = fopen(fname, "r");
    char *line_to_read = NULL;

    dict_main = calloc(MAX_LENGTH_DICT_MAIN, sizeof(char*));
    size_t len = 0; // Is dinamic!
    if (dict_to_load != NULL) {
    
        while (feof(dict_to_load) == 0) {
        
            if (getline(&line_to_read, &len, dict_to_load) != -1) {
                
                if (i >= MAX_LENGTH_DICT_MAIN) {
                    MAX_LENGTH_DICT_MAIN *= 2; // increased my limit of words
                    dict_main = realloc(dict_main, 
                                        (MAX_LENGTH_DICT_MAIN)*sizeof(char*));
                }

                dict_main[i] = line_to_read;
                
                // lost a reference for my pointer
                line_to_read = NULL;
                i++;
            }
        }
    }
    else {
        printf("Error al abrir archivo");
        return EXIT_FAILURE;
    }

    // realloc to exact total words save in dict 
    MAX_LENGTH_DICT_MAIN = i;
    dict_main = realloc(dict_main, MAX_LENGTH_DICT_MAIN*sizeof(char*));
    
    fclose(dict_to_load);
}

/*******************************************************************
* NAME :            void dict_save(char *fname)
*
* DESCRIPTION :     Guarda el diccionario principal en el archivo 
*                   fname
*
* PARAMETERS:
*      INPUT:
*           char    *fname       Nombre del archivo donde se guardara
*                                el diccionario
* RETURN :
*           Type: void
*******************************************************************/
void dict_save(char *fname) {

    FILE *dict_to_save;
    dict_to_save = fopen(fname, "w");
    
    if (dict_to_save != NULL) {
        
        for (int i = 0; i < MAX_LENGTH_DICT_MAIN; ++i) {
            fprintf(dict_to_save, dict_main[i]);
        }
    }
    else {
        printf("Error al abrir archivo");
        return EXIT_FAILURE;
    }
    fclose(dict_to_save);
}

/*******************************************************************
* NAME :            void dict_add(char *word)
*
* DESCRIPTION :     Agrega una palabra al diccionario principal.
*
* PARAMETERS:
*      INPUT:
*           char    *word       Palabra a ser agregada.
*
* RETURN :
*           Type: void
*
* OBSERVATIONS :
*    1) Recordar que la lista que representa el diccionario no tiene 
*       lugar "de sobra".
*******************************************************************/
void dict_add(char *word){

    assert(word != NULL);
    
    char *new_word_to_add = NULL;
    
    // space for new slot in dict
    MAX_LENGTH_DICT_MAIN++;
    dict_main = realloc(dict_main, MAX_LENGTH_DICT_MAIN*sizeof(char *));

    // space for new value in slot
    new_word_to_add = calloc(strlen(word)+1, sizeof(char));
    // add
    dict_main[MAX_LENGTH_DICT_MAIN-1] = strcpy(new_word_to_add, word);
}

/*******************************************************************
* NAME :            void ignored_add(char *word)
*
* DESCRIPTION :     Agrega una palabra al diccionario de palabras 
*                   ignoradas.
*
* PARAMETERS:
*      INPUT:
*           char    *word       Palabra a ser agregada.

* RETURN :
*           Type: void
* OBSERVATIONS :
*    1) La lista que representa el diccionario de palabras ignoradas 
*       debe agrandarse a medida que se agregan palabras.
*******************************************************************/
void ignored_add(char *word) {

    assert(word != NULL);

    char *new_word_to_add = NULL;
    // create new dict_ignored if have a null space
    if (dict_ignored == NULL) {
        // and add the new word
        dict_ignored = calloc(MAX_LENGTH_DICT_IGNORED, sizeof(char*));
        new_word_to_add = calloc(strlen(word) + 1, sizeof(char));
        dict_ignored[MAX_LENGTH_DICT_IGNORED-1] = strcpy(new_word_to_add, word);
    }
    else {
        // space for my new slot in dictionary
        MAX_LENGTH_DICT_IGNORED++;
        dict_ignored = realloc(dict_ignored, MAX_LENGTH_DICT_IGNORED*sizeof(char*));
        // space for my new value in slot
        new_word_to_add = calloc(strlen(word) + 1, sizeof(char));
        // add
        dict_ignored[MAX_LENGTH_DICT_IGNORED-1] = strcpy(new_word_to_add, word);
    }

}

/*******************************************************************
* NAME :            int is_known(char *word)
*
* DESCRIPTION :     Verifica si una palabra es "conocida", ya sea 
*                   porque esta en el diccionario principal o en el 
*                   diccionario de palabras ignoradas. 
*
* PARAMETERS:
*      INPUT:
*           char    *word       Palabra a verificar.
*
* RETURN :
*           Type: int
*           Values: 1 si la palabra es conocida
*                   0 si la palabra no es conocida
*******************************************************************/
int is_known(char *word) {
    

    int i, exist_in_main, exist_in_ignored = 0; // Convertion implicit to bool
    int found = 0;

    // for each dictionary, check if my word is equal to some word in dict
    for (i = 0; i < MAX_LENGTH_DICT_MAIN && !exist_in_main; ++i) {
        if (dict_main[i] != NULL) {
            exist_in_main = strcmp(dict_main[i], word) == 0;
        }
    }

    if (!exist_in_main) {
        for (i = 0; i < MAX_LENGTH_DICT_IGNORED && !exist_in_ignored; ++i) {
            if (dict_ignored[i] != NULL) {
                exist_in_ignored = strcmp(dict_ignored[i], word) == 0;
            }
    }

    // if the found the word, return 1 (equal to true)
    if (exist_in_ignored || exist_in_main) {
        return 1;
    } else {
        return 0;
    }
}


/*******************************************************************
* NAME :            int get_word(char *w)
*
* DESCRIPTION :     Lee una palabra del archivo de entrada, copiando 
*                   todo caracter de puntuacion precedente al archivo
*                   de salida.
* PARAMETERS:
*      OUTPUT:
*           char    *word       Palabra que se lee desde el archivo.
*
* RETURN :
*           Type: int
*           Values: 0 si no hay mas palabras para leer.  
*                   1 si hay mas palabras para leer.
*******************************************************************/
int get_word(char *word) {
    rewind(doc_in); /*cursor en el principio del archivo*/
    doc_in = fopen("in_file.txt", "r");
}

/*******************************************************************
* NAME :            void put_word(char *word)
*
* DESCRIPTION :     Escribe la palabra w al archivo de salida.
*
* PARAMETERS:
*      INPUT:
*           char    *word       Palabra a escribir.
*
* RETURN :
*           Type: void
*******************************************************************/
void put_word(char *word){
    /* completar aca  */
    doc_out = fopen("out_file.txt", "a");
    if(doc_out == NULL){
        printf("Error al abrir archivo");
    }
    else{
        fprintf(doc_out, "%s\n", word);
        printf("Ud ingreso: %s\n",word);
    }
    fclose(doc_out);
}

/*******************************************************************
* NAME:               void replace_word(char *word, char replace)
*
* DESCRIPTION:        Remplaza la palabra word por replace
*
* PARAMETERS:
*      INPUT:
*            char     *word    Palabra a ser remplazada.
*            char     replace  Palabra por la que se remplazara.
*
* RETURN:
*         Type: void
*******************************************************************/
void replace_word(char *word, char replace){

    file = fopen(doc_in, "r");
    while(feof(file) == 0){ //para recorrer todo el archivo
        char *ptr;
        char *palabra;
        ptr = malloc(sizeof(char));
        palabra = fgets(ptr, MAX_WORD_SIZE, file);

    }
}


/*******************************************************************
* NAME :            void consult_user(char *word)
*
* DESCRIPTION :     Consulta al usuario sobre que accion realizar 
*                   (aceptar, ignorar o reemplazar) con la palabra w.
*                   Una vez que el usuario elige, realiza la accion 
*                   elegida.
*
* PARAMETERS:
*      INPUT:
*           char    *word       Palabra sobre la cual se consulta la 
*                               accion a realizar.
*
* RETURN :
*           Type: void
*******************************************************************/
void consult_user(char *word){
    char ans[2];
    char replace[MAX_WORD_SIZE];
    do{
        printf("Palabra no reconocida: %s\n Aceptar (a) - Ignorar (i) - Reemplazar (r): ", word);
        scanf("%s", ans);
    }while((strcmp(ans,"r") != 0) && (strcmp(ans,"a") != 0) && (strcmp(ans,"i") != 0));
    /* completar aca  */
    if(strcmp(ans,"a") == 0){
        dict_add(word);
        printf("la palabra %s fue AGREGADA al diccionario\n",word);
    }
  
    if(strcmp(ans, "i") == 0){
        ignored_add(word);
        printf("la palabra %s fue IGNORADA\n",word);
    }

    if(strcmp(ans, "r") == 0){
        printf("Remplazar por:\n");
        scanf("%s",replace);
        replace_word(word,replace);
    }

}

/*******************************************************************
* NAME :            void process_document(char *fname)
*
* DESCRIPTION :     Procesa el documento fname, palabra por palabra, 
*                   consultando al usuario sobre la accion a realizar 
*                   si la palabra no es conocida.
* PARAMETERS:
*      INPUT:
*           char    *fname   Nombre del archivo a procesar.
*
* RETURN :
*           Type: void
*******************************************************************/
void process_document(char *fname) {
    char current_word[MAX_WORD_SIZE];

    //open a file
    FILE *my_document;
    my_document = fopen(fname, "a");

    if (my_document == NULL) {
        printf("ERROR: couldn't open document\n");
        exit(EXIT_FAILURE);
    }
    else {
        while(feof(my_document) == 0){
            char *ptr;
            ptr = malloc(sizeof(char));
            current_word = gets(ptr, MAX_WORD_SIZE, my_document); // ALGO PARECIDO A ESTO PORQUE gets devuelve un char*
            know = is_known(current_word);
            if(know == 0){         // la palabra es desconocida
                consult_user(current_word);
            }
            free(ptr);
            ptr = NULL;
        }
        
    }

}

/*******************************************************************
* NAME: bool is_valid_character(char* character)
*
* DESCRIPTION: Dada una lista de caracteres permitidos, evalúa si el
*              caracter recibido es válido.
*
* PARAMETERS:
*      INPUT:
*           char    *character   Caracter a evaluar.
*
* RETURN :
*           Type: bool
*******************************************************************/
bool is_valid_character(char *character) {
    bool is_valid = false;
    char *list_characters = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    
    // check if my character is in list_characters
    is_valid = strstr(list_characters, character) != NULL;

    return is_valid;
}

/****************************************************************************
* NAME :            void dict_destroy(char **dict_to_free, TOTAL_STORED_WORDS)
*
* DESCRIPTION :     Libera completamente el espacio alocado en algún
*                   diccionario.
*
* PARAMETERS:
*      IMPUT:
*           char    **dict_to_free      Diccionario a liberar.
*           int     TOTAL_STORED_WORDS  Cantidad total de palabras almacenadas 
*                                        en el diccionario a liberar
*
* OBSERVATIONS :
*    1) Utiliza como tamaño de memoria a liberar la cantidad de palabras
*       máximas que se han almacenado en el diccionario definido por:
*       MAX_LENGTH_DICT_MAIN para el caso de dict_main, 
*       MAX_LENGTH_DICT_IGNORED para el caso de dict_ignored
*
*    2) Un mal uso de estas variables globales puede conllevar a liberaciones
*       insuficientes o excesivas. 
*
*******************************************************************/
void dict_destroy(char **dict_to_free, int TOTAL_STORED_WORDS) {
    assert (dict_to_free != NULL);

    for (int i = 0; i < TOTAL_STORED_WORDS; ++i) {
        free(dict_to_free[i]);
    }
    free(dict_to_free);
}

/*******************************************************************
* NAME :            int main(int argc, char **argv)
*
* DESCRIPTION :     Punto de entrada principal. Abre el diccionario 
*                   principal, procesa el archivo especificado y 
*                   guarda los cambios realizados en el diccionario 
*                   principal.
*******************************************************************/
int main(int argc, char **argv){
    char *dict;
    /* Verificamos el nro de argumentos. */
    if (argc < 2) {
        printf("spellchecker.c: nro de argumentos erroneo. Deben ser <documento> [<diccionario>].\n");
        return (1);
    }
    /* si se especifico un diccionario lo usamos,  */
    /* caso contrario usamos el diccionario por defecto */
    dict = (argc >=3) ? argv[2] : "dict.txt";

    /* completar aca */
    dict_load(dict);
    process_document(argv[1]);
    dict_save(dict);

    dict_destroy(dict_main, MAX_LENGTH_DICT_MAIN);
    dict_destroy(dict_ignored, MAX_LENGTH_DICT_IGNORED);

    printf("El documento %s ha sido procesado. Resultados en out.txt\n", argv[1]);
    return EXIT_SUCCESS;
}