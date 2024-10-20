#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

void inputDate (Date *d) {
    printf("Year: ");
    scanf("%d", &d -> year);
    printf("Month: ");
    scanf("%d", &d -> month);
    printf("Day: ");
    scanf("%d", &d -> day);
}

void outputDate(Date *d) {
    printf("%d.%d.%d\n", d -> day, d -> month, d -> year);
}

typedef struct Square {
    char row;
    unsigned int column;
} Square;

void inputSquare(Square *s) {
    printf("Row: ");
    scanf("%c", &(s -> row));
    printf("Column: ");
    scanf("%u", &(s -> column));
    assert(s -> row >= 'a' && s -> row <= 'h' || s -> column >= 1 && s -> column <= 8);
}

void outputSquare(Square *s) {
    printf("Square: %c%d\n", s -> row, s -> column);
}

typedef struct Vertex {
    long double x;
    long double y;
} Vertex;

void inputVertex(Vertex* v) {
    printf("x : ");
    scanf("%Lf", &v -> x);
    printf("y : ");
    scanf("%Lf", &v -> y);
}

void outputVertex (Vertex v) {
    printf("(%Lg, %Lg)\n", v.x, v.y);
}

typedef struct Rectangle {
    Vertex v1;
    Vertex v2;
} Rectangle;

void inputRectangle(Rectangle* r) {
    Vertex* ptr_v1 = &r -> v1;
    Vertex* ptr_v2 = &r -> v2;
    printf("Enter v1 :\n");
    inputVertex(ptr_v1);
    printf("Enter v2 :\n");
    inputVertex(ptr_v2);
}

void outputRectangle (Rectangle r) {
    outputVertex(r.v1);
    outputVertex(r.v2);
}

typedef struct Poly {
    unsigned int n;
    double *a;
} Poly;

int inputPoly(Poly *p) {
    printf("n = ");
    scanf("%d", &(p -> n));
    p -> a = (double*) calloc((p -> n) + 1, sizeof(*(p -> a)));
    for (unsigned i = 0; i < (p -> n) + 1; i++) {
        printf("a[%i] : ", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void output_Poly(Poly p) {
    printf("%g + ", p.a[0]);
    for (int i = 1; i < p.n; i++) {
        printf("%g * x ^ %i + ", p.a[i], i);
    }
    printf("%g * x ^ %i", p.a[p.n], p.n);
}

void deletePoly(Poly *p) {
    if (p -> a) {
        free(p -> a);
    }
}

void task1() {
    Date *date = (Date*) malloc(sizeof(Date));
    inputDate(date);
    outputDate(date);
    free(date);
    Square* square = (Square*) malloc(sizeof(Square));
    inputSquare(square);
    outputSquare(square);
    free(square);
    Rectangle r;
    Rectangle* ptr_r = &r;
    inputRectangle(ptr_r);
    outputRectangle(*ptr_r);
    Poly p;
    Poly* ptr_p = &p;
    inputPoly(ptr_p);
    output_Poly(p);
    deletePoly(ptr_p);
}

bool hitQueen(Square f1, Square f2) {
    return (f1.row == f2.row) || (f1.column == f2.column) || (fabs(f1.column - f2.column) == fabs(f1.row - f1.row));
}

void task2() {
    Square s1, s2;
    Square* ptr_s1 = &s1;
    Square* ptr_s2 = &s2;
    printf("Enter current position of the queen:\n");
    inputSquare(ptr_s1);
    printf("Enter the position to check:\n");
    inputSquare(ptr_s2);
    printf("Possible for the queen to go from %c%d to %c%d : %d\n", s1.row, s1.column, s2.row, s2.column, hitQueen(s1, s2));
}

bool is_leap(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0 & year % 4 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

void task3() {
    int MONTH_DAY[12];
    Date date;
    Date* ptr_date = &date;
    inputDate(ptr_date);
    if (is_leap(date.year)) {
        int MONTH_DAY[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }
    else {
        int MONTH_DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }
    if (date.day > MONTH_DAY[date.month - 1] || date.day < 0 || date.month < 0 || date.month > 12) {
        printf("Incorrect date.\n");
    }
    else {
        Date tomorrow_date;
        if (date.day == 31 && date.month == 12) {
            tomorrow_date.year = date.year + 1;
            tomorrow_date.month = 1;
            tomorrow_date.day = 1;
        }
        else if (date.day == MONTH_DAY[date.month - 1]) {
            tomorrow_date.day = 1;
            tomorrow_date.month = date.month + 1;
            tomorrow_date.year = date.year;
        }
        else {
            tomorrow_date.day = date.day + 1;
            tomorrow_date.month = date.month;
            tomorrow_date.year = date.year;
        }
        Date* ptr_tomorrow_date = &tomorrow_date;
        outputDate(ptr_tomorrow_date);
    }
}

int main() {
    task3();
}
