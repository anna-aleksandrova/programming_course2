#pragma once
#include <stdio.h>
#include <stdint.h>

/**
 * Represents a tensor in IDX format.
 * 
 * @param data_type encodes one of C basic arithmetic types
 * @param power represents the number of dimensions
 * @param shape represents the size of every dimension
 * @param tensor_data contains the data as tensors of lower dimension
 * @param data_<spec> contains the data of a certain type (for dimension == 1)
 */
typedef struct Tensor{
    unsigned char first_byte, second_byte;
    int data_type;
    int power, product;
    __uint32_t *shape;
    unsigned char** data_uc;
    signed char** data_sc;
    short** data_s;
    int** data_i;
    float** data_f;
    double** data_d;
}Tensor;

/**
 * Creates a tensor (data is taken from console).
 * 
 * @returns Tensor* in case of correct data.
 *          NULL otherwise.
 */
extern Tensor* input();

/**
 * Creates a tensor from the given parameters.
 * 
 * @returns Tensor* in case of correct data.
 *          NULL otherwise.
 */
extern Tensor* input_from_uc(int data_type, int power, int* shape, unsigned char** data);
extern Tensor* input_from_sc(int data_type, int power, int* shape, signed char** data);
extern Tensor* input_from_s(int data_type, int power, int* shape, short** data);
extern Tensor* input_from_i(int data_type, int power, int* shape, int** data);
extern Tensor* input_from_f(int data_type, int power, int* shape, float** data);
extern Tensor* input_from_d(int data_type, int power, int* shape, double** data);

/**
 * Prints out the tensor <tensor> into the console.
 */
extern void show_tensor(Tensor* tensor);

/**
 * Deletes the tensor <t>.
 * 
 * @param sh_check 1 if memory was allocated dynamically for <sh_check>,
 *                 0 otherwise.
 */
extern void del(Tensor* tensor, int sh_check);

/**
 * Writes the tensor into the file.
 * 
 * @param filename name of the file to write the tensor into
 * @param tensor a tensor to be written into the file <filename>
 * 
 * @returns 0 success
 *          1 failure
 */
extern int write(char* filename, Tensor* tensor);

/**
 * Checks the file <filename> if it stores the data(tensors) in IDX format.
 * 
 * @returns 0 if all tensors are in IDX format,
 *          1 otherwise
 */
extern int check_format(char* filename);

/**
 * Checks whether the given string <n> represents a number in hexadecimal form.
 * 
 * @returns 1 if <n> is a number in hexadeciaml form,
 *          0 otherwise
 */
extern int is_hex(char* n);

/**
 * Checks whether the given string <n> represents an encoded data_type for <Tensor>.
 * 
 * @returns 1 if <n> is a number in hexadeciaml form,
 *          0 otherwise
 */
extern int is_dtype(char* n);

/**
 * Reads the tensor from the file.
 * 
 * @param filename name of the file to read the tensor from
 * @param n the number of the tensor
 * 
 * @returns pointer to the read tensor in case of successful reading
 *          NULL in case of failure
 */
extern Tensor* read(char* filename, unsigned int n);

/**
 * Checks whether two tensors are equal.
 * 
 * @returns 1 if the tensors are equal, 0 otherwise.
 */
extern int equal_tensors(Tensor* tensor1, Tensor* tensor2);

/**
 * Checks if there is a value with <coordinates> in <tensor>.
 * 
 * @param size the amount of coordinates
 * 
 * @returns 1 if there is, 0 otherwise
 */
extern int check_coordinates(Tensor* tensor, int* coordinates, int size);

/**
 * Changes the value with <coordinates> in <tensor>.
 * 
 * @param coordinates coordinates to access the value to change
 * @param size the amount of coordinates
 * @param tensor tensor to change
 * @param new_value can be of different types
 * 
 * @returns 0 if the change was successful, 1 otherwise
 */
extern int change_value_uc(int* coordinates, int size, Tensor* tensor, unsigned char new_value);
extern int change_value_sc(int* coordinates, int size, Tensor* tensor, signed char new_value);
extern int change_value_s(int* coordinates, int size, Tensor* tensor, short new_value);
extern int change_value_i(int* coordinates, int size, Tensor* tensor, int new_value);
extern int change_value_f(int* coordinates, int size, Tensor* tensor, float new_value);
extern int change_value_d(int* coordinates, int size, Tensor* tensor, double new_value);
