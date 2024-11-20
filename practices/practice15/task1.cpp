#include <cmath>
#include "rational.h"

#define LEN 50

Rational *input_array() {
    Rational *array = new Rational[LEN];
    for (int i = 0; i < LEN; i++) {
        array[i] = Rational::input_terminal();
    }
    return array;
}

Rational min(Rational *array) {
    Rational min = array[0];
    for (int i = 1; i < LEN; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void task1_1() {
    Rational* array = input_array();
    Rational min_number = min(array);
    std::cout << "Minimal rational number in the array: ";
    min_number.output_terminal();
    delete[] array;
}

void task1_2() {
    double eps;
    std::cout << "Enter <eps>: ";
    std::cin >> eps;
    Rational current(1, 1);
    Rational sum = current;
    int i = 1;
    while (fabs(((double) current.get_num()) / current.get_den()) >= eps) {
        current = Rational(pow(-1, i), (i+1) * (i+1));
        sum = sum + current;
        sum.output_terminal();
        i++;
    }
    std::cout << "The sum of the series: ";
    std::cout << (double) sum.get_num() / sum.get_den() << std::endl;
    std::cout << M_PI * M_PI / 12 << std::endl;
    if (eps < pow(10, -1)) {
        std::cout << "The series converges to (pi^2)/12: " << (fabs((double) sum.get_num() / sum.get_den() - M_PI * M_PI / 12) < 0.01) << std::endl;
    }
    else {
        std::cout << "Not enough accuracy of <eps> to talk about convergence.\n";
    }
}

int main() {
    task1_2();
}
