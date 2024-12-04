#include <iostream>
#include <vector>
#include <cmath>

std::vector <double> input_vect(int dimension) {
    std::vector <double> vect;
    double x;
    for (int i = 0; i < dimension; i++) {
        std::cin >> x;
        vect.push_back(x);
    }
    return vect;
}

double norm(const std::vector<double>& vect) {
    double sum = 0;
    for (int i = 0; i < vect.size(); i++) {
        sum += pow(vect[i], 2);
    }
    return sqrt(sum);
}

void task1_1() {
    int dimension;
    std::cout << "Enter the dimension: ";
    std::cin >> dimension;
    std::vector <double> vect = input_vect(dimension);
}

void task1_2() {
    int n, d;
    std::cout << "Enter the dimension: ";
    std::cin >> d;
    std::cout << "Enter the amount of vectors: ";
    std::cin >> n;
    std::vector <double> vect;
    std::vector <std::vector<double>> matrix;
    for (int i = 0; i < n; i++) {
        vect = input_vect(d);
        matrix.push_back(vect);
    }
    double sum = 0;
    for (const std::vector<double>& v:matrix) {sum += norm(v);}
    std::cout << "The sum of norms of row vectors in the matrix: " << sum << std::endl;
}

int main() {
    task1_2();
}
