#include <stdio.h>

double fa(double x) {
    double res, x_2;
    x_2 = x * x;
    return 1 + 2 * x_2 + x_2 * x_2;
}

double fb(double x) {
    double res, x_2;
    x_2 = x * x;
    return 1 + x + x_2 + x_2 * x + x_2 * x_2;
}

double fc(double x) {
    double temp_1, temp_2;
    temp_1 = x + 1;
    temp_2 = temp_1 * temp_1;
    return (temp_2 * temp_2) * temp_1;
}

double fd(double x) {
    double x_2, x_3;
    x_2 = x * x;
    x_3 = x_2 * x;
    return 1 + x_3 + (x_3 * x_3) * x_3;
}

double fe(double x) {
    double x_2, x_3;
    x = 2 * x;
    x_2 = x * x;
    x_3 = x_2 * x;
    return x_2 * x_2 + x_3 + x_2 + x + 1;
}

double fg(double x) {
    double temp, temp_2;
    temp = x * x;
    temp_2 = temp * temp + 1;
    return (x * temp_2) * temp_2;
}

int main() {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("a) f(%g) = %g\n", x, fa(x));
    printf("b) f(%g) = %g\n", x, fb(x));
    printf("c) f(%g) = %g\n", x, fc(x));
    printf("d) f(%g) = %g\n", x, fd(x));
    printf("e) f(%g) = %g\n", x, fe(x));
    printf("f) f(%g) = %g\n", x, fg(x));
}