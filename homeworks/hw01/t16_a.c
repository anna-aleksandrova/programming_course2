#include <stdio.h>
#include <math.h>

int main() {
    printf("x----");
    for (int i = 1; i < 6; i++) {
        printf("|-%i-", i);
    }
    printf("|\n-----");
    for (int i = 1; i < 6; i++) {
        printf("|---");
    }
    printf("|\nF(x)");
    for (int i = 1; i < 6; i++) {
        printf("|%.2lf", exp(-pow(i, 2)));
    }
    printf("|\n");
}
