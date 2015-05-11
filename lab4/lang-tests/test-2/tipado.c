#include <stdio.h>
#include <stdlib.h>

float doble(float var){
	float result = var * 2;
	return result;
}

int main(void){

	float a = 0.0;

	a = doble(2);
	printf("%f\n",a);

	return 0;
}