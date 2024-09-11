#include <stdio.h>

int main(){
    double x, x_2, x_3, x_4, x_5, x_6, x_8, x_9, x_15, x_16, x_28, x_32, x_64;
    scanf("%lf", & x);

    x_2 = x * x;
    x_4 = x_2 * x_2;
    printf("(%.2lf)^4 = %.2lf\n", x, x_4);

    x_6 = x_2 * x_4;
    printf("(%.2lf)^6 = %.2lf\n", x, x_6);

    x_3 = x * x_2;
    x_6 = x_3 * x_3;
    x_9 = x_3 * x_6;
    printf("(%.2lf)^9 = %.2lf\n", x, x_9);

    x_5 = x_3 * x_2;
    x_15 = (x_5 * x_5) * x_5;
    printf("(%.2f)^15 = %.2lf\n", x, x_15);

    x_8 = x_4 * x_4;
    x_28 = ((x_8 * x_8) * x_8) * x_4;
    printf("(%.2f)^28 = %.2lf\n", x, x_28);

    x_16 = x_8 * x_8;
    x_32 = x_16 * x_16;
    x_64 = x_32 * x_32;

    printf("(%.2f)^64 = %.2lf\n", x, x_64);
}