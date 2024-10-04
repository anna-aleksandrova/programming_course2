#include <stdio.h>
#include <math.h>

long double poly_a(long double x, unsigned int n) {
    long double res = 1, temp = x * x;
    for (int i = 0; i < n; i++) {
        res += temp;
        temp *= temp;
    }
    return res;
}

long double poly_b(long double x, unsigned int n) {
    long double res = 1, temp = x * x * x;
    for (int i = 0; i < n; i++) {
        res += temp;
        temp = temp * temp * temp;
    }
    return res;
}

long double poly_c(long double x, unsigned int n) {
    long double res = 0, aux = x * x, temp = x, temp_ = x * x * x;
    for (int i = 0; i < n; i++) {
        res += temp;
        temp *= temp_;
        temp_ *= aux;
    }
    return res;
}

void task12() {
    unsigned int n;
    long double x;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%Lf", &x);
    printf("a) f(x, n) = %Lf\n", poly_a(x, n));
    printf("b) f(x, n) = %Lf\n", poly_b(x, n));
    printf("c) f(x, n) = %Lf\n", poly_c(x, n));
}

long double exp_a(long double x, unsigned int n) {
    long double temp = 1, res = 1;
    for (int i = 1; i <= n; i++) {
        temp *= x - 1;
        res += temp;
    }
    return res;
}

long double exp_b(long double x, unsigned int n) {
    long double temp = 1.0, aux = x * x + 1, res = 1;
    for (int i = 1; i <= n; i++) {
        temp /= aux;
        res += temp;
    }
    return res;
}

long double exp_c(long double x, unsigned int n) {
    long double temp = sin(x), res = 1;
    for (int i = 1; i <= n; i++) {
        res += temp;
        temp *= sin(x);
    }
    return res;
}

long double exp_d(long double x, unsigned int n) {
    long double temp = x, res = 1;
    for (int i = 2; i <= n; i++) {
        res += i * temp;
        temp *= x;
    }
    return res;
}

long double exp_e(long double x, unsigned int n) {
    long double temp = x * pow(1 - x, n - 1), res = 0;
    for (int i = 1; i <= n; i++) {
        res += i * temp;
        temp *= (x / (1 - x));
    }
    return res;
}

void task13() {
    unsigned int n;
    long double x;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%Lf", &x);
    printf("a) f(x, n) = %Lf\n", exp_a(x, n));
    printf("b) f(x, n) = %Lf\n", exp_b(x, n));
    printf("c) f(x, n) = %Lf\n", exp_c(x, n));
    printf("d) f(x, n) = %Lf\n", exp_d(x, n));
    printf("e) f(x, n) = %Lf\n", exp_e(x, n));
}

void task14() {
    int m, n;
    unsigned int counter = 0;
    printf("m = ");
    scanf("%i", &m);
    if (m == 0) {
        printf("Sign changed 0 times.\n");
    }
    else {
        do {
            n = m;
            printf("m = ");
            scanf("%i", &m);
            if (m * n < 0) {
                counter += 1;
            }
        }
        while (m != 0);
        if (counter == 1) {
            printf("Sign changed 1 time.\n");            
        }
        else {
            printf("Sign changed %i times.\n", counter);
        }
    }
}

void task19a() {
    unsigned int n;
    double p = 2.0;
    printf("n = ");
    scanf("%u", &n);
    for (int i = 2; i <= n; i++) {
        p *= (1 + 1.0 / (i * i));
    }
    printf("a) p(%u) = %lf\n", n, p);
}

void task19b() {
    unsigned int n;
    double p = 0.75;
    printf("n = ");
    scanf("%u", &n);
    for (int i = 3; i <= n; i++) {
        p *= (1 - 1.0 / (i * i));
    }
    printf("b) p(%u) = %lf\n", n, p);
}

int main() {
    task19a();
    task19b();
}
