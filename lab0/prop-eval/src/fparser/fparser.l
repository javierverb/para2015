/* Archivo:: formula.l 
 * Descripcion:: Archivo de especificacion utilizado por lex. A partir de este
 * archivo lex genera el analizador lexico para el evaluador de
 * de formulas. Este analizador lexico debe reconocer los diferentes componentes
 * de una formula, los cuales transformara en tokens que enviara al analizador 
 * sintactico especificado en el archivo formula.y
 */


/* Descripcion de las opciones*/
%option noyywrap yylineno
%option prefix="f_"

/* Seccion de Declaraciones:: Todo lo que se encuentra entr
 * %{ y %} se copia textualmente a los distintos archivos de 
 * codigo generados por Flex.
*/
%{
#define _POSIX_SOURCE 1
#include "misc.h"
#include "ast.h" 
#include "fparser.tab.h"
#include <stdio.h>
extern char* fname;
%}


NUMBER_    [0-9]*

/* Seccion de Patrones y Acciones:: En esta seccion se listan */
/* los patrones que debe identificar el lexer y las acciones a ejecutar*/
/* cuando los encuentra. */
/* Los patrones se definen como expresiones regulares.  */
/* Las acciones son codigo en C. */

/* HINT: El patron (expresion regular) debe comenzar al principio de
/* * la linea (sin espacios antes), ya que flex considera cada linea que  */
/* * empieza con espacio como una linea de codigo valida. *\/ */
%%

begin|BEGIN     {return TK_BEGIN ;}
end|END         {return TK_END ;}


[ \t]* {
    /*Ignoro cualquier clase de tabulación o espacio*/
}

((P|p)0.){NUMBER_} {
    printf("REJECTED: Only accept Pi or pi:i!=0");
}



(p[0-9]+|P[0-9]+){NUMBER_} {
    printf("%s\n", f_text);
    f_lval.v = get_prop_var(f_text);
    return TK_PROP;
}

(&[^&]){NUMBER_} {
    printf("AND\n");
    f_lval.v = get_prop_var(f_text); 
    return TK_AND;
}

(v[^v]){NUMBER_} {
    printf("OR\n");
    f_lval.v = get_prop_var(f_text); 
    return TK_OR;
}

. {
    log_error(" %s - lexer error - at line %d: [%s]\n",fname,f_lineno,f_text); 
}
%%
/*Seccion de Codigo:: en esta seccion se puede colocar el codigo C
* necesario para ejecutar las acciones. Es comun agregar aca una rutina
* main para ejecutar el lexer y poder probarlo. */


