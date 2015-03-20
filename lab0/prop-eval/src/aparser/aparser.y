/* Archivo:: asignacion.y
 * Descripcion:: Archivo de especificacion utilizado por bison. 
 */

/* Describir esto*/

%name-prefix "a_"

%{
 #include <stdio.h>
 #include "misc.h"
 #include "assignment.h"

 /*funciones definidas por el lexer*/
 extern int a_lex();
 extern int a_error(char *s);
 extern int a_lex_destroy(); 
 extern FILE *a_in;
 extern int a_lineno;
 
 Asgmnt *asg; 
 char *aname;
%}
%union {
  Asgmnt *a;
  int v;
}

/* COMPLETAR AQUI */
%token <v> TK_PROP
%token TK_TRUE
%token TK_FALSE
%token TK_COMA
%token TK_NEW_LINE

%type <a> asgmnt vval prop bool

%%
asgmnt: vval
        | vval TK_COMA asgmnt {}
        | vvaln TK_NEW_LINE asgmnt
;
vval: prop TK_COLON bool {};
;
prop: TK_PROP {};
;
bool: TK_TRUE {$$=$1;}| TK_FALSE {$$=$2}
;



%%
/* Funcion que se provee para parsear una asignacion en un archivo.*/
void parse_assignment(FILE * input)
{
  a_lineno = 1;
  a_in = input;
  if (!a_in)
    log_error("parse_assignment: no input file.");
  a_parse();
  a_lex_destroy();
}


/* Funcion que se ejecuta cuando ocurre un error durante el parseo.*/
int a_error(char *s)
{
  log_error(" %s - parser error - %s\n",aname,s);
  return 0;
}
