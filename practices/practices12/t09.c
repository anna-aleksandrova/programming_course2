#include <stdio.h>

int main(){
    double x, y, arithm, harm;
    printf("x, y = ");
    scanf("%lf %lf", &x, &y);
    arithm = (x + y) / 2;
    harm = (2 * x * y) / (x + y);
    printf("Arithmetic mean = %lf\n", arithm);
    printf("Arithmetic mean = %le\n", arithm);
    printf("Harmonic mean = %lf\n", harm);
    printf("Harmonic mean = %le\n", harm);
}