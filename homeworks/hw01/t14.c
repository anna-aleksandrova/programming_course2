#include <stdio.h>

int main() {
    double a, t, s, v;
    printf("a = ");
    scanf("%lf", &a);
    printf("t = ");
    scanf("%lf", &t);
    printf("v = ");
    scanf("%lf", &v);
    s = a * t * t / 2;
    printf("The distance the body will travel in %g seconds = %g\n", t, s);
    t = v / a;
    printf("Time needed to reach the velocity of %g = %g\n", v, t);
}
