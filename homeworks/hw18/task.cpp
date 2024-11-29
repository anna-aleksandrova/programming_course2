#include <iostream>

template <class T> class Array {
    public:
        Array(T* array_, size_t size_) {
            size = size_;
            array = array_;
        }
        void bubble_sort();
        static void bubble_sort(T* array, size_t size) {
            bool check = false;
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (array[j] > array[j+1]) {
                        std::swap(array[j], array[j+1]);
                        check = true;
                    }
                }
                if (check == false) {break;}
            }
        }
        T operator[](unsigned int i) {return array[i];}
    private:
        size_t size;
        T* array;
};

template <class T> void Array<T>::bubble_sort() {
    bool check = false;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                std::swap(array[j], array[j+1]);
                check = true;
            }
        }
        if (check == false) {break;}
    }
}

int main() {
    double a[5] {5.67, 4.63, 0, -1, -0.5};
    double* array = a;
    Array<double>::bubble_sort(array, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
