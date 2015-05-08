#include <stdio.h>

/*
int global = 1;

int function_a(int z){
    printf("z en function_a vale: %d\n",z);
    printf("global en function_a vale: %d\n",global);
    printf("como global vale 4 entonces tomo el valor del bloque en function_b\n");
    printf("entonces C tiene un ALCANCE ESTATICO\n");
    return z + global;
}

int function_b(int y){
    printf("\ny en function_b vale: %d\n",y);
    int global = y+1;
    printf("global es local para function_b y vale: %d\n\n",global);
    return (function_a(global*y));
}


int main(void){
    int res = 0;
    res = function_b(3);
    printf("%d\n\n",res);

    return 0;
}
*/

int main(void){
    {
        {
            int x = 10, y  = 20;
            {
                printf("\nprimer print: x, y toman el valor del bloque contenedor\n");
                printf("x = %d, y = %d\n\n", x, y);
                {
                    int y = 40;
    
                    x++;
                    y++;

                    printf("x aumenta en 1, toma el valor del bloque contenedor\n");
                    printf("y es redefinido, NO ES EL MISMO 'y' que el del bloque contenedor \n");      
                    printf("x = %d, y = %d\n\n", x, y);
                }
            printf("x en nungun momento se redefinio, por lo tanto cuando se hace x++ toma el valor del bloque principal\n");
            printf("es decir, no se creo una varieble nueva como fue en el caso de 'y'\n");
            printf("x = %d, y = %d\n\n", x, y);
            }
        }
    return 0;
    }
}