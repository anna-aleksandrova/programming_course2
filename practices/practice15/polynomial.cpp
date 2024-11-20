#include <iostream>
#include <fstream>

class Polynomial {
    int deg;
    double* coefficients;
    public:
        Polynomial(int deg_, double* coefficients_) {
            deg = deg_;
            coefficients = new double[deg+1];
            coefficients = coefficients_;
        }
        Polynomial(Polynomial const& p) {
            deg = p.deg;
            coefficients = p.coefficients;
        }
        ~Polynomial() {
            delete[] coefficients;
        }
        void set_coefficients();
        void set_coefficient();
        static Polynomial input();
        void show();
        friend void write_into();
        friend void read_from();
};

void Polynomial::set_coefficients() {
    std::string answer("y");
    int n;
    while(answer == "y") {
        std::cout << "Enter a degree of the monomial which coefficient you would like to change: ";
        std::cin >> n;
        if (n < 0 || n > deg) {
            std::cout << "No monomial with such a degree." << std::endl;
        }
        else {
            std::cout << "Enter a new value of the coefficient: ";
            std::cin >> coefficients[n];
        }
        std::cout << "Would you like to continue[y/n]?\n";
        std::cin >> answer;
    }
}

void Polynomial::set_coefficient() {
    int n;
    std::cout << "Enter a degree of the monomial which coefficient you would like to change: ";
    std::cin >> n;
    if (n < 0 || n > deg) {
        std::cout << "No monomial with such a degree." << std::endl;
    }
    else {
        std::cout << "Enter a new value of the coefficient: ";
        std::cin >> coefficients[n];
    }
}

Polynomial Polynomial::input() {
    int deg;
    std::cout << "Enter a degree of the polynomial <a>: ";
    std::cin >> deg;
    double* coefficients = new double[deg + 1];
    for (int i = 0; i <= deg; i++) {
        std::cout << "a[" << i << "]: ";
        std::cin >> coefficients[i];
    }
    return Polynomial(deg, coefficients);
}

void Polynomial::show() {
    for (int i = 0; i < deg; i++) {
        std::cout << "(" << coefficients[i] << ") * x ^ (" << i << ") + ";
    }
    std::cout << "(" << coefficients[deg] << ") * x ^ (" << deg << ")\n";
}

void write_into() {
    std::string fname;
    std::cout << "Enter a name of the file to write the data into: ";
    std::cin >> fname;
    std::fstream fin;
    fin.open(fname, std::ios::out | std::ios::binary);
    if (fin) {
        Polynomial p = Polynomial::input();
        fin.write(reinterpret_cast<char*>(&p.deg), sizeof(int));
        for (int i = 0; i <= p.deg; i++) {
            fin.write(reinterpret_cast<char*>(&p.coefficients[i]), sizeof(double));
        }
        fin.close();
    }
    else {
        std::cout << "Error during opening the file.\n";
    }
}

void read_from() {
    std::string fname;
    std::cout << "Enter a name of the file to read the data from: ";
    std::cin >> fname;
    std::fstream fin;
    fin.open(fname, std::ios::in | std::ios::binary);
    if (fin) {
        int deg;
        fin.read(reinterpret_cast<char*>(&deg), sizeof(int));
        double* coefficients = new double[deg+1];
        for (int i = 0; i <= deg; i++) {
            fin.read(reinterpret_cast<char*>(&coefficients[i]), sizeof(double));
        }
        fin.close();
        Polynomial p(deg, coefficients);
        p.show();
    }
    else {
        std::cout << "Error during opening the file.\n";
    }
}

int main() {
    int deg = 3;
    double* coefficients1 = new double[deg+1] {0, 1, 2, 3};
    Polynomial p1(deg, coefficients1);
    p1.show();

    double* coefficients2 = new double[deg+1];
    Polynomial p2(deg, coefficients2);
    p2.set_coefficients();
    std::cout << "The polynomial after the first modification: ";
    p2.show();
    p2.set_coefficient();
    std::cout << "The polynomial after the second modification: ";
    p2.show();

    write_into();
    read_from();
}
