#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define LEN 30

double* input_array(size_t n) {
    double* array = (double*) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        printf("array[%d] : ", i + 1);
        scanf("%lf", &array[i]);
    }
    return array;
}

void output_array(double* array, size_t n, char sep) {
    assert(array != 0);
    for (int i = 0; i < n - 1; i++) {
        printf("%g%c ", array[i], sep);
    }
    printf("%g\n", array[n - 1]);
}

void write_array(char* filename, double* array, size_t n) {
    assert(filename != 0);
    assert(array != 0);
    FILE* file = fopen(filename, "w");
    fwrite(array, sizeof(double), n, file);
    fclose(file);
}

double* read_array(char* filename) {
    assert(filename != 0);
    FILE* file = fopen(filename, "r");
    double* array = (double*) malloc(LEN * sizeof(double));
    int i = 0;
    while(!feof(file)) {
        fread(&array[i], sizeof(double), 1, file);
        i++;
    }
    fclose(file);
    return array;
}

void task1() {
    char filename[LEN];
    printf("Enter a name of the file : ");
    scanf("%s", filename);
    unsigned int n;
    printf("Enter a size of the array : ");
    scanf("%u", &n);
    double* array = input_array(n);
    write_array(filename, array, n);
    array = read_array(filename);
    output_array(array, n, ',');
    free(array);
}

void create_file(char fname[], int choice) {
    if (choice == 2){
        FILE *fp = fopen(fname, "wb");
        double current;
        char ans;
        while (1) {
            printf("Enter a component of the file (a real number): ");
            scanf("%lf", &current);
            fwrite(&current, sizeof(current), 1, fp);
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
    else if (choice == 3) {
        FILE *fp = fopen(fname, "wb");
        int current;
        while(1) {
            printf("Enter a component of the file (an integer): ");
            scanf("%i", &current);
            if (current == 0) {
                break;
            }
            fwrite(&current, sizeof(current), 1, fp);
        }
        fclose(fp);
    }
    else {
        ;
    }
}

void read_file(char fname[], int choice) {
    if (choice == 2) {
        FILE *fp = fopen(fname, "rb");
        double current;
        while(!feof(fp)) {
            if (fread(&current, sizeof(current), 1, fp)) {
                printf("%g ", current);
            }
        }
        printf("\n");
        fclose(fp);
    }
    else if (choice == 3) {
        FILE *fp = fopen(fname, "rb");
        int current;
        while(!feof(fp)) {
            if (fread(&current, sizeof(current), 1, fp)) {
                printf("%i ", current);
            }
        }
        printf("\n");
        fclose(fp);
    }
}

void add_fabs_less(char fname[], char gname[], double a) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    assert(fp);
    assert(gp);
    double current;
    while(!feof(fp)) {
        if(fread(&current, sizeof(current), 1, fp)) {
            if (fabs(current) < a) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
    printf("Result successfully saved in file <%s>\n", gname);
}

void del_fabs_less(char fname[], double a) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = tmpfile();
    double current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (fabs(current) >= a) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fseek(gp, 0*sizeof(double), SEEK_SET);
    fp = fopen(fname, "wb");
    while(!feof(gp)) {
        if (fread(&current, sizeof(current), 1, gp)) {
            fwrite(&current, sizeof(current), 1, fp);
        }
    }
    fclose(fp);
    fclose(gp);
    printf("File <%s> is modified successfully.\n", fname);
}

void task2() {
    printf("-------Create a file with real components-------\n");
    char fname[LEN];
    printf("Enter a name of the file which will be created: ");
    scanf("%s", fname);
    create_file(fname, 2);

    double a;
    while (1) {
        printf("Enter a number to compare with: a = ");
        scanf("%lf", &a);
        if (a <= 0) {
            printf("Wrong value: <a> must be a positive real number.\n");
        }
        else {
            break;
        }
    }
    char gname[LEN] = "G.txt";
    add_fabs_less(fname, gname, a);
    printf("Data in file <%s>: ", fname);
    read_file(fname, 2);
    printf("Data in file <%s>: ", gname);
    read_file(gname, 2);

    del_fabs_less(fname, a);
    printf("Data in file <%s> after modification: ", fname);
    read_file(fname, 2);
}

void even(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (current % 2 == 0) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

int is_power_3(int n) {
    if (n <= 0) {
        return 0;
    }
    else {
        while (n != 1) {
            if (n % 3 != 0) {
                return 0;
            }
            n /= 3;
        }
        return 1;
    }
}

void powers_of_3(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (is_power_3(current)) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

int is_perfect_square(int n) {
    if (n < 0) {
        return 0;
    }
    int temp = (int) sqrt(n);
    return (temp * temp == n);
}

void perfect_squares(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (is_perfect_square(current)) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

int divisors(int n) {
    n = fabs(n);
    int counter = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            counter++;
        }
    }
    if (n != 0) {
        return 2 * (counter + 1);
    }
    else {
        return counter;
    }
}

void amount_divisors(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (divisors(current) == 3) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

int is_palindrome(int n) {
    if (n == 0) {
        return 1;
    }
    n = fabs(n);
    int aux = n;
    int len = (int) (log10(n));
    int res = 0;
    while(aux != 0) {
        res += pow(10, len) * (aux % 10);
        len--;
        aux /= 10;
    }
    if (res == n) {
        return 1;
    }
    else {
        return 0;
    }
}

void palindromes(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (is_palindrome(current)) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

int is_fibonacci(int n) {
    // here, it's considered that fibonacci sequence contains only non-negative integers
    if (n < 0) {
        return 0;
    }
    else if (is_perfect_square(5*n*n - 4) || is_perfect_square(5*n*n + 4)) {
        return 1;
    }
    else {
        return 0;
    }
}

void fibonacci(char fname[], char gname[]) {
    FILE *fp = fopen(fname, "rb");
    FILE *gp = fopen(gname, "wb");
    int current;
    while(!feof(fp)) {
        if (fread(&current, sizeof(current), 1, fp)) {
            if (is_fibonacci(current)) {
                fwrite(&current, sizeof(current), 1, gp);
            }
        }
    }
    fclose(fp);
    fclose(gp);
}

void task3() {
    printf("-------Create a file with integer components-------\n");
    char fname[LEN];
    printf("Enter a name of the file which will be created: ");
    scanf("%s", fname);
    create_file(fname, 3);
    printf("Data in file <%s>: ", fname);
    read_file(fname, 3);

    char gname_a[LEN] = "G_a.txt";
    even(fname, gname_a);
    printf("Data in file <%s>: ", gname_a);
    read_file(gname_a, 3);

    char gname_b[LEN] = "G_b.txt";
    powers_of_3(fname, gname_b);
    printf("Data in file <%s>: ", gname_b);
    read_file(gname_b, 3);

    char gname_c[LEN] = "G_c.txt";
    perfect_squares(fname, gname_c);
    printf("Data in file <%s>: ", gname_c);
    read_file(gname_c, 3);

    char gname_d[LEN] = "G_d.txt";
    amount_divisors(fname, gname_d);
    printf("Data in file <%s>: ", gname_d);
    read_file(gname_d, 3);
    
    char gname_e[LEN] = "G_e.txt";
    palindromes(fname, gname_e);
    printf("Data in file <%s>: ", gname_e);
    read_file(gname_e, 3);

    char gname_f[LEN] = "G_f.txt";
    fibonacci(fname, gname_f);
    printf("Data in file <%s>: ", gname_f);
    read_file(gname_f, 3);
}

int main() {
    task3();
}
