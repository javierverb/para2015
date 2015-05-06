#include <stdio.h>
#include <stdlib.h>

float doble(float var){
	float result = var * 2;
	return result;
}

int main(void){
	//int a = 123;
	//char* b = "hola mundo";
	//char* result ="esto es el resultado";
	//printf("eso es b: %s\n\n",b);
	//printf("trataremos de multiplicar\nun int con char*, C es fuertemente tipado\n sdeberia tirar error");
	//result = a * b;
	//printf("%s\n", result);

	float a = 0.0;

	a = doble(2);
	printf("%f\n",a);


	return 0;
}