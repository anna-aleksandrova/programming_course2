#include <stdio.h>
#include <math.h>
#define infinity 1.7E+308

int even() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n % 2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int last_digit(){
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n % 10 == 5) {
        return 1;
    }
    else {
        return 0;
    }
}

int multiple() {
    unsigned int n, m;
    printf("n = ");
    scanf("%u", &n);
    printf("m = ");
    scanf("%u", &m);
    if (n % m == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int multiples() {
    unsigned int n, m, k;
    printf("n = ");
    scanf("%u", &n);
    printf("k = ");
    scanf("%u", &k);
    printf("m = ");
    scanf("%u", &m);
    if (n % m == 0 && k % m == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void task19() {
    printf("%d\n", even());
    printf("%d\n", last_digit());
    printf("%d\n", multiple());
    printf("%d\n", multiples());
}

double softExponential(double a, double x) {
    if (a < 0) {
        return -log(1 - a * (x + a)) / a;
    }
    else if (fabs(a) < __DBL_EPSILON__) {
        return x;
    }
    else {
        return (exp(a * x) - 1) / a + a;
    }
}

double der_softExponential(double a, double x) {
    double temp;
    if (a < 0) {
        temp = 1 - a * a - a * x;
        if (fabs(temp) < __DBL_EPSILON__) {
            return infinity;
        }
        else {
            return 1 / temp;
        }
    }
    else if (fabs(a) < __DBL_EPSILON__) {
        return 1;
    }
    else {
        return pow(exp(x), a);
    }
}

void task23() {
    double a, x, x0;
    printf("a = ");
    scanf("%lf", &a);
    printf("x = ");
    scanf("%lf", &x);
    printf("x0 = ");
    scanf("%lf", &x0);
    printf("SoftExponential(%g, %g) = %g\n", a, x, softExponential(a, x));
    printf("SoftExponential_der(%g, %g) = %g\n", a, x0, softExponential(a, x0));
}

int main() {
    task23();
}
