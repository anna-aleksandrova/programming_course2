#include <stdio.h>
#include <stdlib.h>

#define N 99
#define M 99

void input_matrix(double* matrix, unsigned int n, unsigned int m) {
    for (int i = 0; i < n; i++) {
        printf("matrix[%i] : ", i + 1);
        for(int j = 0; j < m; j++) {
            scanf("%lf", matrix + i*m + j);
        }
        printf("\n");
    }
}

void output_matrix(double* matrix, unsigned int n, unsigned int m) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%g ", *(matrix + i*m + j));
        }
        printf("\n");
    }
}

unsigned int max_in_row(double* matrix, unsigned int m, unsigned int i) {
    double *temp = matrix + i * m;
    unsigned int max_index = 0;
    double max = *(temp);
    for (unsigned int j = 1; j < m; j++) {
        if (*(temp + j) > max) {
            max_index = j;
        }
    }
    return max_index;
}

void swap_columns(double *matrix, unsigned int n, unsigned int m, unsigned int c1, unsigned int c2) {
    for (int i = 0; i < n; i++) {
        double temp = *(matrix + i*m + c1);
        *(matrix + i*m + c1) = *(matrix + i*m + c2);
        *(matrix + i*m + c2) = temp;
    }
}

int main() {
    double *matrix = (double*) malloc(N * M * sizeof(double));
    unsigned int n, m;
    printf("n = ");
    scanf("%u", &n);
    printf("m = ");
    scanf("%u", &m);
    input_matrix(matrix, n, m);
    for (int i = 0; i < n; i++) {
        unsigned int c2 = max_in_row(matrix, m, i);
        swap_columns(matrix, n, m, i, c2);
    }
    output_matrix(matrix, n, m);
    free(matrix);
}
