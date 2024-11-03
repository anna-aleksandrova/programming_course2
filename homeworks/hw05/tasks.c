#include <stdio.h>

void task11g() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n == 1) {
        printf("S(%u) = 0", n);
    }
    else if (n == 2) {
        printf("S(%u) = 2", n);
    }
    else {
        long double sum = 2;
        long long aux = 2;
        long double a1 = 0, a2 = 1, ai;
        for (int i = 3; i < n + 1; i ++) {
            ai = a2 + a1 / aux;
            aux *= i;
            sum += aux * ai;
            a1 = a2;
            a2 = ai;
        }
        printf("S(%u) = %Lg\n", n, sum);
    }
}

void task16g() {
    double eps;
    long double sum = 0, aux = 1, x;
    unsigned int i = 0;
    printf("eps = ");
    scanf("%lf", &eps);
    printf("x = ");
    scanf("%Lf", &x);
    while (1) {
        if (aux < eps) {
            break;
        }
        sum += aux;
        aux *= x * x / (2 * i + 1) / (2 * i + 2);
        i += 1;
    }
    printf("cosh(%Lg) = %Lg\n", x, sum);
}

int main() {
    task16g();
}
