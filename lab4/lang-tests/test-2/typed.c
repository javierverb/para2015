#include <stdio.h>
#include <stdlib.h>

int main(void){

    int num = 123;
    printf("\n'a' es una variable de tipo entero\n");
    
    char* word = "hola a todos";
    printf("palabra es un string: %s\n\n", word);
    
    int result;
    result = word + num;
    printf("el resultado es %d\n",result);
    printf("C ES DE TIPADO DEBIL\n");

    return 0;
}
// c es de tipado DEBIL