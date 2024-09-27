#include <stdio.h>
#include <math.h>
#include <inttypes.h>

void task1() {
    unsigned int n;
    double res;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &res);
    for (int i = 0; i < n; i++) {
        res = sin(res);
    }
    printf("Result of n times applying sin() to x: %g\n", res);
}

void task2() {
    unsigned int n;
    printf("n = ");
    scanf("%i", &n);
    printf("n! = ");
    for (unsigned int i = 1; i < n; i++) {
        printf("%u*", i);
    }
    printf("%u\n", n);

    printf("n! = ");
    for (unsigned int i = n; i > 1; i--) {
        printf("%u*", n - i + 1);
    }
    printf("%u\n", n);
}

double poly1(unsigned int n, double x) {
    double res = 0, temp = 1;
    for (int i = 1; i < n + 1; i++) {
        temp *= x;
        res += temp;
    }
    return res + 1;
}

void test_poly1() {
    if (fabs(poly1(3, 2) - 15) < __DBL_EPSILON__) {
        printf("Test is passed.\n");
    }
    else {
        printf("Test is failed.\n");
    }
}

void task3a() {
    unsigned int n;
    double x;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);
    printf("Result = %g\n", poly1(n, x));
}

double poly2(unsigned int n, double x, double y) {
    double res = 0, temp1 = 1, temp2 = 1;
    for (int i = 1; i < n + 1; i++) {
        temp1 *= x * x;
        temp2 *= y;
        res += temp1 * temp2;
    }
    return res + 1;
}

void test_poly2() {
    if (fabs(poly2(4, 1, 2) - 31) < __DBL_EPSILON__) {
        printf("Test is passed.\n");
    }
    else {
        printf("Test is failed.\n");
    }
}

void task3b() {
    unsigned int n;
    double x, y;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("Result = %g\n", poly2(n, x, y));
}

void task4() {
    unsigned int n;
    double x, temp, res = 0;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);
    temp = x;
    for (int i = 2; i < n + 1; i++) {
        temp *= x;
        res += i * temp;
    }
    res += x;
    printf("Result = %g\n", res);
}

void task5() {
    unsigned int n, res;
    printf("n = ");
    scanf("%u", &n);
    res = n;
    for (int i = n - 2; i > 0; i -= 2) {
        res *= i;
    }
    printf("%u!! = %u\n", n, res);
}

void task6a() {
    unsigned int n;
    double res;
    printf("n = ");
    scanf("%u", &n);
    res = sqrt(2);
    for (int i = 0; i < n - 1; i++) {
        res = sqrt(2 + res);
    }
    printf("Result: %lf\n", res);
}

void task6b() {
    unsigned int n;
    double res;
    printf("n = ");
    scanf("%u", &n);
    res = sqrt(3*n);
    for (int i = 1; i < n; i++) {
        res = sqrt(3 * (n - i) + res);
    }
    printf("Result: %lf\n", res);
}

void task7() {
    unsigned int n;
    double x, temp, sum;
    printf("n = ");
    scanf("%u", &n);
    printf("x = ");
    scanf("%lf", &x);
    temp = 1;
    sum = 1;
    for (int i = 1; i < n + 1; i++) {
        temp *= x / i;
        sum += temp;
    }
    printf("Result: %g\n", sum);
}

void task8() {
    int m, k;
    long long temp;
    printf("m = ");
    scanf("%u", &m);
    temp = 4;
    k = 0;
    while (1) {
        if (temp > m) {
            break;
        }
        else {
            temp *= 4;
            k += 1;
        }
    }
    printf("k = %i\n", k);
}

void task9() {
    int n;
    long long temp;
    printf("n = ");
    scanf("%u", &n);
    temp = 2;
    do {
        temp *= 2;
    }
    while (temp <= n);
    printf("2 ^ r = %lli", temp);
}

void task10() {
    float a = 0.1;
    while (1 + a != 1) {
        a /= 2;
    }
    printf("Machine epsilon = %e", a);
}

void task11() {
    unsigned int i = 0;
    double temp, sum = 0, product = 1;
    while(1) {
        printf("a[%i] = ", i);
        scanf("%lf", &temp);
        if (fabs(temp) < __DBL_EPSILON__) {
            break;
        }
        sum += temp;
        product *= temp;
        i++;
    }
    printf("Sum = %g\n", sum);
    printf("Arithmetic mean = %g\n", sum / i);
    printf("Geometric mean = %g\n", pow(product, 1.0 / i));
}

unsigned long long subfactorial(unsigned int n) {
    if (n == 1) {
        return 0;
    }
    else {
        return n * subfactorial(n - 1) + pow((-1), n);
    }
}

void task12() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    printf("Subfactorial(%u) = %llu\n", n, subfactorial(n));
}

int main() {
    task12(); 
}
