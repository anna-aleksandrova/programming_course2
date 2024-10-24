#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 255

typedef struct Price {
    unsigned long int hrn;
    unsigned int k;
} Price;

void inputPrice(Price* price) {
    printf("Enter the amount of hryvnias : ");
    scanf("%lu", &price -> hrn);
    printf("Enter the amount of kopiykas : ");
    scanf("%u", &price -> k);
}

void outputPrice(Price price) {
    printf("%lu hrn, %u kop.\n", price.hrn, price.k);
}

void task6() {
    Price p;
    inputPrice(&p);
    outputPrice(p);
}

typedef struct Inhabitant {
    char lastname[LEN];
    char firstname[LEN];
    char city[LEN];
    char street[LEN];
    char house[LEN];
    unsigned int flat_number;
} Inhabitant;

void inputInhabitant(Inhabitant* inhabitant) {
    printf("----------\n");
    printf("Enter the first name : ");
    scanf("%s", inhabitant -> firstname);
    printf("Enter the last name : ");
    scanf("%s", inhabitant -> lastname);
    printf("Enter the city : ");
    scanf("%s", inhabitant -> city);
    printf("Enter the street : ");
    scanf("%s", inhabitant -> street);
    printf("Enter the number of the house : ");
    scanf("%s", inhabitant -> house);
    printf("Enter the number of the flat : ");
    scanf("%u", &inhabitant -> flat_number);
}

void outputInhabitant(Inhabitant inhabitant) {
    printf("----------\n");
    printf("First & last name: %s %s\n", inhabitant.firstname, inhabitant.lastname);
    printf("City: %s\n", inhabitant.city);
    printf("Address: %s, %s, %u\n", inhabitant.street, inhabitant.house, inhabitant.flat_number);
}

int* search(Inhabitant* array, unsigned int n) {
    for (int i = 0; i < n; i++) {
        char* city = array[i].city;
        char* street = array[i].street;
        char* house = array[i].house;
        unsigned int flat = array[i].flat_number;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(city, array[j].city) && !strcmp(street, array[j].street) && !strcmp(house, array[j].house) && flat == array[j].flat_number) {
                int* res = (int*) malloc(2 * sizeof(int));
                res[0] = i;
                res[1] = j;
                return res; 
            }
        }
    }
    int* res = (int*) malloc(sizeof(int));
    res[0] = -1;
    return res;
}

void task11() {
    unsigned int n;
    printf("Enter the size of the array: ");
    scanf("%u", &n);
    Inhabitant* P = (Inhabitant*) malloc(n * sizeof(Inhabitant));
    for (int i = 0; i < n; i++) {
        Inhabitant person;
        inputInhabitant(&person);
        P[i] = person;
    }
    int* res = search(P, n);
    if (res[0] == -1) {
        printf("\nNo people who have the same street adress, but live in different cities.\n");
    }
    else {
        printf("\nPeople who have the same street address but live in different cities:\n");
        outputInhabitant(P[res[0]]);
        outputInhabitant(P[res[1]]);
    }
    free(P);
    free(res);
}

int main() {
    task11();
}
