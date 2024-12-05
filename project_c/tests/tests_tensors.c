#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/tensors.h"
#include "headers/cartesian.h"

#define LEN 100

int test_cartesian() {
    int counter = 0;
    int shape1[3] = {2, 2, 2};
    int** needed1 = (int**) malloc(sizeof(int*) * 8);
    for (int i = 0; i < 8; i++) {needed1[i] = (int*) malloc(sizeof(int) * 3);}
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 2; i++) {
            needed1[counter][2] = i;
            counter++;
        }
    }
    counter = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                needed1[counter][1] = i;
                counter++;
            }
        }
    }
    counter = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            needed1[counter][0] = i;
            counter++;
        }
    }
    counter = 0;
    int** res1 = cartesian_product(shape1, 3);
    int test1 = equal_matrices_i(needed1, 8, 3, res1, 8, 3);
    delete_matrix_i(needed1, 8, 3);
    delete_matrix_i(res1, 8, 3);

    int shape2[2] = {3, 3};
    int** needed2 = (int**) malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++) {needed2[i] = (int*) malloc(sizeof(int) * 2);}
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            needed2[counter][1] = i;
            counter++;
        }
    }
    counter = 0;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            needed2[counter][0] = k;
            counter++;
        }
    }
    int** res2 = cartesian_product(shape2, 2);
    int test2 = equal_matrices_i(needed2, 9, 2, res2, 9, 2);
    delete_matrix_i(needed2, 9, 2);
    delete_matrix_i(res2, 9, 2);
    return test1 && test2;
}

void test_input_show() {
    Tensor* tensor = input();
    show_tensor(tensor);
    del(tensor, 1);
}

