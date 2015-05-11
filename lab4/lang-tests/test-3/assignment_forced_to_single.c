#include <stdio.h>
#include <stdlib.h>

int main() {
    const int readOnlyVar = 10;
    printf("%d\n", readOnlyVar);
    /* Dado que una constante no puede cambiar
    este programa no compilará */
    readOnlyVar++;
}