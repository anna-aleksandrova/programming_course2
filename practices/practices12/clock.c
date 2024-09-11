#include <stdio.h>
#include <math.h>

int main(){
    float x;
    int hours, mins;
    printf("x = ");  // the angle in degrees
    scanf("%f", &x);
    hours = (int) x/10;
    hours /= 3;
    mins = (int) x / 6;
    printf("%d:%d", hours, mins);
}