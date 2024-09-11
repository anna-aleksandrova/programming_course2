#include <stdio.h>
#include <math.h>

int main(){
    float x1 = pow(10, -4);
    printf("10^(-4) = %.2f\n", x1);
    double x2 = 24.33E5;
    printf("24.33E5 = %.2lE\n", x2);
    long double x3 = exp(1);
    printf("e = %.2Lf\n", x3);
    long double x4 = pow(5, 0.5);
    printf("5^(0.5) = %.2Lf\n", x4);
    long double x5 = log(100);
    printf("ln(100) = %.2Lf\n", x5);
}