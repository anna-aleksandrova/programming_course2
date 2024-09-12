#include <stdio.h>

int main(){
    double T = 365 + 1 / (4 + 1 / (7 + 1 / (1 + (float)1 / 3)));
    printf("Approximated period of rotation of the Earth = %f", T);
}
