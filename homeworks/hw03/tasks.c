#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

void task8() {
    uint32_t a, b;
    int overflow;
    printf("a = ");
    scanf("%u", &a);
    printf("b = ");
    scanf("%u", &b);
    if (a > UINT32_MAX - b) {
        printf("Integer overflow during addition.\n");
    }
    else {
        printf("%"PRIu32" + %"PRIu32" = %"PRIu32"\n", a, b, a + b);
    }
    if (UINT32_MAX / (b + 0.0) < a) {
        printf("Integer overflow during multiplication.\n");
    }
    else {
        printf("%"PRIu32" * %"PRIu32" = %"PRIu32"\n", a, b, a * b);
    }
}

double max(double x, double y, double z) {
    double max;
    (x > y) ? (max = x) : (max = y);
    (z > max) ? (max = z) : 1;
    return max;
}

void task9() {
    double x, y, z;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("z = ");
    scanf("%lf", &z);
    printf("a) max(%g, %g, %g) = %g\n", x, y, z, max(x + y + z, x * y - x * z + y * z, x * y *z));
    printf("b) max(%g, %g, %g) = %g\n", x, y, z, max(x * y, x * z, y *z));
}

void task10() {
    double x, y, z, a, arithm_mean;
    unsigned int counter_mean = 0, counter_input = 0;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("z = ");
    scanf("%lf", &z);
    printf("a = ");
    scanf("%lf", &a);
    if (x == y && y == z) {
        printf("a) 0 different values in (%g, %g, %g)\n", x, y, z);
        printf("b) 3 equal values in (%g, %g, %g)\n", x, y, z);
    }
    else if (x != y && y != z && x != z) {
        printf("a) 3 different values in (%g, %g, %g)\n", x, y, z);
        printf("b) 0 equal values in (%g, %g, %g)\n", x, y, z);
    }
    else {
        printf("a) 2 different values in (%g, %g, %g)\n", x, y, z);
        printf("b) 2 equal values in (%g, %g, %g)\n", x, y, z);
    }
    double arr[3] = {x, y, z};
    arithm_mean = (x + y + z) / 3;
    for (int i = 0; i < 3; i++) {
        if (arr[i] > arithm_mean) {
            counter_mean += 1;
        }
        if (arr[i] > a) {
            counter_input += 1;
        }
    }
    if (counter_mean == 1){
        printf("c) %i number in (%g, %g, %g) are greater than the arithmetic mean of (%g, %g, %g)\n", counter_mean, x, y, z, x, y, z);      
    }
    else {
        printf("c) %i numbers in (%g, %g, %g) are greater than the arithmetic mean of (%g, %g, %g)\n", counter_mean, x, y, z, x, y, z);  
    }
    if (counter_input == 1) {
        printf("d) %i number in (%g, %g, %g) are greater than <%g>\n", counter_input, x, y, z, a);
    }
    else {
        printf("d) %i numbers in (%g, %g, %g) are greater than <%g>\n", counter_input, x, y, z, a);
    }
}

double f1_abs(double x) {
    if (x > 0) {
        return x;
    }
    else {
        return -x;
    }
}

double f2_abs(double x) {
    if (x > 1) {
        return x - 2;
    }
    else if (x > 0 && x <= 1) {
        return -x;
    }
    else if (x < -1) {
        return -x - 2;
    }
    else {
        return x;
    }
}

double sign(double x) {
    if (fabs(x) < __DBL_EPSILON__) {
        return 0;
    }
    else if (x > 0) {
        return 1;
    }
    else {
        return -1;
    }
}

void task11() {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    printf("a) f1(%g) = %g\n", x, f1_abs(x));
    printf("b) f2(%g) = %g\n", x, f2_abs(x));
    printf("c) f3(%g) = %g\n", x, sign(x));
    printf("d) f4(%g) = %g\n", x, sin(f1_abs(x)));
}

void task12() {
    double a, b, c;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    if (a < b + c && b < a + c && c < a + b) {
        printf("There exists a triangle with the sides of length <%g>, <%g>, <%g>\n", a, b, c);
        double cos_a, cos_b, cos_c;
        cos_a = (b * b + c * c - a * a) / (2 * b * c);
        cos_b = (a * a + c * c - b * b) / (2 * a * c);
        cos_c = (a * a + b * b - c * c) / (2 * a * b);
        if (fabs(cos_a) < __DBL_EPSILON__ || fabs(cos_b) < __DBL_EPSILON__ || fabs(cos_c) < __DBL_EPSILON__) {
            printf("The triangle is right.\n");
        }
        else if (cos_a < 0 || cos_b < 0 || cos_c < 0) {
            printf("The triangle is obtuse.\n");
        }
        else {
            printf("The triangle is acute.\n");
        }
    }
    else {
        printf("Such a triangle doesn't exist.\n");
    }
}

