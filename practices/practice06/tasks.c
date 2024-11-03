#include <stdio.h>

void task1() {
    __uint8_t n;
    printf("n = ");
    scanf("%hhu", &n);
    unsigned long long m = 1 << n;
    printf("%llu\n", m);
}

void task2() {
    int n, res;
    unsigned int k;
    printf("n = ");
    scanf("%i", &n);
    printf("k = ");
    scanf("%u", &k);
    res = n | (1 << k);
    printf("%i\n", res);
}

void task3() {
    __uint32_t m;
    unsigned int res, j;
    printf("m = ");
    scanf("%u", &m);
    printf("j = ");
    scanf("%u", &j);
    res = m & ~(1 << j);   
    printf("%u\n", res);
    printf("%x\n", res);     
}

void task4() {
    __uint32_t n;
    int b1, b2, b3, b4, m;
    scanf("%u", &n);
    b1 = n & 0xFF;
    b2 = (n >> 8) & 0xFF;
    b3 = (n >> 16) & 0xFF;
    b4 = n >> 24;
    m = (b1 << 24) | (b3 << 16) | (b2 << 8) | b4;
    printf("%u\n", m);
    printf("%x\n", m);
}

void task5() {
    unsigned int n, counter = 0, max = 0, temp;
    printf("n = ");
    scanf("%i", &n);
    while (n) {
        if (n & 1) {
            counter += 1;
        }
        else {
            if (counter > max) {
                max = counter;
            }
            counter = 0;
        }
        n = n >> 1;
    }
    printf("%u\n", max);
}

void task6a() {
    int i, aux;
    for (i = 1; i < 1 << (16 - 1); i++) {
        aux = i & (i - 1);
        printf("%i\n", aux == 0? 0: 1);
    }
    printf("res = x & (x - 1) : res == 0 if and only if x is a power of 2.\n");
}

void task6b() {
    int i, res;
    for (i = 1; i < 1 << (16 - 1); i++) {
        res = i & (-i);
        printf("%i\n", res);
    }
    printf("x & (-x) shows the lowest bit in <x>.\n");
}

void task7() {
    if (2864434397 == 0xaabbccdd) {
        printf("Your computer has big-endian system.\n");
    }
    else if (2864434397 == 0xddccddaa) {
        printf("Your computer has little-endian system.\n");
    }
    else {
        printf("Your computer has middle-endian system.\n");
    }
}

int main() {
    task7();
}
