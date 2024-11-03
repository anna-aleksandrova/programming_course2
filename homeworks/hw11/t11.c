#include <stdio.h>
#include <stdlib.h>
#include "t11.h"

#define LEN 30
#define AMOUNT 100

void create_file_passengers(char fname[]) {
    FILE *fp = fopen(fname, "wb");
    Passenger current;
    char ans;
    while(1) {
        printf("Enter a passenger: \n");
        printf("Last name: ");
        scanf("%s", current.lastname);
        printf("First name: ");
        scanf("%s", current.firstname);
        printf("Number: ");
        scanf("%u", &current.number);
        fwrite(&current, sizeof(Passenger), 1, fp);
        while(1) {
            printf("Continue[y/n]: ");
            scanf(" %c", &ans);
            if (ans != 'y' && ans != 'n') {
                printf("Wrong format.\n");
            }
            else {
                break;
            }
        }
        if (ans == 'n') {
            break;
        }
    }
    fclose(fp);
}

void create_file_packages(char fname[]) {
    FILE *fp = fopen(fname, "wb");
    Package current;
    char ans;
    while(1) {
        printf("Enter a package: \n");
        printf("Owner's number: ");
        scanf("%u", &current.owner_number);
        printf("Amount: ");
        scanf("%u", &current.amount);
        printf("Total weight: ");
        scanf("%u", &current.total_weight);
        fwrite(&current, sizeof(Package), 1, fp);
        while(1) {
            printf("Continue[y/n]: ");
            scanf(" %c", &ans);
            if (ans != 'y' && ans != 'n') {
                printf("Wrong format.\n");
            }
            else {
                break;
            }
        }
        if (ans == 'n') {
            break;
        }
    }
    fclose(fp);
}

void show_passenger(Passenger p) {
    printf("Passenger: number = %u, name: %s %s\n", p.number, p.lastname, p.firstname);
}

void show_package(Package p) {
    printf("Package: owner_number = %u, amount = %u, total_weight = %u\n", p.owner_number, p.amount, p.total_weight);
}

void read_file_passengers(char fname[]) {
    FILE *fp = fopen(fname, "rb");
    Passenger current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Passenger), 1, fp)) {
            show_passenger(current);
        }
    }
    fclose(fp);
}

void read_file_packages(char fname[]) {
    FILE *fp = fopen(fname, "rb");
    Package current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Package), 1, fp)) {
            show_package(current);
        }
    }
    fclose(fp);
}

int* package_conditions(char fname[]) {
    int* first_condition = (int*) malloc(AMOUNT * sizeof(int));
    int max_amount = 0;
    int k = 1;
    FILE *fp = fopen(fname, "rb");
    Package current;
    while(!feof(fp)) {
        if(fread(&current, sizeof(Package), 1, fp)) {
            if (current.amount == max_amount) {
                first_condition[k] = current.owner_number;
                k++;
            }
            else if (current.amount > max_amount) {
                max_amount = current.amount;
                free(first_condition);
                first_condition = (int*) malloc(AMOUNT * sizeof(int));
                first_condition[1] = current.owner_number;
                k = 2;
            }
            else {;}
        }
    }
    first_condition[0] = k - 1;
    
    fseek(fp, 1*sizeof(Package), SEEK_SET);
    fread(&current, sizeof(Package), 1, fp);
    int min_weight = current.total_weight;
    fseek(fp, 0*sizeof(Package), SEEK_SET);
    int* conditions = (int*) malloc(AMOUNT*sizeof(int));
    int m = 1;
    while(!feof(fp)) {
        if(fread(&current, sizeof(Package), 1, fp)){
            if (in_array(first_condition, current.owner_number)) {
                if (current.total_weight == min_weight) {
                    conditions[m] = current.owner_number;
                    m++;
                }
                else if (current.total_weight < min_weight) {
                    min_weight = current.total_weight;
                    free(conditions);
                    conditions = (int*) malloc(AMOUNT*sizeof(int));
                    conditions[1] = current.owner_number;
                    m = 2;
                }
                else {;}
            }
        }
    }
    conditions[0] = m - 1;
    free(first_condition);
    fclose(fp);
    return conditions;
}

int in_array(int* array, int k) {
    for (int i = 1; i <= array[0]; i++) {
        if (array[i] == k) {
            return 1;
        }
    }
    return 0;
}

void search_passengers(char fname[], int* numbers) {
    FILE *fp = fopen(fname, "rb");
    Passenger current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Passenger), 1, fp)) {
            if (in_array(numbers, current.number)) {
                show_passenger(current);
            }
        }
    }
    free(numbers);
    fclose(fp);
}

int main() {
    char fpassengers[LEN], fpackages[LEN];
    printf("Enter a name of the file with passengers to create: ");
    scanf("%s", fpassengers);
    create_file_passengers(fpassengers);
    printf("-----------\nData in the file <%s>:\n", fpassengers);
    read_file_passengers(fpassengers);
    
    printf("\n");
    printf("Enter a name of the file with packages to create: ");
    scanf("%s", fpackages);
    create_file_packages(fpackages);
    printf("-----------\nData in the file <%s>:\n", fpackages);
    read_file_packages(fpackages);

    printf("------------\n");
    printf("Passengers whose package satisfies the conditions:\n");
    search_passengers(fpassengers, package_conditions(fpackages));
}
