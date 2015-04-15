#ifndef DICTIONARY_H
#define DICTIONARY_H

/* Estos dos renglones son los que importan */
struct Dictionary;
typedef struct Dictyonary *dict_s;


void dict_load(*char filename, dict_s d);
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


void dict_save(char* fname, dict_s d);
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


void dict_add(char* word, dict_s d);
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


dict_contains();

dict_s dict_new(void);
/*******************************************************************
* NAME :            dict_s dict_new(void)
*
* DESCRIPTION :     Crea un nuevo diccionario
*
* PARAMETERS:
*      INPUT:
*           void

* RETURN :
*           Type: dict_s
* OBSERVATIONS :
*    1) el parametro de entrada podria ser dict_s d ??
*******************************************************************/


dict_s dict_destroy(dict_s d);
/*******************************************************************
* NAME :            dict_s dict_destroy(dict_s d)
*
* DESCRIPTION :     Elimina el diccionario vaciando todos sus 
*                   contenidos.
*
* PARAMETERS:
*      INPUT:
*           dict_s    d       Diccionario a eliminar

* RETURN :
*           Type: dict_s
*******************************************************************/


void ignored_add(char* word, dict_s d);
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

#endif