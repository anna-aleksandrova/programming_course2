#include <stdio.h>
#include <math.h>

double Rosenbrock2d(double x, double y) {
    double res = 100 * pow((x * x - y), 2) + pow(x - 1, 2);
    return res;
}

int test() {
    if (Rosenbrock2d(0, 0) == 1 && Rosenbrock2d(1, 1) == 0 && Rosenbrock2d(-1, 0) == 104) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    double x, y;
    int res = test();
    if (res == 1) {
        printf("Tests passed successfully.\n");
        printf("x = ");
        scanf("%lf", &x);
        printf("y = ");
        scanf("%lf", &y);
        printf("Rosenbrock2d(%g, %g) = %g\n", x, y, Rosenbrock2d(x, y));
    }
    else {
        printf("Tests failed.\n");
    }
}