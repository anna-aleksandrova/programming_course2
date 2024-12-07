#pragma once

#include <iostream>
#include <vector>
#include <cinttypes>
#include <fstream>
#include <exception>
#include <set>
#include <cmath>

/**
 * Represents a tensor in IDX format.
 * 
 * @param data_type encodes one of the basic arithmetic types
 * @param power represents the number of dimensions
 * @param shape represents the size of every dimension
 * @param data contains the data of a certain type
 */
template <typename T> class Tensor {
    public:
        Tensor(){};
        Tensor(int d_type, int power, std::vector<int> shape, std::vector<std::vector<T>> data);
        int input();
        void show();
        int write(std::string filename);
        int change_value(std::vector<int> coordinates, T new_value);
        template <typename P> friend int equal_tensors(Tensor<P> t1, Tensor<P> t2);
        template <typename P> friend Tensor<P> read(std::string filename, int n);
        template <typename P> friend int check_format(std::string filename);
        friend int check_coordinates(std::vector<int> shape, std::vector<int> coordinates);
    private:
        unsigned char first_byte, second_byte;
        int data_type, power, product;
        std::vector<int> shape;
        std::vector<std::vector<T>> data;
};

template <typename T> Tensor<T>::Tensor(int d_type, int pow, std::vector<int> sh, std::vector<std::vector<T>> d) {
    first_byte = 0x00; second_byte = 0x00;
    data_type = d_type;
    power = pow;
    shape = sh;
    data = d;
    product = 1;
    for (int i = 0; i < power - 1; i++) {product *= sh[i];}
}

/**
 * Checks whether the string <s> represents an encoding of some data type.
 */
extern int is_dtype(std::string s);

/**
 * Checks whether the string <s> represents a hexadecimal number. 
 */
extern int is_hex(std::string s);

/**
 * Is thrown if user's input does not encode any data type.
 */
class WrongDataType : public std::exception {
    public:
        const char* what() const throw() {
            return "No data type is encoded with such a number.";
        }
};

class WrongFormat : public std::exception {
    public:
        WrongFormat(std::string expected) {expected_f = expected;}
        const char* what() const throw() {
            std::string aux("Wrong format. Expected : ");
            aux += expected_f;
            return aux.c_str();
        }
    private:
        std::string expected_f;
};

class WrongData : public std::exception {
    public:
        WrongData(std::string e) {error = e;}
        const char* what() const throw() {
            std::string aux(" does not match any of the data types.");
            aux = error + aux;
            return aux.c_str();
        }
    private:
        std::string error;
};

// For usage in <cartesian>.
std::vector<std::vector<int> > cartesian_aux(int range, std::vector<std::vector<int>> set);

/**
 * Generates the components of cartesian product of the sets S1, S2, ..., S_n,
 * (the order is fixed), where S1 = {0, 1, ..., s1}, ..., S_n = {0, 1, ..., s_n},
 * {s1, s2, .., sn} ⊂ Z>=0.
 * 
 * @param shape defines s1, s2, .., s_n
 */
std::vector<std::vector<int>> cartesian(std::vector<int> shape);

/**
 * For comprehensible output of coordinates (i1, i2, ..., in) of tensor's component.
 * 
 * @param coordinates contains the values of i1, i2, ..., in
 */
void indexing_output(std::vector<int> coordinates);

/**
 * Inputs the tensor's data. Uses linear order to represent 
 * the elements of the tensor T ⊂ V1 x V2 x ... x V_n-1 x V_n
 * 
 * @param shape represents the dimensions of V1, V2, ..., V_n
 * @param product the power of the cartesian product V1 x V2 x ... x V_n-1
 * @param ldim represents the dimension of V_n
 * @returns the data stored in tensor
 */
template <typename T> std::vector<std::vector<T>> input_matrix(std::vector<int> shape, int product, int ldim) {
    std::vector<std::vector<T>> res;
    T current;
    std::vector<T> temp;
    std::vector<int> needed_shape;
    for (int i = 0; i < shape.size() - 1; i++) {needed_shape.push_back(shape[i]);}
    std::vector<std::vector<int>> indexing = cartesian(needed_shape);
    int counter = 0;
    for (int i = 0; i < product; i++) {
        std::cout << "t";
        indexing_output(indexing[counter]);
        std::cout << ": ";
        for (int j = 0; j < ldim; j++) {
            std::cin >> current;
            temp.push_back(current);
        }
        res.push_back(temp);
        temp.clear();
        counter++;
    }
    return res;
}

