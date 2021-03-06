/* Archivo:: asignacion.l 
 * Descripcion:: Archivo de especificacion utilizado por lex. A partir de este
 * archivo lex genera el analizador lexico para parsear las asignaciones.
 */

%option  noyywrap case-insensitive yylineno
%option prefix="a_"

%{
#include "misc.h"
#include "aparser.tab.h"
#include <stdio.h>
extern char* aname;
%}
NUMBER [0-9]*
			
%%
[ \t]* {
    /*Ignoro cualquier clase de tabulación o espacio*/
}

:{1} {
    return TK_COLON;
}

((p|P)[^0]){NUMBER} {
    a_lval.v = get_prop_var(a_text);
    return TK_PROP;
}

(,|\n){1} {
    return TK_SEPARATOR;
}

true|1 {return TK_TRUE;}
false|0 {return TK_FALSE;}

. {
    log_error(" %s - lexer error - at line %d: %s\n",aname,a_lineno,a_text); 
}      
%%
