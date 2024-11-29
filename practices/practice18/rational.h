#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

class Rational {
    int num, den;
    unsigned int gcd(int n1, int n2);
    void reduce() {
        int temp = gcd(num, den);
        num /= temp;
        den /= temp;
    }
    public:
        Rational(){};
        Rational(bool option){
            // option (bool): if <false>, random rational is created, else: 1/1.
            if (!option) {
                num = rand();
                den = rand();
            }
            else {
                num = 1;
                den = 1;
            }
            reduce();
        };
        Rational(int num_, int den_) {
            int temp = gcd(num_, den_);
            num = num_ / temp;
            den = den_ / temp;
        }
        Rational(Rational const& r) {
            num = r.num;
            den = r.den;
        }
        static Rational input_terminal() {
            int num, den;
            std::cout << "Numerator: ";
            std::cin >> num;
            std::cout << "Denominator: ";
            std::cin >> den;
            return Rational(num, den);
        }
        void output_terminal() {
            std::cout << num << "/" << den << "\n";
        }
        int get_num();
        int get_den();
        void set_numerator(int num_);
        void set_denominator(unsigned int den);
        Rational add(Rational r1, Rational r2);
        Rational multiply(Rational r1, Rational r2);
        Rational operator+(Rational const& r);
        Rational operator*(Rational const& r);
        Rational operator-(Rational const& r);
        Rational operator/(Rational const& r);
        bool operator>(Rational const& r);
        bool operator==(Rational const& r);
        bool operator<(Rational const& r);
        bool operator>=(Rational const& r);
        bool operator<=(Rational const& r);
        friend std::ostream& operator<<(std::ostream& out, Rational& r);
        friend std::istream& operator>>(std::istream& in, Rational& r);
};

Rational Rational::add(Rational r1, Rational r2) {
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational Rational::multiply(Rational r1, Rational r2) {
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

void Rational::set_numerator(int num_) {
    num = num_;
}

void Rational::set_denominator(unsigned int den_) {
    if (den_ != 0) {
        den = den_;
    }
    else {
        den = 1;
    }
}

int Rational::get_num() {
    return num;
}

int Rational::get_den() {
    return den;
}

unsigned int Rational::gcd(int a, int b) {
    if (a == 0) {return b;}
    if (b == 0) {return a;}
    a = fabs(a);
    b = fabs(b);
    if (a == b) {return a;}
    if (a > b) {
        return gcd(a - b, b);
    }
    else {
        return gcd(a, b - a);
    }
}

Rational Rational::operator+(Rational const& r) {
    int m = num * r.den + den * r.num;
    int n = den * r.den;
    return Rational(m, n);
}

Rational Rational::operator*(Rational const& r) {
    return Rational(num * r.num, den*r.den);
}

Rational Rational::operator-(Rational const& r) {
    int m = num * r.den - den * r.num;
    int n = den * r.den;
    return Rational(m, n);
}

Rational Rational::operator/(Rational const& r) {
    if (r.num == 0) {
        return Rational(0, 1);
    }
    else {
        return Rational(num * r.den, den * r.num);
    }
}

bool Rational::operator>(Rational const& r) {
    return (num * r.den > den * r.num);
}

bool Rational::operator==(Rational const& r) {
    return (num * r.den == den * r.num);
}

bool Rational::operator<(Rational const &r) {
    return !(*this > r) && !(*this == r);
}

bool Rational::operator>=(Rational const& r) {
    return (*this > r || *this == r);
}

bool Rational::operator<=(Rational const& r) {
    return (*this < r || *this == r);
}

std::ostream& operator<<(std::ostream& out, Rational& r) {
    out << r.num << "/" << r.den;
    return out;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    in >> r.num >> r.den;
    return in;
}
