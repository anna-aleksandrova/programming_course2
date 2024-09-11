#include <stdio.h>

int main(){
    int a, i;
    printf("Enter a: ");
    scanf("%d", &a);
    for( i = 0; i < 3; i += 1){
        printf("- %d ", a);
    }
    printf("\n");
    for ( i = 0; i < 2; i += 1){
        printf("%d | ", a);
    }
    printf("%d\n", a);
    for( i = 0; i < 3; i += 1){
        printf("- %d ", a);
    }
    printf("\n");
}