int even() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n % 2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int last_digit(){
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n % 10 == 5) {
        return 1;
    }
    else {
        return 0;
    }
}

int multiple() {
    unsigned int n, m;
    printf("n = ");
    scanf("%u", &n);
    printf("m = ");
    scanf("%u", &m);
    if (n % m == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int multiples() {
    unsigned int n, m, k;
    printf("n = ");
    scanf("%u", &n);
    printf("k = ");
    scanf("%u", &k);
    printf("m = ");
    scanf("%u", &m);
    if (n % m == 0 && k % m == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int twodigits() {
    unsigned int x, temp;
    printf("x = ");
    scanf("%i", &x);
    while (1) {
        if (x >= 10 && x <= 99) {
            break;
        }
        else {
            printf("Incorrect value: two-digits positive integer is expected.\n");
        }
    }
    temp = x % 10 + x / 10;
    if (temp >= 10 && temp <= 99) {
        return 1;
    }
    else {
        return 0;
    }
}

int difference() {
    double x, y;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    if (x - y >= 7) {
        return 1;
    }
    else {
        return 0;
    }
}

int greater99() {
    double x, y, z;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("z = ");
    scanf("%lf", &z);
    if (x > 99 || y > 99 || z > 99) {
        return 1;
    }
    else {
        return 0;
    }
}

int less1001() {
    double x, y, z;
    printf("x = ");
    scanf("%lf", &x);
    printf("y = ");
    scanf("%lf", &y);
    printf("z = ");
    scanf("%lf", &z);
    if (x < 1001 && y >= 1001 && z >= 1001 || x >= 1001 && y < 1001 && z >= 1001 || x >= 1001 && y >= 1001 && z < 1001) {
        return 1;
    }
    else {
        return 0;
    }
}

void task19() {
    printf("%d\n", even());
    printf("%d\n", last_digit());
    printf("%d\n", multiple());
    printf("%d\n", multiples());
    printf("%d\n", twodigits());
    printf("%d\n", greater99());
    printf("%d\n", less1001());
}

double onestep(double x) {
    if (x > 0 || fabs(x) < __DBL_EPSILON__) {
        return 1;
    }
    else {
        return 0;
    }
}

double der_onestep(double x) {
    if (fabs(x) < __DBL_EPSILON__) {
        return __DBL_MAX__;
    }
    else {
        return 0;
    }
}

double ReLu(double x) {
    if (x > 0) {
        return x;
    }
    else {
        return 0;
    }
}

double der_ReLu(double x) {
    if (fabs(x) < __DBL_EPSILON__) {
        return __DBL_MAX__;
    }
    else if (x > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

double leakyReLu(double x, double a) {
    if (x < 0) {
        return a * x;
    }
    else {
        return 0;
    }
}

double der_leakyReLu(double x, double a) {
    if (fabs(a) < 0 || x > 0) {
        return 0;
    }
    else if (fabs(x) < 0) {
        return __DBL_MAX__;
    }
    else {
        return a;
    }
}

double eReLu(double a, double x) {
    if (x < 0) {
        return a * (exp(x) - 1);
    }
    else {
        return 0;
    }
}

double der_eReLu(double a, double x) {
    if (fabs(a) < __DBL_EPSILON__ || x > 0) {
        return 0;
    }
    else if (fabs(x) < 0) {
        return __DBL_MAX__;
    }
    else {
        return a * exp(x);
    }
}

double sReLu(double tl, double tr, double al, double ar, double x) {
    if (x < tl || fabs(x - tl) < __DBL_EPSILON__) {
        return tl + al * (x - tl);
    }
    else if (x > tl && x < tr) {
        return 0;
    }
    else {
        return tr + ar * (x - tr);
    }
}

double der_sReLu(double tl, double tr, double al, double ar, double x) {
    if (fabs(al) < __DBL_EPSILON__ && fabs(tl) < __DBL_EPSILON__ && fabs(ar) < __DBL_EPSILON__ && fabs(tr) < __DBL_EPSILON__) {
        return 0;
    }
    else if (fabs(x - tl) < __DBL_EPSILON__ || fabs(x - tr) < __DBL_EPSILON__) {
        return __DBL_MAX__;
    }
    else if (x < tl) {
        return al;
    }
    else if (x > tr) {
        return ar;
    }
    else {
        return 0;
    }
}

double isReLu(double x, double a) {
    if (x < 0 && fabs(x + sqrt(-1 / a)) < __DBL_EPSILON__) {
        return __DBL_MAX__;
    }
    else if (x < 0) {
        return x / sqrt(1 + a * x * x);
    }
    else {
        return 0;
    }
}

double der_isReLu(double x, double a) {
    if (fabs(a) < __DBL_EPSILON__ || x > 0) {
        return 1;
    }
    else if (fabs(x) < __DBL_EPSILON__) {
        return __DBL_MAX__;
    }
    else {
        if (a < 0 && fabs(x + sqrt(-1 / a)) < __DBL_EPSILON__) {
            return __DBL_MAX__;
        }
        else {
            return (fabs(1 + a * x * x) - a * x * x) / (fabs(1 + a * x * x) * sqrt(1 + a * x * x));
        }
    }
}

double softExponential(double a, double x) {
    if (a < 0) {
        if (1 - a * (x + a) < 0 || fabs(1 - a * (x + a)) < __DBL_EPSILON__) {
            return __DBL_MAX__;
        }
        else {
            return -log(1 - a * (x + a)) / a;
        }
    }
    else if (fabs(a) < __DBL_EPSILON__) {
        return x;
    }
    else {
        return (exp(a * x) - 1) / a + a;
    }
}

double der_softExponential(double a, double x) {
    if (a < 0) {
        double temp;
        temp = 1 - a * a - a * x;
        if (1 - a * (x + a) < 0 || fabs(1 - a * (x + a)) < __DBL_EPSILON__) {
            return __DBL_MAX__;
        }
        else {
            return 1 / temp;
        }
    }
    else if (fabs(a) < __DBL_EPSILON__) {
        return 1;
    }
    else {
        return pow(exp(x), a);
    }
}

double sinc(double x) {
    if (fabs(x) < __DBL_EPSILON__) {
        return 1;
    }
    else {
        return sin(x) / x;
    }
}

double der_sinc(double x) {
    if (fabs(x) < __DBL_EPSILON__) {
        return 0;
    }
    else {
        return (x * cos(x) - sin(x)) / (x * x);
    }
}

void task23() {
    double a, x, x0, tl, tr, al, ar;
    printf("a = ");
    scanf("%lf", &a);
    printf("x = ");
    scanf("%lf", &x);
    printf("x0 = ");
    scanf("%lf", &x0);
    printf("a) onestep(%g) = %g\n", x, onestep(x));
    printf("   onestep_der(%g) = %g\n", x0, der_onestep(x0));
    printf("b) ReLu(%g) = %g\n", x, ReLu(x));
    printf("   ReLu_der(%g) = %g\n", x0, der_ReLu(x0));
    printf("c) leakyReLu(%g, %g) = %g\n", x, a, leakyReLu(x, a));
    printf("   leakyReLu_der(%g, %g) = %g\n", x0, a, der_leakyReLu(x0, a));
    printf("d) eReLu(%g, %g) = %g\n", a, x, eReLu(a, x));
    printf("   eReLu_der(%g, %g) = %g\n", a, x0, der_eReLu(a, x0));
    printf("tl, tr, al, ar = ");
    scanf("%lf %lf %lf %lf", &tl, &tr, &al, &ar);
    printf("e) sReLu(%g, %g, %g, %g, %g) = %g\n", tl, tr, al, ar, x, sReLu(tl, tr, al, ar, x));
    printf("   sReLu_der(%g, %g, %g, %g, %g) = %g\n", tl, tr, al, ar, x0, der_sReLu(tl, tr, al, ar, x));
    printf("f) isReLu(%g, %g) = %g\n", x, a, isReLu(x, a));
    printf("   isReLu_der(%g, %g) = %g\n", x0, a, der_isReLu(x0, a));
    printf("g) softExponential(%g, %g) = %g\n", a, x, softExponential(a, x));
    printf("   softExponential_der(%g, %g) = %g\n", a, x0, der_softExponential(a, x0));
    printf("h) sinc(%g) = %g\n", x, sinc(x));
    printf("   sinc_der(%g) = %g\n", x0, der_sinc(x0));
}

int main() {
    task23();
}
