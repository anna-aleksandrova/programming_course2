#include <stdio.h>

void output_array(unsigned int array[], size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%u", array[i]);
    }
}

int next(unsigned int array[], size_t n) {
    if (array[0] == 1) {
        for (int i = 1; i < n; i++) {
            if (array[i] == 1) {
                return 1;
            }
        }
        return 0;
    }
    else {
        return 1;
    }
}

int sum_array(unsigned int array[], size_t n) {
    unsigned int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

unsigned int rightmost_one(unsigned int array[], size_t n) {
    for (int i = n - 1; i > 0; i--) {
        if (array[i] == 1) {
            return i;
        }
    }
}

void gray_code(const unsigned int n) {
    unsigned int current[n];
    for (int i = 0; i < n; i++) {
        current[i] = 0;
    }
    output_array(current, n);
    printf("\n");
    while (next(current, n)) {
        unsigned int sum = sum_array(current, n);
        if (sum % 2 == 0) {
            current[n - 1] = !(current[n - 1]);
        }
        else {
            unsigned int needed_position = rightmost_one(current, n) - 1;
            current[needed_position] = !(current[needed_position]);
        }
        output_array(current, n);
        printf("\n");
    }
}

int main() {
    unsigned int n;
    printf("The order of Gray code : ");
    scanf("%u", &n);
    gray_code(n);
}
