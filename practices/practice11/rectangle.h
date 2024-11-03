#include <stddef.h>

#pragma once

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Rectangle {
    int number;
    Point v1;
    Point v2;
} Rectangle;

void create_file(char fname[]);

void show_rectangle(Rectangle r);

void read_file(char fname[]);

double area(Rectangle r);

int* max_area(char fname[]);

void rectangles_max_area(char fname[]);

void delete_rectangle(char fname[], int k);

void replace_rectangle(char fname[], int k, Rectangle r);
