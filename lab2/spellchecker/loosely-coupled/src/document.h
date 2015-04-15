#ifndef DOCUMENT_H
#define DOCUMENT_H

/* Estos dos renglones son los que importan */
struct Document;
typedef struct Document *doc_s;

doc_get_word();
doc_put_word();
doc_open();
doc_close();

#endif