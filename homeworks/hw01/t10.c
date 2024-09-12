#include <stdio.h>

int main(){
    int i1, i2, i3, i4, i5;
    double r1, r2, r3, r4, r5;
    printf("Enter 5 integers: ");
    scanf("%i %i %i %i %i", &i1, &i2, &i3, &i4, &i5);
    printf("Enter 5 real numbers: ");
    scanf("%lf %lf %lf %lf %lf", &r1, &r2, &r3, &r4, &r5);
    printf("x | %d | %d | %d | %d | %d |\n", i1, i2, i3, i4, i5);
    for (int i = 0; i < 6; i++){
        printf(" -- |");
    }
    printf("\ny | %g | %g | %g | %g | %g |\n", r1, r2, r3, r4, r5);
}