/**
 * Prints out the matrix.
 * 
 * @param matrix to print out
 */
template <typename T> void output_matrix(std::vector<std::vector<T>> matrix) {
    std::cout << std::endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * To input a tensor from the console.
 */
template <typename T> int Tensor<T>::input() {
    std::string d_type, pow;
    if (typeid(T) == typeid(unsigned char)) {data_type = 8;}
    if (typeid(T) == typeid(signed char)) {data_type = 9;}
    if (typeid(T) == typeid(short)) {data_type = 11;}
    if (typeid(T) == typeid(int)) {data_type = 12;}
    if (typeid(T) == typeid(float)) {data_type = 13;}
    if (typeid(T) == typeid(double)) {data_type = 14;}
    std::cout << "Enter the forth byte of the magic number (represents the number of dimensions): ";
    try {
        std::cin >> pow;
        if (!is_hex(pow)) {throw WrongFormat("hex");}
    }
    catch (WrongFormat& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    power = stoi(pow, 0, 16);
    int temp;
    product = 1;
    for (int i = 0; i < power; i++) {
        std::cout << "Enter the size of the " << i + 1 << " dimension: ";
        std::cin >> temp;
        shape.push_back(temp);
        if (i != power - 1) {product *= temp;}
    }
    data = input_matrix<T>(shape, product, shape[power - 1]);
    first_byte = 0x00;
    second_byte = 0x00;
    return 0;
}

void hex(int n);

void hexf(int n, std::ofstream& fout);

template <typename T> void Tensor<T>::show() {
    std::cout << std::endl << "=================" << "Tensor" << "=================" << std::endl;
    hex(first_byte);
    std::cout << " ";
    hex(second_byte);
    std::cout << " ";
    hex(data_type);
    std::cout << " ";
    hex(power);
    std::cout << std::endl;
    std::cout << "shape : ";
    for (int i : shape) {std::cout << i << " ";}
    std::cout << std::endl << "data:" << std::endl;
    output_matrix(data);
}

/**
 * Checks the equality of tensors.
 * 
 * @returns 1 if the tensors are equal, 0 otherwise
 */
template <typename T> int equal_tensors(Tensor<T> t1, Tensor<T> t2) {
    if (t1.data_type != t2.data_type || t1.power != t2.power || t1.product != t2.product || t1.shape != t2.shape || t1.data != t2.data) {return 0;}
    else {return 1;}
}

/**
 * Writes matrix of any basic C++ arithmetic types into the file.
 */
template <typename T> void write_matrix(std::ofstream& fout, std::vector<std::vector<T>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            fout << matrix[i][j] << " ";
        }
        fout << std::endl;
    }
}

template <typename T> int Tensor<T>::write(std::string filename) {
    std::ofstream fout(filename);
    hexf(first_byte, fout); fout << " ";
    hexf(second_byte, fout); fout << " ";
    hexf(data_type, fout); fout << " ";
    hexf(power, fout); fout << " ";
    fout << std::endl;
    for (int el : shape) {fout << el << " ";}
    fout << std::endl;
    write_matrix(fout, data);
    return 1;
}

/**
 * Reads the matrix from the file.
 * 
 * @param fin stream to read the matrix from
 * @param rows the amount of rows which the matrix must contain
 * @param columns the amount of columns which the matrix must contain
 * 
 * @returns pointer to the read matrix in case of success,
 *          nullptr otherwise
 */
template <typename T> std::vector<std::vector<T>> read_matrix(std::ifstream& fin, int rows, int columns) {
    T curr;
    std::vector<T> temp;
    std::vector<std::vector<T>> res;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fin >> curr;
            temp.push_back(curr);
        }
        res.push_back(temp);
        temp.clear();
    }
    return res;
}

/**
 * Checks the file <filename> if it stores the data(tensors) in IDX format.
 * 
 * @returns 1 if all tensors are in IDX format,
 *          0 otherwise
 */
