#include <stddef.h>
#define LEN 30

#pragma once

typedef struct Passenger {
    unsigned int number;
    char lastname[LEN];
    char firstname[LEN];
} Passenger;

typedef struct Package {
    unsigned int owner_number;
    unsigned int amount;
    unsigned int total_weight;
} Package;

void create_file_passengers(char fname[]);

void create_file_packages(char fname[]);

void show_passenger(Passenger p);

void show_package(Package p);

void read_file_passengers(char fname[]);

void read_file_packages(char fname[]);

int* package_conditions(char fname[]);

int in_array(int* array, int k);

void search_passengers(char fname[], int* numbers);

