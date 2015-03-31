#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//tamaño maximo de una palabra
#define MAX_WORD_SIZE 30
#define MAX_LENGTH_DICT_MAIN 200
#define MAX_LENGTH_DICT_IGNORED 100
/* diccionario principal */
char **dict_main;
/*tamaño inicial del diccionario principal*/
int main_size = 10;

/* diccionario de palabras ignoradas */
char **dict_ignored;
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
void dict_load(char *fname){
   /* completar aca */
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
void dict_save(char *fname){
/* completar aca  */
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
/* completar aca */
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
void ignored_add(char *word){
/* completar aca  */
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
        exist_in_main = strcmp(dict_main[i], word) == 0;
    }

    if (!exist_in_some_dictionary) {
        for (i = 0; i < MAX_LENGTH_DICT_IGNORED && !exist_in_ignored; ++i) {
          exist_in_ignored = strcmp(dict_ignored[i], word) == 0;
    }

    // if the found the word, return 1 (equal to true)
    found = exist_in_ignored == 1 || exist_in_main == 1;

    return found;
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
int get_word(char *word){
/* completar aca */
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
    printf("ingrese palabra a agregar: ");
    scanf("%s", word);
    printf("ud ingresara: %s\n", word);
    fprintf(doc_out, "%s\n", word);
    fclose(doc_out);
}

;/*******************************************************************
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
    scanf("%s",remplazo);
    /*falta*/
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
void process_document(char *fname){
   char current_word[MAX_WORD_SIZE];
   /* completar aca */
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
   if (argc < 2)
     {
       printf("spellchecker.c: nro de argumentos erroneo. Deben ser <documento> [<diccionario>].\n");
       return (1);
     }
   /* si se especifico un diccionario lo usamos,  */
   /* caso contrario usamos el diccionario por defecto */
   dict = (argc >=3) ? argv[2] : "dict.txt";
  
   /* completar aca */
  
   printf("El documento %s ha sido procesado. Resultados en out.txt\n", argv[1]);
}

