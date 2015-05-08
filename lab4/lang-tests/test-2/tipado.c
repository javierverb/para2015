#include <stdio.h>
#include <stdlib.h>


void function(char* a, int b){
	return a * b;
}

int main(void){

	int a = 123;
	printf("\n'a' es una variable de tipo entero\n");
	
	char* palabra = "hola a todos";
	printf("palabra es un string: %s\n\n", palabra);
	
	void result;
	result = function(palabra, a);

	return 0;
}

// PREGUNTAR PERO ES TIPADO FUERTE


