#pragma once

/**
 * Checks the equality of matrices of different types.
 * 
 * @returns 1 if matrices are equal, 0 otherwise
 */
extern int equal_matrices_uc(unsigned char** matrix1, int m1, int n1, unsigned char** matrix2, int m2, int n2);
extern int equal_matrices_sc(signed char** matrix1, int m1, int n1, signed char** matrix2, int m2, int n2);
extern int equal_matrices_s(short** matrix1, int m1, int n1, short** matrix2, int m2, int n2);
extern int equal_matrices_i(int** matrix1, int m1, int n1, int** matrix2, int m2, int n2);
extern int equal_matrices_f(float** matrix1, int m1, int n1, float** matrix2, int m2, int n2);
extern int equal_matrices_d(double** matrix1, int m1, int n1, double** matrix2, int m2, int n2);
extern int equal_matrices_uint32(__uint32_t** matrix1, int m1, int n1, __uint32_t** matrix2, int m2, int n2);

extern int** cartesian_product_1(int first, int* n, int power_n, int dim_n);

extern int** cartesian_product_2(int first, int** n, int power_n, int dim_n);

extern int** cartesian_product(int* shape, int dimension);

extern void show_matrix_uc(unsigned char** matrix, int m, int n);
extern void show_matrix_sc(signed char** matrix, int m, int n);
extern void show_matrix_s(short** matrix, int m, int n);
extern void show_matrix_i(int** matrix, int m, int n);
extern void show_matrix_f(float** matrix, int m, int n);
extern void show_matrix_d(double** matrix, int m, int n);

extern void delete_matrix_uc(unsigned char** matrix, int m, int n);
extern void delete_matrix_sc(signed char** matrix, int m, int n);
extern void delete_matrix_s(short** matrix, int m, int n);
extern void delete_matrix_i(int** matrix, int m, int n);
extern void delete_matrix_f(float** matrix, int m, int n);
extern void delete_matrix_d(double** matrix, int m, int n);

/**
 * Writes the matrix of a certain type into the file <fout>.
 */
extern void write_m_uc(FILE* fout, unsigned char** matrix, int m, int n);
extern void write_m_sc(FILE* fout, signed char** matrix, int m, int n);
extern void write_m_s(FILE* fout, short** matrix, int m, int n);
extern void write_m_i(FILE* fout, int** matrix, int m, int n);
extern void write_m_f(FILE* fout, float** matrix, int m, int n);
extern void write_m_d(FILE* fout, double** matrix, int m, int n);
extern void write_m_uint32(FILE* fout, __uint32_t** matrix, int m, int n);

/**
 * Read the matrix of a certain type from the file <fin>.
 */
extern unsigned char** read_matrix_uc(FILE* fin, int m, int n);
extern signed char** read_matrix_sc(FILE* fin, int m, int n);
extern short** read_matrix_s(FILE* fin, int m, int n);
extern int** read_matrix_i(FILE* fin, int m, int n);
extern float** read_matrix_f(FILE* fin, int m, int n);
extern double** read_matrix_d(FILE* fin, int m, int n);
