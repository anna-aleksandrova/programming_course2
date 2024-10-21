#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define LEN 255

typedef struct Mountain {
    char name[LEN];
    int height;
} Mountain;

void input(Mountain* mountain) {
    assert(mountain != 0);
    printf("----------\n");
    printf("Enter name : ");
    scanf("%s", mountain -> name);
    printf("Enter height : ");
    scanf("%i", &mountain -> height);
}

void output(Mountain mountain) {
    printf("----------");
    printf("Name : %s", mountain.name);
    printf("Height : %i", mountain.height);
}

char* highest(Mountain** mountains, int n) {
    assert (mountains != 0);
    char* name_max = mountains[0] -> name;
    int max_height = mountains[0] -> height;
    for (int i = 1; i < n; i++) {
        if (mountains[i] -> height > max_height) {
            max_height = mountains[i] -> height;
            name_max = mountains[i] -> name;
        }
    }
    return name_max;
}

int height(Mountain** mountains, char *name, int n) {
    assert(mountains != 0);
    for (int i = 0; i < n; i++) {
        if (!strcmp(mountains[i] -> name, name)) {
            return mountains[i] -> height;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    Mountain** mountains = (Mountain**) malloc(n * sizeof(Mountain*));
    for (int i = 0; i < n; i++) {
        mountains[i] = (Mountain*) malloc(sizeof(Mountain));
        input(mountains[i]);
    }
    printf("\nThe heighest mountain : %s.\n", highest(mountains, n));
    char* name_highest = highest(mountains, n);
    char title[LEN];
    printf("\nA mountain to find (enter name) : ");
    scanf("%s", title);
    int needed_height = height(mountains, title, n);
    if (needed_height == -1) {
        printf("No mountain with such name.\n");
    }
    else {
        printf("Height of the mountain: %i.\n", needed_height);
    }
    free(mountains);
}
