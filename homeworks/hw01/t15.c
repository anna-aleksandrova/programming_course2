#include <stdio.h>

int main(){
    double m, v;
    printf("m = ");
    scanf("%lf", &m);
    printf("v = ");
    scanf("%lf", &v);
    printf("E = %lf\n", m * v * v / 2);
}
