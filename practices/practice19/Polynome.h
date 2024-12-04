#pragma once
#include <iostream>
#include <list>

template <typename T> class Polynome {
    public:
        Polynome(){};
        Polynome(std::list<T>& c);
        Polynome<T> add(Polynome& p1);
        Polynome<T> mult(Polynome& p1);
        T value(T point);
        void input();
        void output();
    private:
        std::list<T> coefficients;
        int deg;
};
