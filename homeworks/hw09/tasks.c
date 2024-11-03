#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double** create_matrix(unsigned int n, unsigned int m) {
    double** matrix = (double**) calloc(n, sizeof(double*));
    for (int j = 0; j < n; j++) {
        matrix[j] = (double*) calloc(m, sizeof(double));
    }
    return matrix;
}

void delete_matrix(double** matrix, unsigned int n) {
    if (matrix != 0) {
        free(matrix);   
    }
}

void input_matrix(double** matrix, unsigned int n, unsigned int m) {
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        printf("row[%i] : ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void output_matrix(double** matrix, unsigned int n, unsigned int m) {
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lg ", matrix[i][j]);
        }
        printf("\n");
    }
}

void input_row(double* row, unsigned int m) {
    assert(row != 0);
    printf("Enter the row: ");
    for (int j = 0; j < m; j++) {
        scanf("%lf", row + j);
    }
}

unsigned int end_rows(double** matrix, unsigned int n, unsigned int m, unsigned int k) {
    assert(matrix != 0);
    for (int i = 0; i < k; i++) {
        *(matrix + n + i) = (double*) calloc(m, sizeof(double));
    }
    for (int i = n; i < n + k; i++) {
        assert(matrix[i] != 0);
        input_row(matrix[i], m);
    }
    n += k;
    return n;
}

void input_column(double** matrix, unsigned int n, unsigned int m, unsigned int k) {
    assert(matrix != 0);
    printf("Enter the column: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &matrix[i][m + k]);
    }
}

unsigned int end_columns(double** matrix, unsigned int n, unsigned int m, unsigned int k) {
    assert(matrix != 0);
    for (int i = 0; i < n; i++) {
        double* ptr = realloc(matrix[i], (m + n) * sizeof(double));
        matrix[i] = ptr;
        assert(matrix[i] != 0);
    }
    for (int i = 0; i < k; i++) {
        input_column(matrix, n, m, i);
    }
    m += k;
    return m;
}

int main() {
    unsigned int n, m, rows, columns;
    printf("n = ");
    scanf("%u", &n);
    printf("m = ");
    scanf("%u", &m);
    double** matrix = create_matrix(n, m);
    input_matrix(matrix, n, m);
    printf("The number of columns to add to the end of the matrix: ");
    scanf("%u", &columns);
    m = end_columns(matrix, n, m, columns);
    printf("The number of rows to add to the end of the matrix: ");
    scanf("%u", &rows);
    n = end_rows(matrix, n, m, rows);
    printf("Updated matrix: \n");
    output_matrix(matrix, n, m);
    delete_matrix(matrix, n);
}
