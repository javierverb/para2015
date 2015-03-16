/* Archivo:: formula.y
 * Descripcion:: Archivo de especificacion utilizado por bison. 
 */

/* Describir esto*/

%name-prefix "f_"

%{
#define _POSIX_C_SOURCE 1
 #include <stdio.h>
 #include "misc.h"
 #include "ast.h" 
 extern int f_lex();
 extern int f_error(char *s);
 extern int f_lex_destroy(); 
 extern FILE *f_in;
 extern int f_lineno;
 ASTNode *ast;
 char *fname;
 /*nodo temporal que se usa para crear el AST. */
 ASTNode *n;
%}

/* Declaracion de yyval: yyval es la variable que  */
%union {
  ASTNode *a;
  int v;
  unsigned int nat;
}

/* Tokens*/
%token <v> TK_PROP
%token TK_BEGIN
%token TK_END
%token TK_OR
%token TK_AND
%token <nat> TK_NATURAL_NUMBER

 /* Define el tipo de datos que retorna la bnf*/
%type <a> input phi prop number
%%
/* Simbolo inicial */
input: TK_BEGIN phi TK_END {ast = $2;};

/* COMPLETAR ACA */
phi: prop
    | phi TK_OR phi {ASTNODE_OR(n,$1, $3); $$=n;}
    | phi TK_AND phi {ASTNODE_AND(n,$1, $3); $$=n;}
;
prop: TK_PROP {ASTNODE_PROP(n,$1); $$ =n ;}
| TK_PROP number {ASTNODE_PROP(n,$1); $$ =n ;}
;
number: TK_NATURAL_NUMBER {$$ =n;}
;
%%

/* Funcion que se provee para parsear una formula en un archivo.*/
void parse_formula(FILE * input)
{
  f_lineno = 1;
  f_in = input;
  if (!f_in)
    log_error("parse_formula: no input file.");
  f_parse();
  f_lex_destroy();
}

/* Funcion que se ejecuta cuando ocurre un error durante el parseo.*/
int f_error(char *s)
{
    log_error(" %s - parser error - %s\n",fname,s);
    return 0;
}
