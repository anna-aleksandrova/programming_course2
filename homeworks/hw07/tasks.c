#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 30

void input_array(size_t size, unsigned int array[]) {
    for (int i = 0; i < size; i++) {
        printf("el[%i] : ", i + 1);
        scanf("%u", array + i);
    }
}

void input_int_array(size_t size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("el[%i] : ", i + 1);
        scanf("%i", array + i);
    }
}

void output_int_array(size_t size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
}

int is_perfectsquare(unsigned int n) {
    unsigned int temp = (unsigned int) sqrt(n);
    if (temp * temp == n) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_fibonacci(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    unsigned int temp = 5 * n * n;
    if (is_perfectsquare(temp + 4) || is_perfectsquare(temp - 4)) {
        return 1;
    }
    else {
        return 0;
    }
}

void task8() {
    size_t n;
    printf("Size of the array : ");
    scanf("%zu", &n);
    unsigned int array[SIZE], counter = 0;
    input_array(n, array);
    for (int i = 0; i < n; i++) {
        if (is_fibonacci(array[i])) {
            counter++;
        }
    }
    printf("The number of Fibonacci numbers in the array : %i.\n", counter);
}

int in_array(int el, size_t size, int array[]) {
    for (int i = 0; i < size; i++) {
        if (array[i] == el) {
            return 1;
        }
    }
    return 0;
}

void task12() {
    size_t n;
    printf("Size of the array : ");
    scanf("%zu", &n);
    int array[SIZE];
    input_int_array(n, array);
    unsigned int counter = 0, max_counter = 0, k = 0;
    int *modes = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[j] == array[i]) {
                counter++;
            }
        }
        if (counter == max_counter) {
            if (modes) {
                if (in_array(array[i], k, modes)) {
                    ;
                }
                else {
                    *(modes + k) = array[i];
                    k++;
                }
            }
        }
        if (counter > max_counter) {
            max_counter = counter;
            free(modes);
            int *modes = (int*) malloc(n * sizeof(int));
            if (modes) {
                k = 0;
                modes[k] = array[i];
                k++;
            }
        }
        counter = 0;
    }
    printf("Modes of the array : ");
    output_int_array(k, modes);
    printf("\n");
}

int main() {
    task12();
}
