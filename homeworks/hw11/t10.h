#include <stddef.h>

#pragma once

typedef struct TPair {
    unsigned int key;
    char data[10];
} TPair;

void create_file(char fname[]);

void read_file(char fname[]);

void show_TPair(TPair p);

int search_sorted(char fname[], unsigned int key);

void search_res();

int delete_data(char fname[], unsigned int key);

void delete_res();
