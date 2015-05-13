#include <stdio.h>

void interchange(int x1, int y1){
    
    int z1 = 0;
    printf("\nInside interchange function before interchange\n");
    printf("x1 = %d \ny1 = %d\n", x1, y1);

    z1 = x1;
    x1 = y1;
    y1 = z1;

    printf("Inside interchange function after interchange\n");
    printf("x1 = %d\ny1 = %d\n", x1, y1);

}

int main(void){
    
    int x=50, y=70;
    printf("\nfunction main:\n");
    printf("x = %d\ny = %d\n", x, y);

    interchange(x,y);
    printf("\nfunction main:\n");
    printf("x = %d\ny = %d\n", x, y);
    printf("\nEl programa realiza pasaje por valor (call_by_value)\n\n");

    return 0;

}