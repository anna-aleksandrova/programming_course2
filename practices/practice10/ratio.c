#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "ratio.h"

void output(Ratio x) {
    printf("%d / %u\n", x.num, x.den);
}

int input(Ratio *x) {
    printf("x / y = ");
    scanf("%d", &x -> num);
    scanf("%u", &x -> den);
    return 0;
}

unsigned int gcd(unsigned int n, unsigned int m) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (n == m) {
        return n;
    }
    if (n > m) {
        return gcd(n - m, m);
    }
    return gcd(n, m - n);
}

Ratio reduce(Ratio *x) {
    unsigned int temp = gcd(fabs(x -> num), x -> den);
    Ratio z;
    z.num = (x -> num) / temp;
    z.den = (x -> den) / temp;
    return z;
}

Ratio add(Ratio x, Ratio y) {
    Ratio z;
    z.num = x.num * y.den + x.den * y.num;
    z.den = x.den * y.den;
    return reduce(&z);
}

Ratio mult(Ratio x, Ratio y) {
    Ratio z;
    z.num = x.num * y.num;
    z.den = x.den * y.den;
    return reduce(&z);
}

bool greater(Ratio x, Ratio y) {
    int temp_x = x.num * y.den;
    int temp_y = y.num * x.den;
    if (temp_x > temp_y) {
        return true;
    }
    else {
        return false;
    }
}
