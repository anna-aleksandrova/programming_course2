#include <stdio.h>
#include <math.h>

double length(double x1, double x2, double y1, double y2) {
    double res;
    res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return res;
}

double area(double l1, double l2, double l3) {
    double p, area;
    p = (l1 + l2 + l3) / 2;
    area = sqrt(p * (p - l1) * (p - l2) * (p - l3));
    return area;
}

int main() {
    double x1, x2, y1, y2, z1, z2, res;
    printf("A = ");
    scanf("%lf %lf", &x1, &x2);
    printf("\nB = ");
    scanf("%lf %lf", &y1, &y2);
    printf("\nC = ");
    scanf("%lf %lf", &z1, &z2);
    res = area(length(x1, x2, y1, y2), length(z1, z2, y1, y2), length(x1, x2, z1, z2));
    printf("\nArea = %g\n", res);
}
