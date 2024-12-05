#pragma once

#include <stdio.h>

/**
 * Tests function <cartesian_product>.
 * 
 * @returns 1 if success, 0 otherwise
 */
extern int test_cartesian();

/**
 * Tests function <input> and <show>.
 */
extern void test_input_show();

/**
 * Tests functions <input_from_uc>, <input_from_sc>, <input_from_s>,
 *                 <input_from_i>, <input_from_f>, <input_from_d>.
 */                 
extern void test_input_uc();
extern void test_input_sc();
extern void test_input_s();
extern void test_input_i();
extern void test_input_f();
extern void test_input_d();

/**
 * Tests function <write>.
 */
extern void test_write();

/**
 * Tests function <is_hex>.
 */
extern int test_is_hex();

/**
 * Tests function <is_dtype>.
 */
extern int test_is_data_type();

/**
 * Tests function <check_format>.
 */
extern int test_check_format();

/**
 * Tests function <equal_tensors>
 */
extern int test_equal_tensors();

/**
 * Tests function <read>.
 */
extern int test_read();

/**
 * Tests function <check_coordinates>.
 */
extern int test_check_coordinates();

/**
 * Tests functions <change_value_uc>, <change_value_sc>, <change_value_s>,
 *                 <change_value_i>, <change_value_f>, <change_value_d>.
 */
extern int test_change_value_uc();
extern int test_change_value_sc();
extern int test_change_value_s();
extern int test_change_value_i();
extern int test_change_value_f();
extern int test_change_value_d();
