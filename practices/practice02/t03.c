#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
    double a, b, c, area, p;
    while(true) {
        printf("a = ");
        scanf("%lf", &a);
        printf("b = ");
        scanf("%lf", &b);
        printf("c = ");
        scanf("%lf", &c);
        if (a < b + c && b < a + c && c < a + b){
            break;
        }
        else {
            printf("Invalid values: triangle inequality doesn't hold.\n");
        }
    }
    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("Area = %g\n", area);
}