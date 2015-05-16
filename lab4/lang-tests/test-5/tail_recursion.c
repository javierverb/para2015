#include <stdio.h>
int tail_rec(int number) {
    if (number == 0) {
        // break here! 
        return 1;
    }
    else {
        return 1 + tail_rec(number-1);
    }
}

int main() {
    int result = tail_rec(10);
    printf("tail_rec(10) result is: %d\n", result);
    return 0;
}

// con -O2