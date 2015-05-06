#include <stdio.h>

int global = 1;

int function_a(int z){
	printf("z en function_a vale: %d\n",z);
	printf("global en function_a vale: %d\n",global);
	printf("como global vale 4 entonces tomo el valor del bloque en function_b\n");
	printf("entonces C tiene un ALCANCE DINAMICO\n");
	return z + global;
}

int function_b(int y){
	printf("\ny en function_b vale: %d\n",y);
	global = y+1;
	printf("global es local para function_b y vale: %d\n\n",global);
	return (function_a(global*y));
}


int main(void){
	int res = 0;
	res = function_b(3);
	printf("%d\n\n",res);

	return 0;
}