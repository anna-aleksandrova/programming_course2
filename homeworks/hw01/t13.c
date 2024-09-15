#include <stdio.h>
#include <math.h>

int main(){
    double x;
    printf("x = ");
    scanf("%le", &x);
    printf("lg(%g) = %.3lf\n", x, log10(x));
}
