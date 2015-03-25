PARTE 1 -- fparser

a v b & c. Puede ser considerado como:

a v (b & c)

a | b | c | b&c | a v (b & c)
T | T | T |  T  |     T
T | T | F |  F  |     T
T | F | T |  F  |	  T
T | F | F |  F  |	  T
F | T | T |  T  |	  T
F | T | F |  F  |	  F
F | F | T |  F  |	  F
F | F | F |  F  |	  F

ó como:
(a v b) & c

a | b | c | avb | (a v b) & c
T | T | T |  T  |     T
T | T | F |  T  |     F
T | F | T |  T  |	  T
T | F | F |  T  |	  F
F | T | T |  T  |	  T
F | T | F |  T  |	  F
F | F | T |  F  |	  F
F | F | F |  F  |	  F

La gramatica es ambigua, la solución es usar parentesis y precedencia, la precedencia en operadores es de la forma tal que los de MAYOR precedencia se encuentran en lo mas profundo del arbol generado, por lo tanto, es necesario cambiar el orden en la EBNF de modo tal que cumpla con la precedencia.
------------------------------
Se agregaron test a la carpeta test/test-formulas y en test/test-evaluator

Los scripts de carpetas de tests fueron modificados para que impriman en color los resultados de los tests, ademas de  eliminar los excedentes .log


