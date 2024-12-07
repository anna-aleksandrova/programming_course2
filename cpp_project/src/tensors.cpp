#include <iostream>
#include <cinttypes>
#include <headers/tensors.h>

int is_hex(std::string s) {
    if (s.size() != 4) {return 0;}
    if (s[0] != '0' || s[1] != 'x' || ((s[2] < 'A' || s[2] > 'F') && (s[2] < '0' || s[2] > '9')) || ((s[3] < 'A' || s[3] > 'F') && (s[3] < '0' || s[3] > '9'))) {return 0;}
    return 1;
}

int is_dtype(std::string s) {
    if (s.size() != 4) {return 0;}
    std::set<char> domain = {'8', '9', 'b', 'c', 'd', 'e'};
    if (s[0] != '0' || s[1] != 'x' || s[2] != '0' || domain.count(s[3]) != 1) {return 0;}
    return 1;
}

std::vector<std::vector<int>> cartesian_aux(int range, std::vector<std::vector<int>> set) {
    std::vector<std::vector<int>> res;
    for (int i = 0; i < range; i++) {
        for (std::vector<int> v : set) {
            v.insert(v.begin(), i);
            res.push_back(v);
        }
    }
    return res;
}

std::vector<std::vector<int>> cartesian(std::vector<int> shape) {
    std::vector<std::vector<int>> res;
    int size = shape.size();
    for (int i = 0; i < size; i++) {res.push_back({i});}
    for (int i = 0; i < size - 1; i++) {
        res = cartesian_aux(shape[size - 2 - i], res);
    }
    return res;
}

void indexing_output(std::vector<int> coordinates) {
    for (int i : coordinates) {std::cout << "[" << i << "]";}
}

void hex(int n) {
    if (n < 16) {std::cout << "0x0" << std::hex << n;}
    else {std::cout << "0x"<< std::hex << n;}
}

void hexf(int n, std::ofstream& fout) {
    if (n < 16) {fout << "0x0" << std::hex << n;}
    else {fout << "0x"<< std::hex << n << " ";}
}

int check_coordinates(std::vector<int> shape, std::vector<int> coordinates) {
    if (coordinates.size() != shape.size()) {return 0;}
    for (int i = 0; i < coordinates.size(); i++) {
        if (!(coordinates[i] >= 0 && coordinates[i] < shape[i])) {return 0;}
    }
    return 1;
}
