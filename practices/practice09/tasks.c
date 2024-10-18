#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define SIZE 100

void input_array(double* array, unsigned int n) {
    printf("array : ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", array + i);
    }
}

void output_array(double* array, unsigned int n) {
    for (int i = 0; i < n; i++) {
        printf("%g ", *(array + i));
    }
}

void task1() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    double* array = (double*) malloc(n * sizeof(double));
    input_array(array, n);
    double res = 0;
    for (int i = 0; i < n; i++) {
        double el = *(array + i);
        res += el * el;
    }
    free(array);
    printf("The sum of the squares of array's components : %g.\n", res);
}

int is_perfect_square(int n) {
    if (n < 0) {
        return 0;
    }
    int a = (int) round(pow(n, 1.0 / 2));
    if (a * a  == n) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_perfect_cube(int n) {
    if (n < 0) {
        n = fabs(n);
    }
    int a = (int) round(pow(n, 1.0 / 3));
    if (a * a * a == n) {
        return 1;
    }
    else {
        return 0;
    }
}

void task2() {
    unsigned int cardinality = 0;
    unsigned int perfect_squares = 0;
    unsigned int perfect_cubes = 0;
    int x, i = 0;
    while (1) {
        printf("array[%i] : ", i + 1);
        scanf("%i", &x);
        if (x == 0) {
            break;
        }
        cardinality++;
        i++;
        if (is_perfect_square(x)) perfect_squares++;
        if (is_perfect_cube(x)) perfect_cubes++;
    }
    printf("The number of elements in the array : %i.\n", i);
    printf("The number of perfect squares in the array : %i.\n", perfect_squares);
    printf("The number of perfect cubes in the array: %i.\n", perfect_cubes);
}

double* input(size_t n){
    double* array = (double*) malloc(n * sizeof(double));
    assert(array != 0);
    for (size_t i = 0; i < n; i++) {
        scanf("%lf", array + i);
    }
    return array;
}

void delete_vect(double *array) {
    free(array);
}

double* subtract(double *array1, double *array2, int n) {
    assert(array1 != 0);
    assert(array2 != 0);
    double* res = (double*) malloc(n * sizeof(double));
    for (size_t i = 0; i < n; i++) {
        res[i] = array1[i] - array2[i];
    }
    return res;
}

void task3() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    printf("v1 : ");
    double* vect1 = input(n);
    printf("v2 : ");
    double* vect2 = input(n);
    double* res = subtract(vect1, vect2, n);
    printf("v1 - v2 : ");
    output_array(res, n);
    delete_vect(vect1);
    delete_vect(vect2);
    delete_vect(res);
}

double** create_matrix(unsigned int n) {
    double** matrix = (double**) calloc(n, sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*) calloc(n, sizeof(double));
    }
    return matrix;
}

int input1_matrix(double** matrix, unsigned int n) {
    if (!matrix) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("matrix[%i] : ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    return 0;
}

void output1_matrix(double** matrix, unsigned int n) {
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%g ", matrix[i][j]);
        }
        printf("\n");
    }
}

void delete1_matrix(double** matrix, unsigned int n) {
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void product1_matrices(double** m1, double** m2, double** res, unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void task4_1() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    double** m1 = create_matrix(n);
    double** m2 = create_matrix(n);
    printf("matrix_1 :\n");
    input1_matrix(m1, n);
    printf("matrix_2 :\n");
    input1_matrix(m2, n);
    double** res = create_matrix(n);
    product1_matrices(m1, m2, res, n);
    printf("matrix_1 * matrix_2 :\n");
    output1_matrix(res, n);
    delete1_matrix(m1, n);
    delete1_matrix(m2, n);
    delete1_matrix(res, n);
}

double* input2_matrix(unsigned int n) {
    double* matrix = (double*) calloc(n * n, sizeof(double));
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        printf("matrix[%i] : ", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf", matrix + i * n + j);
        }
    }
    return matrix;
}

void output2_matrix(double* matrix, unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%g ", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

void delete2_matrix(double* matrix) {
    free(matrix);
}

double* product2_matrices(double* m1, double* m2, unsigned int n) {
    double* res = (double*) calloc(n * n, sizeof(double));
    assert(res != 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                *(res + i * n + j) += *(m1 + i * n + k) * *(m2 + k * n + j);
            }
        }
    }
    return res;
}

void task4_2() {
    unsigned int n;
    printf("n = ");
    scanf("%u", &n);
    double* m1 = input2_matrix(n);
    double* m2 = input2_matrix(n);
    double* res = product2_matrices(m1, m2, n);
    output2_matrix(res, n);
    delete2_matrix(m1);
    delete2_matrix(m2);
    delete2_matrix(res);
}

int main() {
    task4_2();
}
