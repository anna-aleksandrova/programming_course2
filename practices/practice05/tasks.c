#include <stdio.h>
#include <math.h>

void task1() {
    unsigned int n = 1;
    double a, sum = 0;
    printf("a = ");
    scanf("%lf", &a);
    do {
        sum += (double) 1 / n;
        n ++;
    }
    while (sum <= a);
    printf("Index: %d, res: %lf\n", n - 1, sum);
}

long long int Fibonacci(unsigned int n) {
        unsigned long long F0, F1, F;
        size_t i;
        F0 = 0;
        F1 = 1;
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            for (i = 2; i <= n; i++) {
                F = F0 + F1;
                F0 = F1;
                F1 = F;
            }
            return F;
        }
    }

void task2a() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    printf("%llu\n", Fibonacci(n));
}

void task2bcd() {
    unsigned int n = 0;
    double a;
    long long unsigned sum = 0;
    printf("a = ");
    scanf("%lf", &a);
    if (a < 0) {
        printf("b) There is no Fibonacci number which are less than or equal to %g.\n", a);
        printf("c) n = 0 : F(n) = 0.\n");
        printf("d) The sum of all Fibonacci numbers which are less than or equal to <%g> = %llu\n", a, sum);
    }
    else {
        unsigned long long int current = Fibonacci(n);
        while (current <= a) {
            sum = sum + current;
            n++;
            current = Fibonacci(n);
        }
        printf("b) n = %u : F(n) = %llu\n", n - 1, Fibonacci(n - 1));
        printf("c) n = %u : F(n) = %llu\n", n, current);
        unsigned long long int x = sum;
        printf("d) The sum of all Fibonacci numbers which are less than or equal to <%g> = %llu\n", a, sum);
    }
}

int sequence(long long ak) {
    unsigned int n, i;
    i = 0;
    printf("%llu, ", ak);
    while (ak != 1) {
        if (ak % 2 == 0) {
            ak = ak / 2;
        }
        else {
            ak = 3 * ak + 1;
        }
        printf("%llu, ", ak);
        i++;
    }
    return i;
}

void task3() {
    unsigned int temp_step, max_step = 0, max_res = 0;
    for (int i = 1; i < 1001; i++) {
        temp_step = sequence(i);
        printf("\n");
        if (temp_step > max_step) {
            max_step = temp_step;
            max_res = i;
        }
    }
    printf("n which requires the greatest amount of steps: %u\n", max_res);
}

void task4a() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    long long product = 1;
    unsigned long long int fact = 1;
    for (int i = 1; i < n + 1; i++) {
        fact *= i;
        product *= 1 + 1.0 / fact;
    }
    printf("a) P(%u) = %llu\n", n, product);
}

void task4b() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n == 1) {
        printf("a) P(1) = 1.5\n");  
    }
    else {
        printf("b) P(%u) = 0\n", n);
    }
}

void task5() {
    long long int x1 = -99, x2 = -99, x3 = -99, x4 = 0;
    while (x4 <= 0) {
        x4 = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x4;
    }
    printf("The smallest x4 greater than 0: %llu\n", x4);
}

void task6a() {
    unsigned int n;
    long double b, res;
    printf("b = ");
    scanf("%Lf", &b);
    printf("n = ");
    scanf("%u", &n);
    res = b;
    for (int i = 0; i < n; i++) {
        res = b + (1.0 / res);
    }
    printf("a) b(n) = %Lg\n", res);
}

void task6b() {
    unsigned int n;
    long double res;
    printf("n = ");
    scanf("%u", &n);
    res = 4 * n + 2;
    for (int i = 1; i < n + 1; i++) {
        res = 4 * (n - i) + 2 + 1 / res;
    }
    printf("b) lambda(n) = %Lg\n", res);
}

void task6c() {
    unsigned int n;
    long double res;
    printf("n = ");
    scanf("%u", &n);
    res = 2;
    for (int i = 0; i < n - 1; i++) {
        res = 1 + 1 / res;
        res = 2 + 1 / res;
    }
    res = 1 + 1 / res;
    printf("c) x(2n) = %Lg\n", res);
}

void task7() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    if (n == 1) {
        printf("S_n = 2\n");
    }
    else if (n == 2) {
        printf("S_n = 6\n");
    }
    else {
        long double a1 = 0, a2 = 1, a_i;
        long double b1 = 1, b2 = 0, b_i;
        long double sum = 6;
        long double nom = 4;
        for (int i = 3; i < n + 1; i++) {
            nom *= 2;
            b_i = b2 + a2;
            a_i = a2 / i + a1 * b_i;
            sum += nom / (a_i + b_i);
            a1 = a2;
            a2 = a_i;
            b2 = b_i;
        }
        printf("S_n = %Lg\n", sum);
    }
}

void task8a() {
    unsigned int i = 1;
    double eps;
    long double x, res = 0;
    printf("eps = ");
    scanf("%lf", &eps);
    printf("x = ");
    scanf("%Lf", &x);
    long double current = x;
    while (fabs(current) >= eps / 10) {
        res += current;
        i += 1;
        current *= x / i;
    }
    printf("exp(%Lg) = %Lf\n", x, res + 1);
    printf("by <math.h>: exp(%Lg) = %Lf\n", x, exp(x));
}

void task8b() {
    unsigned int i = 0;
    double eps;
    long double x, res = 0;
    printf("eps = ");
    scanf("%lf", &eps);
    printf("x = ");
    scanf("%Lf", &x);
    long double current = x;
    while (fabs(current) >= eps / 10) {
        res += current;
        current *= - x * x * (2 * i + 1) / (2 * i + 3) / (i + 1);
        i += 1;
    }
    printf("PHI(%Lg) = %Lf\n", x, res);
}

int main() {
    task8b();
}
