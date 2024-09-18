#include <stdio.h>
#include <math.h>
#include <inttypes.h>


void task1() {
    unsigned n, temp, sum = 0;
    int digits[] = {};
    printf("n = ");
    scanf("%d", &n);
    int i = 0;
    while (n > 0) {
        temp = n % 10;
        sum += temp;
        digits[i] = temp;
        i++;
        printf("10^(%d): %d\n", i, temp);
        n /= 10;
    }
    printf("The sum of digits = %d\n", sum);
    printf("Reversed: ");
    for (i = 0; i < 3; i++)  {
        printf("%d", digits[i]);
    }
    printf("\n");
}

void task2() {
    unsigned a, b, c, n;
    printf("n = ");
    scanf("%d", &n);
    if (n >= 100 && n <= 999) {
        c = n % 10;
        b = (n / 10) % 10;
        a = n / 100;
        if (a != b && b != c && a != c) {
            printf("%i, %i, %i\n", a, b, c);
            printf("%i, %i, %i\n", a, c, b);
            printf("%i, %i, %i\n", c, a, b);
            printf("%i, %i, %i\n", c, b, a);
            printf("%i, %i, %i\n", b, c, a);
            printf("%i, %i, %i\n", b, a, c);
        }
        else {
            printf("Impossible to print out permutations: at least 2 same digits.\n");
        }
    }
    else {
        printf("Invalid data: not a three-digit number.\n");
    }
}

void task3() {
    long long a, b, c;
    printf("a, b, c = ");
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", (a * b) * c);
}

void task4() {
    uint8_t a, b;
    uint16_t z;
    printf("a = ");
    scanf("%hhu", &a);
    printf("b = ");
    scanf("%hhu", &b);
    z = (uint16_t) a * b;
    printf("%"PRIu8" * %"PRIu8" = %"PRIu16"\n", a, b, z);
}

void task5() {
    double a, b, max;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    max = (a > b) ? a : b;
    printf("max(%g, %g) = %g\n", a, b, max);
}

void task6() {
    double a, b, c, max, min;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);
    max = (fabs(a) > fabs(b)) ? a : b;
    max = (fabs(max) > fabs(c)) ? max : c;
    printf("max_abs(%g, %g, %g) = %g\n", a, b, c, max);
    min = (fabs(a) > fabs(b)) ? b : a;
    min = (fabs(min) > fabs(c)) ? c : min;
    printf("min_abs(%g, %g, %g) = %g\n", a, b, c, min);
}

void task7a() {
    double a, b, c, D, x1, x2;
    printf("a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (fabs(a) < __DBL_EPSILON__) {
        if (fabs(b) < __DBL_EPSILON__ && fabs(c) >= __DBL_EPSILON__) {
            printf("The equation has no roots.\n");
        }
        else if (fabs(b) < __DBL_EPSILON__ && fabs(c) < __DBL_EPSILON__) {
            printf("The equation has infinitely many real roots.\n");
        }
        else {
            x1 = -c/b;
            printf("The equation has 1 root: %g\n", x1);
        }
    }
    else {
        D = b * b - 4 * a * c;
        if (fabs(D) < __DBL_EPSILON__) {
            x1 = -b / (2 * a);
            printf("The equation has 1 root: %g\n", x1);
        }
        else if (D < 0) {
            printf("The equation has no real roots.\n");
        }
        else {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("The equation has two real roots:\nx1 = %g\nx2 = %g\n", x1, x2);
        }
    }
}

void task7b() {
    double a, b, c, D, x1, x2, x3, x4, temp1, temp2;
    printf("a, b, c = ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (fabs(a) < __DBL_EPSILON__) {
        if (fabs(b) < __DBL_EPSILON__ && fabs(c) < __DBL_EPSILON__) {
            printf("The equation has infinitely many real roots.\n");
        }
        else if (fabs(b) < __DBL_EPSILON__ && fabs(c) >= __DBL_EPSILON__) {
            printf("The equation has no roots.\n");
        }
        else {
            temp1 = -c/b;
            if (temp1 < 0) {
                printf("The equation has no real roots.\n");
            }
            else {
                x1 = sqrt(temp1);
                x2 = -sqrt(temp1);
                printf("The equation has two real roots:\nx1 = %g\nx2 = %g\n", x1, x2);
            }
        }
    }
    else {
        D = b * b - 4 * a * c;
        if (fabs(D) < __DBL_EPSILON__) {
            temp1 = -b / (2 * a);
            if (temp1 < 0) {
                printf("The equation has no real roots.\n");    
            }
            else {
                x1 = sqrt(temp1);
                x2 = -sqrt(temp1);
                printf("The equation has two real roots: \nx1 = %g\nx2 = %g\n", x1, x2);
            }
        }
        else if (D < 0) {
            printf("The equation has no real roots.\n");
        }
        else {
            temp1 = (-b + sqrt(D)) / (2 * a);
            temp2 = (-b - sqrt(D)) / (2 * a);
            if (temp1 * temp2 < 0) {
                x1 = sqrt(temp1);
                x2 = -x1;
                printf("The equation has two real roots: \nx1 = %g\nx2 = %g\n", x1, x2);
            }
            else if (temp1 < 0 && temp2 < 0) {
                printf("The equation has no real roots.\n");
            }
            else {
                x1 = sqrt(temp1);
                x2 = x1;
                x3 = sqrt(temp2);
                x4 = -x3;
                printf("The equation has four real roots:\nx1 = %g\nx2 = %g\nx3 = %g\nx4 = %g\n", x1, x2, x3, x4);
            }
        }
    }
}

int main() {
    task7a();
    task7b();
}