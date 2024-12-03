#include <iostream>
#include <fstream>
#include "rational.h"

std::ostream& operator<<(std::ostream& out, Rational& r) {
    out << r.num << "/" << r.den << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    in >> r.num >> r.den;
    return in;
}

class Ratio_Exception : public std::exception {
    virtual const char* what() const noexcept {
        return "Can't initialize a rational number with <0> denominator.";
    }
};

Rational::Rational(int num_, int den_) {
    if (den_ == 0) {throw Ratio_Exception();}
    else {
        int temp = gcd(num_, den_);
        num = num_ / temp;
        den = den_ / temp;
    }
}

void Rational::set_denominator(unsigned int den_) {
    if (den_ == 0) {throw Ratio_Exception();}
    else {den = 1;}
}

int write_into(std::string filename, Rational& r) {
    std::fstream fout;
    try {
        fout.open(filename, std::ios::out | std::ios::app);
        if (!fout) {
            throw std::runtime_error("Can't open file <" + filename + ">");
            return 1;
        }
        else {fout << r;}
    }
    catch (std::runtime_error& e) {std::cout << "error: " << e.what() << std::endl;}
    return 0;
}

int main() {
    std::string filename("test.txt");
    Rational r(3, 4);
    write_into(filename, r);
}
