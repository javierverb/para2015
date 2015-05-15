#include <stdio.h>

int factorial(int n) {

    if (n == 0 || n == 1) {
      return 1;
    }

    return n * factorial(n-1);
}

int main(int argc) {
    int answer = factorial(15);
    printf("%d\n", answer);
}

// con -O2
