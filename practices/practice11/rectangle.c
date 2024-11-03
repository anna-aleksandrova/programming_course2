#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "rectangle.h"

#define LEN 30
#define AMOUNT 100

void create_file(char fname[]) {
    FILE *fp = fopen(fname, "wr");
    Rectangle r;
    int i = 0;
    char ans;
    while (1) {
        printf("Enter a rectangle: \n");
        printf("Left upper vertice (x, y): ");
        scanf("%lf %lf", &r.v1.x, &r.v1.y);
        printf("Right lower vertice (x, y): ");
        scanf("%lf %lf", &r.v2.x, &r.v2.y);
        r.number = i;
        fwrite(&r, sizeof(r), 1, fp);
        i++;
        while (1) {
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

void show_rectangle(Rectangle r) {
    printf("Rectangle: number = %i, (x1, y1) = (%g, %g), (x2, y2) = (%g, %g)\n", r.number, r.v1.x, r.v1.y, r.v2.x, r.v2.y);
}

void read_file(char fname[]) {
    FILE *fp = fopen(fname, "rb");
    Rectangle current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Rectangle), 1, fp)) {
            show_rectangle(current);
        }
    }
}

double area(Rectangle r) {
    return fabs(r.v1.x - r.v2.x) * fabs(r.v1.y - r.v2.y);
}

int* max_area(char fname[]) {
    FILE *fp = fopen(fname, "rb");
    int* res = (int*) malloc(AMOUNT * sizeof(int));
    int k = 1;
    double max = 0, cur_area;
    Rectangle current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Rectangle), 1, fp)) {
            cur_area = area(current);
            if (cur_area == max) {
                res[k] = current.number;
                k++;
            }
            else if (cur_area > max) {
                max = cur_area;
                free(res);
                res = (int*) malloc(AMOUNT * sizeof(int));
                res[1] = current.number;
                k = 2;
            }
            else {
                ;
            }
        }
    }
    res[0] = k - 1;
    return res;
}

void rectangles_max_area(char fname[]) {
    int* res = max_area(fname);
    printf("Numbers of rectangles from file <%s> which have maximum area: ", fname);
    for (int i = 1; i <= res[0]; i++) {
        printf("%i ", res[i]);
    }
    printf("\n");
    free(res);
}


void delete_rectangle(char fname[], int k) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = tmpfile();
    Rectangle r;
    int check = 0;
    while(!feof(fp)) {
        if (fread(&r, sizeof(Rectangle), 1, fp)) {
            if (r.number + 1 != k && !check) {
                fwrite(&r, sizeof(Rectangle), 1, gp);
            }
            else if (r.number + 1 != k && check) {
                r.number--; 
                fwrite(&r, sizeof(Rectangle), 1, gp);
            }
            else {
                check = 1;
            }
        }
    }
    fclose(fp);
    fseek(gp, 0*sizeof(Rectangle), SEEK_SET);
    fp = fopen(fname, "wb");
    while(!feof(gp)) {
        if (fread(&r, sizeof(Rectangle), 1, gp)) {
            fwrite(&r, sizeof(Rectangle), 1, fp);
        }
    }
    fclose(fp);
    fclose(gp);
    if (check) {
        printf("Rectangle with the number %i (mathematical counting) was successfully deleted.\n", k);
    }
    else {
        printf("There is no rectangle with the number %i in file <%s>.\n", k, fname);
    }
}

void replace_rectangle(char fname[], int k, Rectangle r) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = tmpfile();
    int check = 0;
    Rectangle current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(Rectangle), 1, fp)) {
            if (current.number + 1 == k) {
                check = 1;
                fwrite(&r, sizeof(Rectangle), 1, gp);
            }
            else {
                fwrite(&current, sizeof(Rectangle), 1, gp);
            }
        }
    }
    fclose(fp);
    fseek(gp, 0*sizeof(Rectangle), SEEK_SET);
    fp = fopen(fname, "wb");
    while(!feof(gp)) {
        if (fread(&current, sizeof(Rectangle), 1, gp)) {
            fwrite(&current, sizeof(Rectangle), 1, fp);
        }
    }
    fclose(fp);
    fclose(gp);
    if (check) {
        printf("Rectangle with the number %i (mathematical counting) was successfully replaced.\n", k);
    }
    else {
        printf("There is no rectangle with the number %i in file <%s>.\n", k, fname);
    }
}

int main() {
    char fname[LEN] = "t04.txt";
    create_file(fname);
    printf("\n");
    printf("Data in the file before modification: \n");
    read_file(fname);

    printf("----------\n");
    rectangles_max_area(fname);

    printf("----------\n");
    delete_rectangle(fname, 2);
    printf("Data in the file after deletion: \n");
    read_file(fname);
    
    printf("----------\n");
    Point v1 = {1, 2};
    Point v2 = {3, 1};
    Rectangle r = {2, v1, v2};
    replace_rectangle(fname, 3, r);
    printf("Data in the file after modification: \n");
    read_file(fname);
}
