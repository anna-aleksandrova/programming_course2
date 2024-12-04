#include <iostream>
#include <list>
#include <iterator>
#include "Polynome.h"

template <typename T> Polynome<T>::Polynome(std::list<T>& c) {
    while (c.size() != 1) {
        if (c.back() != 0) {break;}
        else {c.pop_back();}
    }
    coefficients = c;
    deg = c.size() - 1;
}

template <typename T> void Polynome<T>::input() {
    std::string answer;
    std::list<T> c;
    T temp;
    int deg_ = -1;
    while(answer != "n") {
        deg_++;
        std::cout << "f_" << deg_ << ": ";
        std::cin >> temp;
        c.push_back(temp);
        std::cout << "Continue[y/n]: ";
        std::cin >> answer;
    }
    deg = deg_ - 1;
    this->coefficients = c;
    this->deg = deg_;
}

template <typename T> void Polynome<T>::output() {
    unsigned int i = 0;
    for (auto pos = coefficients.begin(); pos != coefficients.end(); ++pos) {
        if (i == coefficients.size() - 1) {std::cout << "(" << *pos << ") * x ^ " << i << std::endl; continue;} 
        std::cout << "(" << *pos << ") * x ^ " << i << " + ";
        i++;
    }
}

template <typename T> std::list<T> equal_size(std::list<T> lst1, std::list<T> lst2) {
    size_t needed = std::max(lst1.size(), lst2.size());
    if (lst1.size() > lst2.size()) {
        for (int i = 0; i <= lst1.size() - lst2.size(); i++) {
            lst2.push_back(0); 
        }
        return lst2;
    }
    else {
        for (int i = 0; i < lst2.size() - lst1.size(); i++) {
            lst1.push_back(0); 
        }
        return lst1;
    }
}

template <typename T> Polynome<T> Polynome<T>::add(Polynome& p1) {
    if (coefficients.size() > p1.coefficients.size()) {p1.coefficients = equal_size(coefficients, p1.coefficients);}
    if (p1.coefficients.size() > coefficients.size()) {coefficients = equal_size(coefficients, p1.coefficients);}
    std::list<T> res;
    auto pos2 = p1.coefficients.begin();
    for (auto pos1 = coefficients.begin(); pos1 != coefficients.end(); pos1++) {
        res.push_back(*pos1 + *pos2);
        pos2++;
    }
    return Polynome(res);
}

template <typename T> Polynome<T> Polynome<T>::mult(Polynome& p1) {
    std::list<T> res;
    auto pos1 = coefficients.begin();
    auto pos2 = p1.coefficients.begin();
    int res_deg = deg + p1.deg;
    T sum;
    for (int i = 0; i <= res_deg; i++) {
        sum = 0;
        for (int j = 0; j <= deg; j++) {
            for (int k = 0; k <= p1.deg; k++) {
                if (i == j + k) {
                    advance(pos1, j);
                    advance(pos2, k);
                    sum += *(pos1) * *(pos2);
                    pos1 = coefficients.begin();
                    pos2 = p1.coefficients.begin();
                }
            }
        }
        res.push_back(sum);
    }
    return Polynome(res);
}

template <typename T> T Polynome<T>::value(T point) {
    unsigned int counter = 0;
    T res = 0, temp = 1;
    for (auto pos = coefficients.begin(); pos != coefficients.end(); pos++) {
        res += (*pos) * temp;
        temp *= point;
    }
    return res;
}

int main() {
    std::list<int> lst1 = {1, 2, 3, 4};
    Polynome<int> p(lst1);
    p.output();
    int res = p.value(1);
    std::cout << res << std::endl;
}
