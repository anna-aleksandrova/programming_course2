#include <stdio.h>

int main() {
    char a11, a12, a13, a21, a22, a23, a31, a32, a33;
    printf("Enter \"O\"'s and \"X\"'s configuration: ");
    scanf("%c %c %c %c %c %c %c %c %c", &a11, &a12, 
            &a13, &a21, &a22, &a23, &a31, &a32, &a33);
    printf(" %c | %c | %c\n", a11, a12, a13);
    printf(" %c | %c | %c\n", a21, a22, a23);
    printf(" %c | %c | %c\n", a31, a32, a33);
}
