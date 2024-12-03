#include <iostream>
#include "rational.h"

template <typename T> T my_max(T a, T b) {
    return a > b ? a : b;
}

template <typename T> T* our_max(T* a, T*b) {
    int n = strlen(a);
    int m = strlen(b);
    int k = std::min(n, m);
    for (int i = 0; i < k; i++) {
        if (a[i] > b[i]) {return a;}
        else if (a[i] < b[i]) {return b;}
    }
    if (n > k) {return a;}
    else {return b;}
}

int main() {
    Rational r1(-1, 3);
    Rational r2(-2, 3);
    Rational r3 = my_max(r1, r2);
    std::cout << r3 << std::endl;
}
