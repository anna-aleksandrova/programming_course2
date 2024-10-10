#include <stdio.h>
#include <assert.h>

#define SIZEM1 3
#define SIZEN1 3
#define SIZEM2 99
#define SIZEN2 99

void input_matrix_ui(unsigned int matrix[SIZEM1][SIZEN1], size_t m, size_t n) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("matrix[%u][%u] = ", i + 1, j + 1);
            scanf("%u", &matrix[i][j]);
        }
    }
}

void output_matrix_ui(unsigned int matrix[SIZEM1][SIZEN1], size_t m, size_t n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task1() {
    unsigned int matrix[SIZEM1][SIZEN1] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    unsigned int m, n;
    printf("m = ");
    scanf("%u", &m);
    printf("n = ");
    scanf("%u", &n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == m) {
                matrix[i][j] = n;
            }
        }
    }
    output_matrix_ui(matrix, 3, 3);
}

void task2() {
    unsigned int i, j;
    double a;
    double matrix[SIZEM1][SIZEN1] = {
        {1.0, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("i = ");
    scanf("%u", &i);
    printf("j = ");
    scanf("%u", &j);
    assert(i >= 0 && i < SIZEM1);
    assert(j >= 0 && j < SIZEN1);
    printf("a = ");
    scanf("%lf", &a);
    matrix[i][j] = a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%g\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// task3
void input_matrixd(double matrix[SIZEM2][SIZEN2], size_t m, size_t n) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("matrix[%u][%u] = ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void output_matrixd(double matrix[SIZEM2][SIZEN2], size_t m, size_t n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%g ", matrix[i][j]);
        }
        printf("\n");
    }
}

// task4
void input_matrixd2(double matrix[SIZEM2][SIZEN2], size_t m, size_t n) {
    for (unsigned int i = 0; i < m; i++) {
        printf("matrix[%u] : ", i);
        for (unsigned int j = 0; j < n; j++) {
            scanf("%lf ", &matrix[i][j]);
        }
    }
}

void transpose(double matrix[SIZEM2][SIZEN2], double res[SIZEM2][SIZEN2], size_t n) {
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            res[j][i] = matrix[i][j];
        }
    }
}

void task5() {
    unsigned int m, n;
    printf("m = ");
    scanf("%u", &m);
    printf("n = ");
    scanf("%u", &n);
    if (m != n) {
        printf("Not a square matrix. Impossible to take a transpose.\n");
    }
    else {
        double matrix[SIZEM2][SIZEN2];
        double res[SIZEM2][SIZEN2];
        input_matrixd(matrix, m, n);
        transpose(matrix, res, m);
        output_matrixd(res, m, n);
    }
}

void task6() {
    unsigned int m, n;
    int k;
    double sum = 0;
    printf("m = ");
    scanf("%u", &m);
    printf("n = ");
    scanf("%u", &n);
    printf("k = ");
    scanf("%i", &k);
    double matrix[SIZEM2][SIZEN2];
    input_matrixd(matrix, m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - j == k) {
                sum += matrix[i][j];
            }
        }
    }
    printf("The sum of the elements a[i][j] of the matrix such that i - j = <%i> : %g\n", k, sum);
}

int main() {
    task6();
}
