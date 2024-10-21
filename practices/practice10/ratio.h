// header for ratio.c
#include <stdio.h>
#include <stdbool.h>

typedef struct Ratio {
    int num;
    unsigned int den;
} Ratio;
void output(Ratio x);
int input(Ratio *x);
unsigned int gcd(unsigned int n, unsigned int m);
Ratio reduce(Ratio *x);
Ratio add(Ratio x, Ratio y);
Ratio mult(Ratio x, Ratio y);
bool greater(Ratio x, Ratio y);
