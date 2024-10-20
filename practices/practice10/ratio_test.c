#include <stdio.h>
#include "ratio.h"

int main() {
    Ratio a, b, c, d;
    input(&a);
    input(&b);
    c = add(a, b);
    output(c);
    d = mult(a, b);
    output(d);
    printf("a > b : %i", greater(a, b));
}
