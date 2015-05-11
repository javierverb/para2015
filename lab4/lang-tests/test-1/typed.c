#include <stdlib.h>
#include <stdio.h>

int main() {
    
    int tstatic = 222;
    // esto explotará en tiempo de compilación al asignar
    // algo que no se corresponde con el tipo definido a 
    // la variable siempre y cuando coloquemos -Werror en 
    // la compilación
    tstatic = "boom";
    printf("%s\n", tstatic);

    return EXIT_SUCCESS;
}