#include <stdio.h>
const double lambda = 6.673e-11;

int main(){
    double m1, m2, r, F;
    printf("m1 = ");
    scanf("%lf\n", &m1);
    printf("m2 = ");
    scanf("%lf\n", &m2);
    printf("r = ");
    scanf("%lf\n", &r);
    F = (lambda * m1 * m2) / (r * r);
    printf("F = %le\n", F);
}