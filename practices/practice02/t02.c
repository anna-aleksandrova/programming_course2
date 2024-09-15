#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
    double a, b, c;
    while (true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        if (a > 0 && b > 0) {
            break;
        }
        else {
            printf("Invalid values: sides can't have non-positive values.\n");
        }
    } 
    c = sqrt(a * a + b * b);
    printf("c = %g\n", c);
}