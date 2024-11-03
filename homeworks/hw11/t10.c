#include <stdio.h>
#include <math.h>
#include "t10.h"

#define LEN 30

void create_file(char fname[]) {
    FILE *fp = fopen(fname, "wb");
    TPair current;
    char ans;
    while(1) {
        printf("Enter a pair (key, data): \n");
        printf("Key: ");
        scanf("%u", &current.key);
        printf("Data: ");
        scanf("%s", current.data);
        fwrite(&current, sizeof(TPair), 1, fp);
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

void show_TPair(TPair p) {
    printf("TPair: key = %u, data = %s\n", p.key, p.data);
}

void read_file(char fname[]) {
    FILE *fp = fopen(fname, "rb");
    TPair current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(TPair), 1, fp)) {
            printf("TPair: key = %u, data = %s\n", current.key, current.data);
        }
    }
    fclose(fp);
}

int size_fTPair(FILE* fp) {
    TPair current;
    int size = 0;
    while (!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            size++;
        }
    }
    return size;
}

int search_sorted(char fname[], unsigned int needed) {
    FILE *fp = fopen(fname, "rb");
    int res = 0;
    TPair current;
    int start = 0, end = size_fTPair(fp);
    while (1) {
        int pivot = (end - start) / 2;
        fseek(fp, pivot*sizeof(TPair), SEEK_SET);
        fread(&current, sizeof(TPair), 1, fp);
        unsigned int temp = current.key;
        if (fabs(end - start) == 1) {
            if (temp == needed) {
                show_TPair(current);
                res = 1;
                break;
            }
        }
        else {
        if (temp > needed) {
            end = pivot;
        }
        else if (temp < needed) {
            start = pivot;
        }
        else {
            printf("Data with the key <%u>:\n", needed);
            show_TPair(current);
            res = 1;
            break;
        } 
        }   
    }
    fclose(fp);
    return res;
}

void search_res() {
    char fname[LEN];
    unsigned int key;
    printf("Enter a name of the file to search in: ");
    scanf("%s", fname);
    printf("Enter a key to search: ");
    scanf("%u", &key);
    int res = search_sorted(fname, key);
    if (res == 1) {
        printf("The search was successful.\n");
    }
    else {
        printf("No data in file <%s> with key <%u>.\n", fname, key);
    }
}

int delete_data(char fname[], unsigned int needed) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = tmpfile();
    int res = 0;
    TPair current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(TPair), 1, fp)) {
            if (current.key == needed) {
                res = 1;
            }
            else {
                fwrite(&current, sizeof(TPair), 1, gp);
            }
        }
    }
    fclose(fp);
    if (res) {
        fp = fopen(fname, "wb");
        fseek(gp, 0*sizeof(TPair), SEEK_SET);
        while(!feof(gp)) {
            if (fread(&current, sizeof(TPair), 1, gp)) {
                fwrite(&current, sizeof(TPair), 1, fp);
            }
        }
        fclose(fp);
    }
    fclose(gp);
    return res;
}

void delete_res() {
    char fname[LEN];
    unsigned int key;
    printf("Enter a name of the file to delete the data in: ");
    scanf("%s", fname);
    printf("Enter a key to delete: ");
    scanf("%u", &key);
    int res = delete_data(fname, key);
    if (res == 1) {
        printf("The deletion was successful.\n");
    }
    else {
        printf("No data in file <%s> with key <%u>.\n", fname, key);
    }
}

int main() {
    char fname[LEN];
    printf("Enter a name of the file which will be created: ");
    scanf("%s", fname);
    create_file(fname);
    printf("----------\n");
    printf("Data in the file <%s>:\n", fname);
    read_file(fname);
    
    printf("----------\n");
    search_res();

    printf("----------\n");
    delete_res();
    printf("Data in the file <%s> after deletion:\n", fname);
    read_file(fname);
}
