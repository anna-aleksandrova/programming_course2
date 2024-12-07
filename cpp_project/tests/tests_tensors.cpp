#include <iostream>
#include "tests_tensors/tests_tensors.h"

int test_is_dtype() {
    int res1 = is_dtype("0x08");
    int res2 = is_dtype("0x09");
    int res3 = is_dtype("0x0b");
    int res4 = is_dtype("0x0c");
    int res5 = is_dtype("0x0d");
    int res6 = is_dtype("0x0e");
    int res7 = is_dtype("0x00");
    int res8 = is_dtype("0x008");
    int res9 = is_dtype("X08");
    int res10 = is_dtype("0.0B");
    return res1 && res2 && res3 && res4 && res5 && res6 && !res7 && !res8 && !res9 && !res10;
}

int test_is_hex() {
    int res0 = is_hex("0x00");
    int res1 = is_hex("0xAA");
    int res2 = is_hex("0xaa");
    int res3 = is_hex("0xAb");
    int res4 = is_hex("0xAr");
    int res5 = is_hex("0xRR");
    int res6 = is_hex("asdfasdf");
    int res7 = is_hex("asdf");
    return res0 && res1 && !res2 && !res3 && !res4 && !res5 && !res6 && !res7;
}

template <typename T> int equal_matrices(std::vector<std::vector<T>>  matrix1, std::vector<std::vector<T>> matrix2) {
    int rows1 = matrix1.size();
    int rows2 = matrix2.size();
    if (rows1 != rows2) return 0;
    int columns1 = matrix1[0].size();
    int columns2 = matrix2[0].size();
    if (columns1 != columns2) return 0;
    if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns1; j++) {if (fabs(matrix1[i][j] - matrix2[i][j]) > __DBL_EPSILON__) return 0;}
        }
    }
    else {
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns1; j++) {
                if (matrix1[i][j] != matrix2[i][j]) return 0;
            }
        }
    }
    return 1;
}

int test_cartesian_aux() {
    std::vector<std::vector<int>> aux = {{0}, {1}};
    std::vector<std::vector<int>> res = cartesian_aux(3, aux);
    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        {2, 0},
        {2, 1}
    };
    int res1 = equal_matrices<int>(res, expected);
    aux = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    res = cartesian_aux(2, aux);
    expected = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };
    int res2 = equal_matrices<int>(res, expected);
    return  res2;
}

int test_equal_matrices() {
    std::vector<std::vector<int>> m1 = {
        {1, 2, 3},
        {1, 2, 3}
    };
    std::vector<std::vector<int>> m2 = {
        {1, 2, 3},
        {1, 2, 3}
    };
    int res1 = equal_matrices<int>(m1, m2);
    m2 = {
        {1, 2, 3},
        {1, 2, 4}
    };
    int res2 = equal_matrices<int>(m1, m2);
    m2 = {
        {1, 2, 3}
    };
    int res3 = equal_matrices<int>(m1, m2);
    m2 = {
        {1, 2, 3, 4}
    };
    int res4 = equal_matrices<int>(m1, m2);

    std::vector<std::vector<double>> m3 = {
        {1.5, 1.6, 1.7},
        {1.2, 1.4, 1.7}
    };
    std::vector<std::vector<double>> m4 = {
        {1.50000000000001, 1.6, 1.7},
        {1.2, 1.4, 1.7}
    };
    int res5 = equal_matrices<double>(m3, m3);
    int res6 = equal_matrices<double>(m3, m4);
    return res1 && !res2 && !res3 && !res4 && res5 && !res6;
}

int test_cartesian() {
    std::vector<int> shape = {1, 2, 3};
    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 2},
        {0, 1, 0},
        {0, 1, 1},
        {0, 1, 2}
    };
    int res1 = equal_matrices<int>(cartesian(shape), expected);
    shape = {2, 2, 3};
    expected = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 2},
        {0, 1, 0},
        {0, 1, 1},
        {0, 1, 2},
        {1, 0, 0},
        {1, 0, 1},
        {1, 0, 2},
        {1, 1, 0},
        {1, 1, 1},
        {1, 1, 2}
    };
    int res2 = equal_matrices<int>(cartesian(shape), expected);
    return res1 && res2;
}

void test_inout_matrix() {
    std::cout << "You're entering the data for a tensor of shape 2 x 2 x 3, data type = int:" << std::endl;
    std::vector<int> shape = {2, 2, 3};
    std::vector<std::vector<int>> res = input_matrix<int>(shape, 4, 3);
    std::cout << std::endl << "Result: " << std::endl;
    output_matrix<int>(res);
}

void test_in_out() {
    Tensor<float> t;
    t.input();
    t.show();
}

void test_write() {
    std::string filename;
    int dtype;
    std::cout << "Enter the name of the file to write the tensor into: ";
    std::cin >> filename;
    std::cout << "Enter the type of the data contained in tensor: ";
    std::cin >> dtype;
    if (dtype == 8) {Tensor<unsigned char> t; t.input(); t.write(filename);}
    else if (dtype == 9) {Tensor<signed char> t; t.input(); t.write(filename);}
    else if (dtype == 11) {Tensor<short> t; t.input(); t.write(filename);}
    else if (dtype == 12) {Tensor<int> t; t.input(); t.write(filename);}
    else if (dtype == 13) {Tensor<float> t; t.input(); t.write(filename);}
    else if (dtype == 14) {Tensor<double> t; t.input(); t.write(filename);}
}

