#include <stdio.h>
#include <stdlib.h>

int main(void){
	int* a = NULL;
	float b = 0.0;
	float result = 0;

	a = calloc(1,sizeof(int));
	*a = 3;
	b = 3.14;
	printf("a es %d\n",*a);
	printf("b es %f\n",b);

	result = *a + b;
	printf("el resultado de la suma de a y b es %f\n",result);

	return 0;
}