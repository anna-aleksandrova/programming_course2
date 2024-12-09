#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "headers/tensors.h"
#include "headers/cartesian.h"

void array_uc(unsigned char* array_uc, int dimension) {
    if (array_uc != NULL) {for (int i = 0; i < dimension; i++) {scanf("%hhi", &array_uc[i]);}}
}

void array_sc(signed char* array_sc, int dimension) {
    if (array_sc != NULL) {for (int i = 0; i < dimension; i++) {scanf("%hhi", &array_sc[i]);}}
}

void array_s(short* array_s, int dimension) {
    if (array_s != NULL) {for (int i = 0; i < dimension; i++) {scanf("%hi", &array_s[i]);}}
}

void array_i(int* array_i, int dimension) {
    if (array_i != NULL) {for (int i = 0; i < dimension; i++) {scanf("%i", &array_i[i]);}}
}

void array_f(float* array_f, int dimension) {
    if (array_f != NULL) {for (int i = 0; i < dimension; i++) {scanf("%f", &array_f[i]);}}
}

void array_d(double* array_d, int dimension) {
    if (array_d != NULL) {for (int i = 0; i < dimension; i++) {scanf("%lf", &array_d[i]);}}
}

void show_uc(unsigned char* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%hhi ", array[i]);}}

void show_sc(signed char* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%hhi ", array[i]);}}

void show_s(short* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%hi ", array[i]);}}

void show_i(int* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%i ", array[i]);}}

void show_f(float* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%f ", array[i]);}}

void show_d(double* array, int dimension) {for (int i = 0; i < dimension; i++) {printf("%f ", array[i]);}}

void ind(int* array, int dimension) {
    printf("tensor");
    for (int i = 0; i < dimension; i++) {printf("[%i]", array[i]);}
    printf(": ");
}

Tensor* input() {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    int t_dtype;
    printf("Enter the third byte of the magic number (represents the data type): ");
    scanf("%X", &t_dtype);
    if (!(t_dtype == 8 || t_dtype == 9 || (t_dtype >= 11 && t_dtype <= 14))) {return NULL;} // to delete the tensor
    else {tensor -> data_type = t_dtype;}
    printf("Enter the forth byte of the magic number (represents the number of dimensions): ");
    scanf("%i", &tensor->power);
    printf("Enter the shape of the tensor: ");
    tensor -> shape = (__uint32_t*) malloc(sizeof(__uint32_t) * tensor->power);
    int product = 1; 
    for (int i = 0; i < tensor -> power; i++) {
        scanf("%u", &tensor->shape[i]);
        if (i != tensor -> power - 1) {product *= tensor->shape[i];}
    }
    tensor -> product = product;
    int ldim = tensor->shape[tensor -> power - 1];
    int** indexing = cartesian_product(tensor -> shape, tensor -> power - 1);
    switch(tensor->data_type) {
        case 8:
            tensor -> data_uc = (unsigned char**) malloc(sizeof(sizeof(unsigned char) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_uc[i] = (unsigned char*) malloc(sizeof(unsigned char) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_uc(tensor -> data_uc[i], ldim);
            }
            break;
        case 9:
            tensor -> data_sc = (signed char**) malloc(sizeof(sizeof(signed char) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_sc[i] = (signed char*) malloc(sizeof(signed char) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_sc(tensor -> data_sc[i], ldim);
            }
            break;
        case 11:
            tensor -> data_s = (short**) malloc(sizeof(sizeof(short) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_s[i] = (short*) malloc(sizeof(short) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_s(tensor -> data_s[i], ldim);
            }
            break;
        case 12:
            tensor -> data_i = (int**) malloc(sizeof(sizeof(int) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_i[i] = (int*) malloc(sizeof(int) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_i(tensor -> data_i[i], ldim);
            }
            break;
        case 13:
            tensor -> data_f = (float**) malloc(sizeof(sizeof(float) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_f[i] = (float*) malloc(sizeof(float) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_f(tensor -> data_f[i], ldim);
            }
            break;
        case 14:
            tensor -> data_d = (double**) malloc(sizeof(sizeof(double) * ldim) * product);
            for (int i = 0; i < product; i++) {
                tensor -> data_d[i] = (double*) malloc(sizeof(double) * ldim);
                ind(indexing[i], tensor -> power - 1);
                array_d(tensor -> data_d[i], ldim);
            }
            break;
    }
    delete_matrix_i(indexing, tensor -> product, tensor -> shape[tensor -> power - 1]);
    return tensor;
}

Tensor* input_from_uc(int d_type, int pow, int* sh, unsigned char** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 8) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_uc = (unsigned char**) malloc(sizeof(unsigned char*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_uc[i] = (unsigned char*) malloc(sizeof(unsigned char) * ldim);
        tensor -> data_uc[i] = data[i];
    }
    return tensor;    
}

Tensor* input_from_sc(int d_type, int pow, int* sh, signed char** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 9) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_sc = (signed char**) malloc(sizeof(signed char*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_sc[i] = (signed char*) malloc(sizeof(signed char) * ldim);
        tensor -> data_sc[i] = data[i];
    }
    return tensor;    
}

Tensor* input_from_s(int d_type, int pow, int* sh, short** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 11) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_s = (short**) malloc(sizeof(short*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_s[i] = (short*) malloc(sizeof(short) * ldim);
        tensor -> data_s[i] = data[i];
    }
    return tensor;    
}

Tensor* input_from_i(int d_type, int pow, int* sh, int** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 12) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_i = (int**) malloc(sizeof(int*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_i[i] = (int*) malloc(sizeof(int) * ldim);
        tensor -> data_i[i] = data[i];
    }
    return tensor;    
}

Tensor* input_from_f(int d_type, int pow, int* sh, float** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 13) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_f = (float**) malloc(sizeof(float*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_f[i] = (float*) malloc(sizeof(float) * ldim);
        tensor -> data_f[i] = data[i];
    }
    return tensor;    
}

Tensor* input_from_d(int d_type, int pow, int* sh, double** data) {
    Tensor* tensor = (Tensor*) malloc(sizeof(Tensor));
    tensor -> first_byte = 0x00;
    tensor -> second_byte = 0x00;
    if (d_type != 14) {return NULL;}
    else {tensor -> data_type = d_type;}
    tensor -> power = pow;
    tensor -> shape = sh;
    int product = 1, ldim = sh[pow - 1];
    for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
    tensor -> product = product;
    tensor -> data_d = (double**) malloc(sizeof(double*) * product);
    for (int i = 0; i < product; i++) {
        tensor -> data_d[i] = (double*) malloc(sizeof(double) * ldim);
        tensor -> data_d[i] = data[i];
    }
    return tensor;    
}

void show_shape(uint32_t* shape, int power) {
    for (int i = 0; i < power; i++) {printf("%"PRIu32" ", shape[i]);}
}

void show_tensor(Tensor* tensor) {
    if (tensor != NULL) {
        printf("\n====================Tensor====================\n");
        printf("The number of dimensions: %i, shape: ", tensor -> power);
        show_shape(tensor-> shape, tensor->power);
        int product = 1;
        for (int i = 0; i < tensor -> power - 1; i++) {product *= tensor->shape[i];}
        int dimension = tensor -> shape[tensor -> power - 1];
        printf("\nData:\n");
        int** indexing = cartesian_product(tensor -> shape, tensor -> power - 1);
        switch(tensor->data_type) {
            case 8: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_uc(tensor->data_uc[i], dimension); printf("\n");} break;
            case 9: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_sc(tensor->data_sc[i], dimension); printf("\n");} break;
            case 11: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_s(tensor->data_s[i], dimension); printf("\n");} break;
            case 12: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_i(tensor->data_i[i], dimension); printf("\n");} break;
            case 13: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_f(tensor->data_f[i], dimension); printf("\n");} break;
            case 14: for(int i = 0; i < product; i++) {ind(indexing[i], tensor -> power - 1); show_d(tensor->data_d[i], dimension); printf("\n");} break;
        }
        delete_matrix_i(indexing, tensor -> product, tensor -> shape[tensor -> power - 1]);
    }
}

void del(Tensor* tensor, int shape_check) {
    switch(tensor -> data_type) {
        case 8: delete_matrix_uc(tensor -> data_uc, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
        case 9: delete_matrix_sc(tensor -> data_sc, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
        case 11: delete_matrix_s(tensor -> data_s, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
        case 12: delete_matrix_i(tensor -> data_i, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
        case 13: delete_matrix_f(tensor -> data_f, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
        case 14: delete_matrix_d(tensor -> data_d, tensor -> product, tensor -> shape[tensor -> power - 1]); break;
    }
    if (shape_check && tensor -> shape != NULL) {free(tensor -> shape);}
}

int write(char* filename, Tensor* tensor) {
    FILE* fout = fopen(filename, "w");
    if (fout == NULL) {return 1;}
    fprintf(fout, "0x00 0x00 ");
    int ldim = tensor -> shape[tensor -> power - 1];
    switch(tensor -> data_type) {
        case 8:
            if (tensor -> power < 16) {fprintf(fout, "0x08 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x08 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_uc(fout, tensor -> data_uc, tensor -> product, ldim);
            break;
        case 9:
            if (tensor -> power < 16) {fprintf(fout, "0x09 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x09 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_sc(fout, tensor -> data_sc, tensor -> product, ldim);
            break;
        case 11:
            if (tensor -> power < 16) {fprintf(fout, "0x0B 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x0B 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_s(fout, tensor -> data_s, tensor -> product, ldim);
            break;
        case 12:
            if (tensor -> power < 16) {fprintf(fout, "0x0C 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x0C 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_i(fout, tensor -> data_i, tensor -> product, ldim);
            break;
        case 13:
            if (tensor -> power < 16) {fprintf(fout, "0x0D 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x0D 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_f(fout, tensor -> data_f, tensor -> product, ldim);
            break;
        case 14:
            if (tensor -> power < 16) {fprintf(fout, "0x0E 0x0%X\n", tensor -> power);}
            else {fprintf(fout, "0x0E 0x%X\n", tensor -> power);}
            write_m_uint32(fout, &(tensor -> shape), 1, tensor -> power);
            write_m_d(fout, tensor -> data_d, tensor -> product, ldim);
            break;
    }
    fclose(fout);
}

int is_hex(char* n) {
    if (strlen(n) != 4) return 0;
    if (n[0] != '0' || n[1] != 'x') return 0;
    if (!((n[2] >= '0' && n[2] <= '9') || (n[2] >= 'A' && n[2] <= 'F'))) return 0;
    if (!((n[3] >= '0' && n[3] <= '9') || (n[3] >= 'A' && n[3] <= 'F'))) return 0;
    return 1;
}

int is_dtype(char* n) {
    if (!is_hex(n)) return 0;
    if (n[2] != '0' || (n[3] != '8' && n[3] != '9' && n[3] != 'B' && n[3] != 'C' && n[3] != 'D' && n[3] != 'E')) return 0;
    return 1;
}

void read_data(FILE* fin, int dtype, int product, int ldim) {
    switch (dtype) {
        case 8:
            unsigned char** data1 = read_matrix_uc(fin, product, ldim);
            delete_matrix_uc(data1, product, ldim);
            break;
        case 9:
            signed char** data2 = read_matrix_sc(fin, product, ldim);
            delete_matrix_sc(data2, product, ldim);
            break;
        case 11:
            short** data3 = read_matrix_s(fin, product, ldim);
            delete_matrix_s(data3, product, ldim);
            break;
        case 12:
            int** data4 = read_matrix_i(fin, product, ldim);
            delete_matrix_i(data4, product, ldim);
            break;
        case 13:
            float** data5 = read_matrix_f(fin, product, ldim);
            delete_matrix_f(data5, product, ldim);
            break;
        case 14:
            double** data6 = read_matrix_d(fin, product, ldim);
            delete_matrix_d(data6, product, ldim);
            break;
    }
}

int check_format(char* filename) {
    FILE* fin = fopen(filename, "r");
    if (fin == NULL) {return 1;}
    char buf1[5], buf2[2], buf3[3];
    int power, product, ldim, dtype;
    while (!feof(fin)) {
        for (int i = 0; i < 2; i++) {
            fgets(buf1, 5, fin); fgets(buf2, 2, fin);
            if (!is_hex(buf1)) return 1;
        }
        fgets(buf1, 5, fin); fgets(buf2, 2, fin);
        if (!is_dtype(buf1)) return 1;
        dtype = strtol(buf1, 0, 16);
        fgets(buf1, 5, fin); fgets(buf2, 2, fin);
        if (!is_hex(buf1)) return 1;
        power = strtol(buf1, 0, 16);
        product = 1;
        for (int i = 0; i < power - 1; i++) {
            fgets(buf3, 3, fin);
            product *= atoi(buf3);
            if (product == 0) return 1;
        }
        fgets(buf3, 3, fin);
        ldim = atoi(buf3);
        read_data(fin, dtype, product, ldim);
    }
    fclose(fin);
    return 0;
}

Tensor* read(char* filename, unsigned int n) {
    FILE* fin = fopen(filename, "r");
    if (fin == NULL) {return NULL;}
    if (check_format(filename)) {return NULL;}
    char buf1[5], buf2[2], buf3[3];
    int power, product, ldim, dtype, counter = 1;
    int* shape;
    while (!feof(fin)) {
        for (int i = 0; i < 2; i++) {fgets(buf1, 5, fin); fgets(buf2, 2, fin);}
        fgets(buf1, 5, fin); fgets(buf2, 2, fin);
        dtype = strtol(buf1, 0, 16);
        fgets(buf1, 5, fin); fgets(buf2, 2, fin);
        power = strtol(buf1, 0, 16);
        product = 1;
        if (counter == n) {shape = (int*) malloc(sizeof(int) * power);}
        for (int i = 0; i < power - 1; i++) {
            fgets(buf3, 3, fin);
            product *= atoi(buf3);
            if (counter == n) {shape[i] = atoi(buf3);}
        }
        fgets(buf3, 3, fin);
        ldim = atoi(buf3);
        if (counter == n) {
            shape[power - 1] = atoi(buf3);
            switch(dtype) {
                case 8:
                    unsigned char** data1 = read_matrix_uc(fin, product, ldim);
                    return input_from_uc(dtype, power, shape, data1);
                case 9:
                    signed char** data2 = read_matrix_sc(fin, product, ldim);
                    return input_from_sc(dtype, power, shape, data2);
                case 11:
                    short** data3 = read_matrix_s(fin, product, ldim);
                    return input_from_s(dtype, power, shape, data3);
                case 12:
                    int** data4 = read_matrix_i(fin, product, ldim);
                    return input_from_i(dtype, power, shape, data4);
                case 13:
                    float** data5 = read_matrix_f(fin, product, ldim);
                    return input_from_f(dtype, power, shape, data5);
                case 14:
                    double** data6 = read_matrix_d(fin, product, ldim);
                    return input_from_d(dtype, power, shape, data6);
            }
        }
        else {
            read_data(fin, dtype, product, ldim);
        }
        counter++;
    }
    fclose(fin);
    return NULL;
}

int equal_tensors(Tensor* tensor1, Tensor* tensor2) {
    if (tensor1 -> data_type != tensor2 -> data_type || tensor1 -> power != tensor2 -> power) return 0;  
    if (!equal_matrices_uint32(&(tensor1 -> shape), 1, tensor1 -> power, &(tensor2 -> shape), 1, tensor2 -> power)) return 0;
    int rows = tensor1 -> product, cols = tensor1 -> shape[tensor1 -> power - 1];
    switch (tensor1 -> data_type) {
        case 8: if (equal_matrices_uc(tensor1 -> data_uc, rows, cols, tensor2 -> data_uc, rows, cols)) {return 1;} else {return 0;}
        case 9: if (equal_matrices_sc(tensor1 -> data_sc, rows, cols, tensor2 -> data_sc, rows, cols)) {return 1;} else {return 0;}
        case 11: if (equal_matrices_s(tensor1 -> data_s, rows, cols, tensor2 -> data_s, rows, cols)) {return 1;} else {return 0;}
        case 12: if (equal_matrices_i(tensor1 -> data_i, rows, cols, tensor2 -> data_i, rows, cols)) {return 1;} else {return 0;}
        case 13: if (equal_matrices_f(tensor1 -> data_f, rows, cols, tensor2 -> data_f, rows, cols)) {return 1;} else {return 0;}
        case 14: if (equal_matrices_d(tensor1 -> data_d, rows, cols, tensor2 -> data_d, rows, cols)) {return 1;} else {return 0;}
    }
}

int check_coordinates(Tensor* tensor, int* coordinates, int size) {
    if (tensor -> power != size) return 0;
    for (int i = 0; i < tensor -> power; i++) {
        if (!(coordinates[i] >= 0 && coordinates[i] < tensor -> shape[i])) return 0;
    }
    return 1;
}

int change_value_uc(int* coordinates, int size, Tensor* tensor, unsigned char new_value) {
    if (tensor -> data_type != 8) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_uc[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}

int change_value_sc(int* coordinates, int size, Tensor* tensor, signed char new_value) {
    if (tensor -> data_type != 9) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_sc[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}

int change_value_s(int* coordinates, int size, Tensor* tensor, short new_value) {
    if (tensor -> data_type != 11) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_s[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}

int change_value_i(int* coordinates, int size, Tensor* tensor, int new_value) {
    if (tensor -> data_type != 12) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];   
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_i[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}

int change_value_f(int* coordinates, int size, Tensor* tensor, float new_value) {
    if (tensor -> data_type != 13) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];   
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_f[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}

int change_value_d(int* coordinates, int size, Tensor* tensor, double new_value) {
    if (tensor -> data_type != 14) return 1;
    if (tensor -> power != size) return 1;
    if (!check_coordinates(tensor, coordinates, size)) return 1;
    int* sh = (int*) malloc(sizeof(int) * (size - 1));
    int* coord = (int*) malloc(sizeof(int) * (size - 1));
    for (int i = 0; i < size - 1; i++) {sh[i] = tensor -> shape[i]; coord[i] = coordinates[i];}
    int** indexing = cartesian_product(sh, size - 1);
    int counter = 0, ldim = tensor -> shape[size - 1];   
    for (int i = 0; i < tensor -> product; i++) {
        if (equal_matrices_i(&indexing[i], 1, size - 1, &coord, 1, size - 1)) {
            tensor -> data_d[counter][coordinates[size - 1]] = new_value;
            delete_matrix_i(indexing, tensor -> product, (tensor -> shape[size - 1]) - 1);
            free(coord);
            free(sh);
            return 0;
        }
        counter++;
    }
}
