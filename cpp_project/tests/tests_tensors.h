#pragma once
#include "/home/anna-aleksandrova/Desktop/programming_course2/cpp_project/headers/tensors.h"

// tests function <is_dtype()>
extern int test_is_dtype();

// tests function <is_dtype()>
extern int test_is_hex();

// tests function <equal_matrices>
extern int test_equal_matrices();

// tests function <cartesian_aux>
extern int test_cartesian_aux();

// tests function <cartesian>
extern int test_cartesian();

// checks the equality of matrices with data of different types
template <typename T> int equal_matrices(std::vector<std::vector<T>> matrix1, std::vector<std::vector<T>> matrix2);

// tests function <equal_tensors>
extern int test_equal_tensors();

// tests functions <output_matrix> and <output_matrix>
extern void test_inout_matrix();

// tests method <write> from the class <Tensor>
extern void test_write();

// tests function <read_matrix>
extern int test_read_matrix();

// tests function <check_format>
extern int test_check_format();

// tests function <read> for tensors
extern int test_read();

// tests function <check_coordinates>
extern int test_check_coordinates();

//tests method <change_value>
extern int test_change_value();