int test_read_matrix() {
    std::string filename1("test_readmatrix1.txt");
    std::ifstream fin(filename1);
    std::vector<std::vector<int>> read1 = read_matrix<int>(fin, 3, 4);
    std::vector<std::vector<int>> expected1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int res1;
    if (read1 == expected1) {res1 = 1;} else {res1 = 0;}
    fin.close();

    std::string filename2("test_readmatrix2.txt");
    std::ifstream fin1(filename2);
    std::vector<std::vector<double>> read2 = read_matrix<double>(fin1, 5, 5);
    std::vector<std::vector<double>> expected2 = {
        {20.5, 19.5, 18.5, 17.5, 16.5},
        {2, 3, 4, 5, 7},
        {-10.1, 20.123, 123.123, 456.1, -456.23},
        {0, 0, 0, 0, 0},
        {1, -1, 1, -1, 1}
    };
    int res2;
    if (read2 == expected2) {res2 = 1;} else {res2 = 0;}
    fin1.close();
    return res1 && res2;
}

int test_equal_tensors() {
    std::vector<std::vector<int>> data1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    std::vector<std::vector<int>> data2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {11, 11, 12}
    };

    Tensor<int> t1(12, 3, {2, 2, 3}, data1);
    Tensor<int> t2(12, 3, {2, 2, 3}, data1);
    Tensor<int> t3(12, 3, {2, 2, 3}, data2);

    std::vector<std::vector<int>> data3 = {{1}};
    Tensor<int> t4(12, 2, {1, 1}, data3);

    int res1 = equal_tensors(t1, t2);
    int res2 = equal_tensors(t1, t3);
    int res3 = equal_tensors(t1, t4);
    return res1 && !res2 && !res3;
}

int test_check_format() {
    int res1 = check_format<int>("test_readtensor1.txt");
    int res2 = check_format<float>("wrong_format1.txt");
    int res3 = check_format<float>("wrong_format2.txt");
    return res1 && !res2 && !res3;
}

int test_read() {
    Tensor<int> read1 = read<int>("test_readtensor1.txt", 1);
    Tensor<int> read2 = read<int>("test_readtensor1.txt", 2);
    std::vector<std::vector<int>> aux = {
        {1, 2}, {3, 4}, {5, 6}, {7, 8}
    };
    Tensor<int> expected(12, 3, {2, 2, 2}, aux);
    int res1, res2;
    if (equal_tensors(read1, expected)) {res1 = 1;} else {res1 = 0;}
    if (equal_tensors(read2, expected)) {res2 = 1;} else {res2 = 0;}
    return res1 && !res2;
}

int test_check_coordinates() {
    std::vector<std::vector<int>> data = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {11, 11, 12}
    };
    Tensor<int> t(12, 3, {2, 2, 3}, data);
    int res1 = check_coordinates({2, 2, 3}, {0, 0, 0});
    int res2 = check_coordinates({2, 2, 3}, {0, 1, 0});
    int res3 = check_coordinates({2, 2, 3}, {1, 1, 2});
    int res4 = check_coordinates({2, 2, 3}, {1, 1, -2});
    int res5 = check_coordinates({2, 2, 3}, {2, 2, 2});
    int res6 = check_coordinates({2, 2, 3}, {2, 0, 0});
    return res1 && res2 && res3 && !res4 && !res5 && !res6;
}

int test_change_value() {
    std::vector<std::vector<int>> data1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {11, 11, 12}
    };
    Tensor<int> t1(12, 3, {2, 2, 3}, data1);
    t1.change_value({0, 0, 0}, 0);
    std::vector<std::vector<int>> data_exp1 = {
        {0, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {11, 11, 12}
    };
    Tensor<int> exp1(12, 3, {2, 2, 3}, data_exp1);
    int res1 = equal_tensors(t1, exp1);
    return res1;

    std::vector<std::vector<float>> data2 = {
        {1, 2, 3},
        {4, 5.5, 6},
        {7, 8, 9},
        {11, 11, 12}
    };
    Tensor<float> t2(12, 3, {2, 2, 3}, data2);
    t2.change_value({0, 1, 1}, -0.01);
    std::vector<std::vector<float>> data_exp2 = {
        {1, 2, 3},
        {4, -0.01, 6},
        {7, 8, 9},
        {11, 11, 12}
    };
    Tensor<float> exp2(12, 3, {2, 2, 3}, data_exp2);
    int res2 = equal_tensors(t2, exp2);
    return res1 && res2;
}

int main() {
    std::cout << "test_is_dtype: " << test_is_dtype() << std::endl;
    std::cout << "test_is_hex: " << test_is_hex() << std::endl;
    std::cout << "test_equal_matrices: " << test_equal_matrices() << std::endl;
    std::cout << "test_cartesian_aux: " << test_cartesian_aux() << std::endl;
    std::cout << "test_cartesian: " << test_cartesian() << std::endl;
    test_inout_matrix();
    test_in_out();
    test_write();
    std::cout << "test_read_matrix: " << test_read_matrix() << std::endl;
    std::cout << "test_equal_tensors: " << test_equal_tensors() << std::endl;
    std::cout << "test_check_format: " << test_check_format() << std::endl;
    std::cout << "test_read: " << test_read() << std::endl;
    std::cout << "test_check_coordinates: " << test_check_coordinates() << std::endl;
    std::cout << "test_change_value: " << test_change_value() << std::endl;
}
