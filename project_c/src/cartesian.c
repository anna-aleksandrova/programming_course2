#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include "headers/cartesian.h"

int equal_matrices_uc(unsigned char** matrix1, int m1, int n1, unsigned char** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_sc(signed char** matrix1, int m1, int n1, signed char** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_s(short** matrix1, int m1, int n1, short** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_i(int** matrix1, int m1, int n1, int** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_uint32(__uint32_t** matrix1, int m1, int n1, __uint32_t** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_f(float** matrix1, int m1, int n1, float** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (fabs(matrix1[i][j] - matrix2[i][j]) > __DBL_EPSILON__) {return 0;}
        }
    }
    return 1;
}

int equal_matrices_d(double** matrix1, int m1, int n1, double** matrix2, int m2, int n2) {
    if (m1 != m2 || n1 != n2) {return 0;}
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (fabs(matrix1[i][j] - matrix2[i][j]) > __DBL_EPSILON__) {return 0;}
        }
    }
    return 1;
}

int** cartesian_product_1(int first, int* n, int power_n, int dim_n) {
    int product = first * power_n;
    int dimension = dim_n + 1;
    int counter = 0;
    int** res = (int**) malloc(sizeof(int*) * product);
    for (int i = 0; i < product; i++) {res[i] = (int*) malloc(sizeof(int) * dimension);}
    for (int i = 0; i < first; i++) {
        for (int j = 0; j < power_n; j++) {
            res[counter][0] = i;
            res[counter][1] = n[j];
            counter++;
        }
    }
    return res;
}

int** cartesian_product_2(int first, int** n, int power_n, int dim_n) {
    int product = first * power_n;
    int dimension = dim_n + 1;
    int counter = 0;
    int** res = (int**) malloc(sizeof(int*) * product);
    for (int i = 0; i < product; i++) {res[i] = (int*) malloc(sizeof(int) * dimension);}
    for (int i = 0; i < first; i++) {
        for (int j = 0; j < power_n; j++) {
            res[counter][0] = i;
            for (int k = 0; k < dim_n; k++) {
                res[counter][k+1] = n[j][k];
            }
            counter++;
            if (i == first - 1 && dim_n != 1) free(n[j]);
        }
    }
    return res;
}

int** cartesian_product(int* shape, int dimension) {
    int temp[shape[dimension - 1]];
    for (int i = 0; i < shape[dimension - 1]; i++) {temp[i] = i;}
    int** res = cartesian_product_1(shape[dimension - 2], temp, shape[dimension - 1], 1);
    int product = shape[dimension - 1];
    for (int i = 1; i < dimension - 1; i++) {
        product *= shape[dimension - 1 - i];
        res = cartesian_product_2(shape[dimension - 2 - i], res, product, i+1);
    }
    return res;
}

void show_matrix_uc(unsigned char** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%hhi ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void show_matrix_sc(signed char** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%hhi ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void show_matrix_s(short** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%hi ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void show_matrix_i(int** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%i ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void show_matrix_f(float** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%f ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void show_matrix_d(double** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {
                for (int j = 0; j < n; j++) {printf("%f ", matrix[i][j]);}
            }
            printf("\n");
        }
    }
}

void delete_matrix_uc(unsigned char** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void delete_matrix_sc(signed char** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void delete_matrix_s(short** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void delete_matrix_i(int** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void delete_matrix_f(float** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void delete_matrix_d(double** matrix, int m, int n) {
    if (matrix != NULL) {
        for (int i = 0; i < m; i++) {
            if (matrix[i] != NULL) {free(matrix[i]);}
        }
    }
}

void write_m_uc(FILE* fout, unsigned char** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%hhi ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_sc(FILE* fout, signed char** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%hhi ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_s(FILE* fout, short** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%hi ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_i(FILE* fout, int** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%i ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_f(FILE* fout, float** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%f ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_d(FILE* fout, double** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%f ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

void write_m_uint32(FILE* fout, __uint32_t** matrix, int m, int n) {
    if (fout != NULL) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(fout, "%"PRIu32" ", matrix[i][j]);
            }
            fprintf(fout, "\n");
        }
    }
}

unsigned char** read_matrix_uc(FILE* fin, int m, int n) {
    unsigned char** res = (unsigned char**) malloc(sizeof(unsigned char*) * m);
    for (int i = 0; i < m; i++) {res[i] = (unsigned char*) malloc(sizeof(unsigned char) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%hhi ", &res[i][j]);
        }
    }
    return res;
}

signed char** read_matrix_sc(FILE* fin, int m, int n) {
    signed char** res = (signed char**) malloc(sizeof(signed char*) * m);
    for (int i = 0; i < m; i++) {res[i] = (signed char*) malloc(sizeof(signed char) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%hhi ", &res[i][j]);
        }
    }
    return res;
}

short** read_matrix_s(FILE* fin, int m, int n) {
    short** res = (short**) malloc(sizeof(short*) * m);
    for (int i = 0; i < m; i++) {res[i] = (short*) malloc(sizeof(short) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%hi ", &res[i][j]);
        }
    }
    return res;
}

int** read_matrix_i(FILE* fin, int m, int n) {
    int** res = (int**) malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {res[i] = (int*) malloc(sizeof(int) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%i ", &res[i][j]);
        }
    }
    return res;
}

float** read_matrix_f(FILE* fin, int m, int n) {
    float** res = (float**) malloc(sizeof(float*) * m);
    for (int i = 0; i < m; i++) {res[i] = (float*) malloc(sizeof(float) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%f ", &res[i][j]);
        }
    }
    return res;
}

double** read_matrix_d(FILE* fin, int m, int n) {
    double** res = (double**) malloc(sizeof(double*) * m);
    for (int i = 0; i < m; i++) {res[i] = (double*) malloc(sizeof(double) * n);}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fin, "%lf ", &res[i][j]);
        }
    }
    return res;
}
