#include <stdio.h>
#include <math.h>
#include <float.h>

int main(){
    double x, f, c, z, d, r;
    printf("x = ");
    scanf("%lf", &x);
    f = floor(x);
    c = ceil(x);
    r = round(x);
    z = (int) x;
    d = x - z;
    printf("floor(%.2lf) = %.2lf\n", x, f);
    printf("ceil(%.2lf) = %.2lf\n", x, c);
    printf("z(%.2lf) = %.2lf\n", x, z);
    printf("d(%.2lf) = %.2lf\n", x, d);
    printf("r(%.2lf) = %.2lf\n", x, r);
}