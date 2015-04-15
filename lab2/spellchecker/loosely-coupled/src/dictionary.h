#ifndef DICTIONARY_H
#define DICTIONARY_H

/* Estos dos renglones son los que importan */
struct Dictionary;
typedef struct Dictyonary *dict_s;


void dict_load();
void dict_save();
dict_add();
dict_contains();
dict_new();
dict_destroy();

ignored_add();

#endif