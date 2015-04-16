#ifndef DOCUMENT_H
#define DOCUMENT_H

/* Estos dos renglones son los que importan */
struct Document;
typedef struct Document *doc_s;


int doc_get_word(char* word, doc_s document);
/*******************************************************************
* NAME :            int get_word(char *word)
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


void doc_put_word(doc_s document, char* word);
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


doc_s doc_open(char *doc_to_open);

void doc_close(doc_s document);

#endif