template <typename T> int check_format(std::string filename) {
    std::ifstream fin(filename);
    std::string buf;
    int dtype, power, temp, ldim, product = 1;
    std::vector<int> shape;
    std::vector<std::vector<T>> data;
    Tensor<T> for_error;
    for_error.data_type = -1;
    while (!fin.eof()) {
        for (int i = 0; i < 2; i++) {
                fin >> buf; 
                if (buf != "0x00") {return 0;}
        } 
        fin >> buf;
        if (!is_dtype(buf)) {return 0;}
        else {dtype = stoi(buf, 0, 16);}
        fin >> buf;
        if (!is_hex(buf)) {return 0;} 
        else {power = stoi(buf, 0, 16);}
        for (int i = 0; i < power; i++) {
            fin >> buf;
            temp = stoi(buf);
            shape.push_back(temp);
            if (i != power - 1) {product *= temp;}
            else {ldim = temp;}
        }
        if (dtype == 8) {data = read_matrix<T>(fin, product, ldim);}
        else if (dtype == 9) {data = read_matrix<T>(fin, product, ldim);}
        else if (dtype == 11) {data = read_matrix<T>(fin, product, ldim);}
        else if (dtype == 12) {data = read_matrix<T>(fin, product, ldim);}
        else if (dtype == 13) {data = read_matrix<T>(fin, product, ldim);}
        else if (dtype == 14) {data = read_matrix<T>(fin, product, ldim);}
    }
    fin.close();
    return 1;
}

/**
 * Reads the tensor from the file.
 * 
 * @param filename name of the file to read the tensor from
 * 
 * @returns Tensor<T>: the read tensor in case of successful reading
 * @throws std::runtime_error in case of failure
 */
template <typename T> Tensor<T> read(std::string filename, int n) {
    std::ifstream fin(filename);
    std::string buf;
    int dtype, power, temp, ldim, product = 1, counter = 1;
    std::vector<int> shape;
    std::vector<std::vector<T>> data;
    Tensor<T> for_error;
    for_error.data_type = -1;
    if (!check_format<T>(filename)) {return for_error;}
    while (!fin.eof()) {
        for (int i = 0; i < 2; i++) {fin >> buf;}
        fin >> buf;
        dtype = stoi(buf, 0, 16);
        fin >> buf;
        power = stoi(buf, 0, 16);
        for (int i = 0; i < power; i++) {
            fin >> buf;
            temp = stoi(buf);
            shape.push_back(temp);
            if (i != power - 1) {product *= temp;}
            else {ldim = temp;}
        }
        if (counter == n) {
        if (dtype == 8) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t1(dtype, power, shape, data);
            fin.close(); return t1;
        }
        else if (dtype == 9) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t2(dtype, power, shape, data);
            fin.close(); return t2;
        }
        else if (dtype == 11) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t3(dtype, power, shape, data);
            fin.close(); return t3;
        }
        else if (dtype == 12) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t4(dtype, power, shape, data);
            fin.close(); return t4;
        }
        else if (dtype == 13) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t5(dtype, power, shape, data);
            fin.close(); return t5;
        }
        else if (dtype == 14) {
            data = read_matrix<T>(fin, product, ldim);
            Tensor<T> t6(dtype, power, shape, data);
            fin.close(); return t6;
        }
        }
        else {
            if (dtype == 8) {data = read_matrix<T>(fin, product, ldim);}
            else if (dtype == 9) {data = read_matrix<T>(fin, product, ldim);}
            else if (dtype == 11) {data = read_matrix<T>(fin, product, ldim);}
            else if (dtype == 12) {data = read_matrix<T>(fin, product, ldim);}
            else if (dtype == 13) {data = read_matrix<T>(fin, product, ldim);}
            else if (dtype == 14) {data = read_matrix<T>(fin, product, ldim);}
            counter++;
        }
    }
    fin.close();
    return for_error;
} 

/**
 * Checks if there is a value with <coordinates> in the tensor with shape <shape>.
 * 
 * @returns 1 if there is, 0 otherwise
 */
int check_coordinates(std::vector<int> shape, std::vector<int> coordinates);

template <typename T> int Tensor<T>::change_value(std::vector<int> coordinates, T new_value) {
    if (!check_coordinates(shape, coordinates)) {return 1;}
    std::vector<int> nshape;
    std::vector<int> ncoordinates;
    for (int i = 0; i < shape.size(); i++) {nshape.push_back(shape[i]); ncoordinates.push_back(coordinates[i]);}
    std::vector<std::vector<int>> indexing = cartesian(nshape);
    for (int i = 0; i < indexing.size(); i++) {
        if (indexing[i] == ncoordinates) {
            data[i][coordinates[coordinates.size() - 1]] = new_value; \
            return 0;
        }
    }
    return 1;
}
