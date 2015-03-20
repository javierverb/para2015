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
int a_lval;
extern char* aname;
%}

			
%%
[ \t\n]* {
    /*Ignoro cualquier clase de tabulación o espacio o salto de línea*/
}


(p[^0](","|"\n")?){NUMBER_}|(P[^0](","|"\n")?){NUMBER_} {
    printf("%s\n", f_text);
    f_lval.v = get_prop_var(f_text);
    return TK_PROP;
}

true|"1" {printf("TRUE\n"); return TK_TRUE;}
false|"0" {printf("FALSE\n"); return TK_FALSE;}


. {
    log_error(" %s - lexer error - at line %d: %s\n",aname,a_lineno,a_text); 
}      
%%
