#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int fuerte = 0;
	char *string = "Esto es un string";
	char *resultado = "Nunca tomare este valor";
	/* La definición de estático determina que
	si el tipo ya está definido, SÓLO podemos
	realizar operaciones definida para este tipo
	a menos que la conversión a -otro- tipo sea 
	explícita: */

	resultado = string * fuerte;

	printf("%s\n", resultado);

	return EXIT_SUCCESS;

}