#include <stdio.h>
#include <math.h>

# define SIZE3 10
# define SIZE4 5
# define SIZE5 50
# define SIZE6 20

void task1() {
    unsigned int counter = 0;
    long double n;
    printf("n = ");
    scanf("%Lf", &n);
    int array[5] = {1, 2, -10, 100, 120};
    for (int i = 0; i < 5; i++) {
        if (array[i] < n) {
            counter += 1;
        }
    }
    printf("The number of elements in array which are less than <%Lg> = %u.\n", n, counter);
}

void task2() {
    unsigned int array[4] = {5, 112, 4, 3};
    for (int i = 0; i < 4; i++) {
        printf("%u ", array[3 - i]);
    }
}

double sum_greater_e(double arr[SIZE3]) {
    double sum = 0;
    const double e = exp(1);
    for (int i = 0; i < SIZE3; i++) {
        if (arr[i] > e) {
            sum += arr[i];
        }
    }
    return sum;
}

void task3() {
    double array[SIZE3];
    for (unsigned int i = 0; i < SIZE3; i++) {
        printf("array[%u] = ", i + 1);
        scanf("%lf", &array[i]);
    }
    printf("Sum of all numbers in the array which are greater than <e> = %g.\n", sum_greater_e(array));
}

void input_array(int array[SIZE4]) {
    for (unsigned int i = 0; i < SIZE4; i++) {
        printf("array[%u] = ", i + 1);
        scanf("%i", &array[i]);
    }
}

int max_in_array(int array[SIZE4]) {
    int max = array[0];
    for (unsigned int i = 1; i < SIZE4; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
} 

void task4() {
    int array[SIZE4];
    input_array(array);
    printf("Maximum element of the array = %i.\n", max_in_array(array));
}

void task5() {
    unsigned int odd = 0, even = 0;
    unsigned int array[SIZE5];
    for (unsigned int i = 0; i < SIZE5; i++) {
        printf("array[%u] = ", i + 1);
        scanf("%u", &array[i]);
        if (array[i] == 0) {
            break;
        }
        else {
            if (array[i] % 2 == 0) {
                even += 1;
            }
            else {
                odd += 1;
            }
        }
    }
    printf("The number of even elements in the array = %u.\n", even);
    printf("The number of odd elements in the array = %u.\n", odd);
}

void input_vect(double v[], size_t n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("v[%u] = ", i);
        scanf("%lf", &v[i]);
    }
}

void output_vect(double v[], size_t n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("%g ", v[i]);
    }
    printf("\n");
}

void sum_vect(double v1[], double v2[], double v3[], size_t n) {
    for (unsigned int i = 0; i < n; i++) {
        v3[i] = v1[i] + v2[i]; 
    }    
}

double dot_product(double v1[], double v2[], size_t n) {
    double res = 0;
    for (unsigned int i = 0; i < n; i++) {
        res += v1[i] * v2[i];
    }
    return res;
}

void task6() {
    size_t n;
    printf("n = ");
    scanf("%lu", &n);
    double v1[SIZE6], v2[SIZE6], v3[SIZE6];
    printf("Enter the coordinates of the first vector:\n");
    input_vect(v1, n);
    printf("Enter the coordinates of the second vector:\n");
    input_vect(v2, n);
    sum_vect(v1, v2, v3, n);
    printf("v1 : ");
    output_vect(v1, n);
    printf("v2 : ");
    output_vect(v2, n);
    printf("v1 + v2 : ");
    output_vect(v3, n);
    printf("(v1, v2) = %g\n", dot_product(v1, v2, n));
}

int main() {
    task6();
}