void test_input_uc() {
    int d_type = 0x08, counter = 0;
    int shape[3] = {3, 3, 3};
    unsigned char** test = (unsigned char**) malloc(sizeof(unsigned char*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (unsigned char*) malloc(sizeof(unsigned char) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}
    Tensor* tensor = input_from_uc(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_input_sc() {
    int d_type = 0x09, counter = 0;
    int shape[3] = {3, 3, 3};
    signed char** test = (signed char**) malloc(sizeof(signed char*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (signed char*) malloc(sizeof(signed char) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}    
    Tensor* tensor = input_from_sc(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_input_s() {
    int d_type = 0x0B, counter = 0;
    int shape[3] = {3, 3, 3};
    short** test = (short**) malloc(sizeof(short*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (short*) malloc(sizeof(short) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}    
    Tensor* tensor = input_from_s(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_input_i() {
    int d_type = 0x0C, counter = 0;
    int shape[3] = {3, 3, 3};
    int** test = (int**) malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (int*) malloc(sizeof(int) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}    
    Tensor* tensor = input_from_i(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_input_f() {
    int d_type = 0x0D, counter = 0;
    int shape[3] = {3, 3, 3};
    float** test = (float**) malloc(sizeof(float*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (float*) malloc(sizeof(float) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}
    Tensor* tensor = input_from_f(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_input_d() {
    int d_type = 0x0E, counter = 0;
    int shape[3] = {3, 3, 3};
    double** test = (double**) malloc(sizeof(double*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (double*) malloc(sizeof(double) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}
    Tensor* tensor = input_from_d(d_type, 3, shape, test);
    show_tensor(tensor);
    del(tensor, 0);
}

void test_write() {
    char filename[LEN];
    printf("\nEnter the name of the file to write the tensor into: ");
    scanf("%s", filename);
    Tensor* tensor = input();
    write(filename, tensor);
    del(tensor, 1);
}

int test_is_hex() {
    char n1[] = "0x00";
    char n2[] = "0xAA";
    char n3[] = "0xFG";
    char n4[] = "asdf";
    char n5[] = "asdfg";
    return is_hex(n1) && is_hex(n2) && !is_hex(n3) && !is_hex(n4) && !is_hex(n5);
}

int test_is_data_type() {
    char n1[] = "0x08";
    char n2[] = "0x09";
    char n3[] = "0x0B";
    char n4[] = "0x0C";
    char n5[] = "0x0D";
    char n6[] = "0x0E";
    char n7[] = "asdlfkj";
    char n8[] = "asdf";
    char n9[] = "0000";
    char n10[] = "0x00";
    return is_dtype(n1) && is_dtype(n2) && is_dtype(n3) && is_dtype(n4)&& is_dtype(n5) && is_dtype(n6) && !is_dtype(n7) && !is_dtype(n8) && !is_dtype(n9) && !is_dtype(n10);
}

int test_check_format() {
    return !check_format("tests/test_write1.txt") && !check_format("tests/test_write2.txt") && !check_format("tests/test_write3.txt") && check_format("tests/wrong_format.txt");
}

int test_equal_tensors() {
    int d_type = 0x0E, counter = 0;
    int shape[3] = {3, 3, 3};
    double** test = (double**) malloc(sizeof(double*) * 9);
    for (int i = 0; i < 9; i++) {test[i] = (double*) malloc(sizeof(double) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][1] = i; counter++;}}
    counter = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test[counter][0] = k;counter++;}}
    for (int k = 0; k < 9; k++) {test[k][2] = k;}
    Tensor* tensor1 = input_from_d(d_type, 3, shape, test);
    Tensor* tensor2 = input_from_d(d_type, 3, shape, test);
    int res1 =  equal_tensors(tensor1, tensor2);

    int d_type1 = 0x0C, counter1 = 0;
    int shape1[3] = {3, 3, 3};
    int** test1 = (int**) malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++) {test1[i] = (int*) malloc(sizeof(int) * 2);}
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test1[counter1][1] = i; counter1++;}}
    counter1 = 0;
    for (int k = 0; k < 3; k++) {for (int i = 0; i < 3; i++) {test1[counter1][0] = k; counter1++;}}
    for (int k = 0; k < 9; k++) {test1[k][2] = k;}
    Tensor* tensor3 = input_from_i(d_type1, 3, shape1, test1);
    int res2 = equal_tensors(tensor1, tensor3);
    del(tensor1, 0);
    del(tensor3, 0);
    return res1 && !res2;
}

int test_read() {
    __uint32_t shape1[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4};
    int** data1 = (int**) malloc(sizeof(int*) * 1);
    for (int i = 0; i < 1; i++) {data1[i] = (int*) malloc(sizeof(int) * 4);}
    for (int i = 0; i < 4; i++) {data1[0][i] = i + 1;}
    Tensor* needed1 = input_from_i(0x0C, 16, shape1, data1);
    Tensor* t1 = read("tests/test_write2.txt", 3);
    int res1 = equal_tensors(needed1, t1);
    del(needed1, 0);
    del(t1, 1);

    __uint32_t shape2[3] = {2, 2, 3};
    double** data2 = (double**) malloc(sizeof(double*) * 4);
    for (int i = 0; i < 4; i++) {data2[i] = (double*) malloc(sizeof(double) * 3);}
    double counter = 1;
    for (int i = 0; i < 4; i++) {for (int j = 0; j < 3; j++) {data2[i][j] = counter; counter++;}}
    Tensor* needed2 = input_from_d(0x0E, 3, shape2, data2);
    Tensor* t2 = read("tests/test_write2.txt", 4);
    int res2 = equal_tensors(needed2, t2);
    del(needed2, 0);
    del(t2, 1);

    Tensor* t3 = read("tests/test_write2.txt", 5);

    return res1 && res2 && (t3 == NULL);
}

int test_check_coordinates() {
    Tensor* t = read("tests/test_write2.txt", 4);
    int coord1[3] = {0, 0, 0};
    int coord2[3] = {1, 1, 1};
    int coord3[3] = {1, 1, 2};
    int coord4[5] = {0, 0, 0, 0, 0};
    int coord5[3] = {0, 1, 3};
    int res1 = check_coordinates(t, coord1, 3);
    int res2 = check_coordinates(t, coord2, 3);
    int res3 = check_coordinates(t, coord3, 3);
    int res4 = check_coordinates(t, coord4, 5);
    int res5 = check_coordinates(t, coord5, 3);
    del(t, 1);
    return res1 && res2 && res3 && !res4 && !res5;
}

int test_change_value_uc() {
    Tensor* t = read("tests/tensors.txt", 1);
    int coord1[3] = {0, 0, 0};
    change_value_uc(coord1, 3, t, 1);
    
    unsigned char** data = (unsigned char**) malloc(sizeof(unsigned char*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(unsigned char) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int s[3] = {2, 2, 2};
    Tensor* needed = input_from_uc(8, 3, s, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_uc(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int test_change_value_sc() {
    Tensor* t = read("tests/tensors.txt", 2);
    int coord1[3] = {0, 1, 1};
    change_value_sc(coord1, 3, t, 4);
    
    signed char** data = (signed char**) malloc(sizeof(signed char*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(signed char) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int shape[3] = {2, 2, 2};
    Tensor* needed = input_from_sc(9, 3, shape, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_sc(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int test_change_value_s() {
    Tensor* t = read("tests/tensors.txt", 3);
    int coord1[3] = {1, 0, 0};
    change_value_s(coord1, 3, t, 5);
    
    short** data = (short**) malloc(sizeof(short*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(short) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int shape[3] = {2, 2, 2};
    Tensor* needed = input_from_s(11, 3, shape, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_s(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int test_change_value_i() {
    Tensor* t = read("tests/tensors.txt", 4);
    int coord1[3] = {1, 0, 1};
    change_value_i(coord1, 3, t, 6);
    
    int** data = (int**) malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(int) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int shape[3] = {2, 2, 2};
    Tensor* needed = input_from_i(12, 3, shape, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_i(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int test_change_value_f() {
    Tensor* t = read("tests/tensors.txt", 5);
    int coord1[3] = {0, 1, 0};
    change_value_f(coord1, 3, t, 3);
    
    float** data = (float**) malloc(sizeof(float*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(float) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int shape[3] = {2, 2, 2};
    Tensor* needed = input_from_f(13, 3, shape, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_f(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int test_change_value_d() {
    Tensor* t = read("tests/tensors.txt", 6);
    int coord1[3] = {1, 1, 1};
    change_value_d(coord1, 3, t, 8);
    
    double** data = (double**) malloc(sizeof(double*) * 4);
    for (int i = 0; i < 4; i++) {data[i] = malloc(sizeof(double) * 2);}
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {data[i][j] = counter; counter++;}
    }
    int shape[3] = {2, 2, 2};
    Tensor* needed = input_from_d(14, 3, shape, data);
    int res1 = equal_tensors(t, needed);

    int coord2[3] = {0, 0, 2};
    int res2 = change_value_d(coord2, 3, t, 1);
    del(t, 1);
    del(needed, 0);
    return res1 && res2;
}

int main() {
    printf("test_cartesian: %i\n", test_cartesian());
    printf("\n-----------Testing <input> and <show_tensor>-----------\n"); test_input_show();
    printf("\n-----------Testing <input_from_uc>-----------\n"); test_input_uc();
    printf("\n-----------Testing <input_from_sc>-----------\n"); test_input_sc();
    printf("\n-----------Testing <input_from_s>-----------\n"); test_input_s();
    printf("\n-----------Testing <input_from_i>-----------\n"); test_input_i();
    printf("\n-----------Testing <input_from_f>-----------\n"); test_input_f();
    printf("\n-----------Testing <input_from_d>-----------\n"); test_input_d();
    printf("\n-----------Testing <write>-----------\n"); test_write();
    printf("test_is_hex: %i\n", test_is_hex());
    printf("test_is_data_type: %i\n", test_is_data_type());
    printf("test_check_format: %i\n", test_check_format());
    printf("test_equal_tensors: %i\n", test_equal_tensors());
    printf("test_read: %i\n", test_read());
    printf("test_check_coordinates: %i\n", test_check_coordinates());
    printf("test_change_value_uc: %i\n", test_change_value_uc());
    printf("test_change_value_sc: %i\n", test_change_value_sc());
    printf("test_change_value_s: %i\n", test_change_value_s());
    printf("test_change_value_i: %i\n", test_change_value_i());
    printf("test_change_value_f: %i\n", test_change_value_f());
    printf("test_change_value_d: %i\n", test_change_value_d());
}
