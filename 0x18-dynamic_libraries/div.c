#include <stdio.h>
int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0;  // or handle the error as you see fit
    }
}
