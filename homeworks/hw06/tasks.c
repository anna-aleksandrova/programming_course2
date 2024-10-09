#include <stdio.h>

void task9() {
    long long unsigned int m;
    unsigned int counter = 1;
    long long unsigned int aux = 1UL << 63;
    printf("m = ");
    scanf("%llu", &m);
    while (m) {
        if (m & aux) {
            printf("The number of the most significant bit = %u.\n", counter);
            break;
        }
        else {
            m = m << 1;
            counter += 1;
        }
    }
    while (m) {
        if (m & aux) {
            m = m << 1;
            counter += 1;
        }
        else {
            printf("The number of the first zero bit which comes after the most significant bit = %u.\n", counter);
            break;
        }
    }
    if (counter == 64) {
        printf("The number of the first zero bit which comes after the most significant bit = 64.\n");
    }
    if (counter > 64) {
        printf("No zero bits after the most significant bit.\n");
    }
}

void task24() {
    __uint32_t m;
    unsigned int counter = 1;
    unsigned int aux = 1 << 31;
    printf("m = ");
    scanf("%u", &m);
    __uint32_t m1 = m;
    while (m1) {
        if (m1 & aux) {
            printf("The number of the most significant bit = %u.\n", counter);
            break;
        }
        else {
            m1 = m1 << 1;
            counter += 1;
        }
    }
    if (!m1) {
        printf("There is no most significant bit in 0.\n");
    }
    counter = 0;
    while (m) {
        if (m & 1) {
            printf("The number of the least significant bit = %u.\n", counter);
            break;
        }
        else {
            m = m >> 1;
            counter += 1;
        }
    }
    if (!m) {
        printf("There is no least significant bit in 0.\n");
    }
}

int main() {
    task24();
}
