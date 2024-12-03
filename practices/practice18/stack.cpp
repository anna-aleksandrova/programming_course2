#include <iostream>
#include <stack>
#include <cmath>

#define LEN 100

template <typename T> size_t input_array(T *array) {
    T temp;
    size_t i = 0;
    while (temp != 0) {
        std::cout << "element: ";
        std::cin >> temp;
        if (fabs(temp) < __DBL_EPSILON__) {break;}
        else {
            array[i] = temp;
            i++;
        }
    }
    return i;
}

template <class T> class Stack {
    public:
        Stack() {
            size = LEN;
            stack = new T[size];
        }
        ~Stack() {delete[] stack;}
        int push(T el);
        void input_stack();
        T pop();
        T peek();
        bool is_empty();
    private:
        T *stack;
        unsigned int size; 
        int current_am = -1;
};

template <class T> int Stack<T>::push(T el) {
    try {
        if (current_am == size) {throw std::runtime_error("Error: stack overflow.");}
        else {
            current_am++;
            stack[current_am] = el;
            return 0;
        }
    }
    catch(std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}

template <class T> bool Stack<T>::is_empty() {
    if (current_am == -1) {return true;}
    else {return false;}
}

template <class T> T Stack<T>::pop() {
    try {
        if (this->is_empty()) {throw std::runtime_error("Error: stack is empty");}
        else {return stack[current_am--];}
    }
    catch (std::runtime_error& e) {std::cout << e.what() << std::endl;}
}

template <class T> T Stack<T>::peek() {
    try {
        if (this->is_empty()) {throw std::runtime_error("Error: stack is empty");}
        else {return stack[current_am];}
    }
    catch (std::runtime_error& e) {std::cout << e.what() << std::endl;}
}


template <class T> void Stack<T>::input_stack() {
    T temp;
    unsigned int counter = -1, check;
    std::string answer;
    while (answer != "n") {
        std::cout << "element: ";
        std::cin >> temp;
        check = this -> push(temp);
        if (check == 1) {break;}
        std::cout << "Continue entering[y/n]: ";
        std::cin >> answer;
    }
}

int main()  {
    Stack<double> stack;
    stack.input_stack();
}
