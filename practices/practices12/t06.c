#include <stdio.h>

int main(){
    double cels, fahr;
    printf("C = ");
    scanf("%lf", &cels);
    fahr = ((9 * cels) / 5) + 32;
    printf("F = %g\n", fahr);
}