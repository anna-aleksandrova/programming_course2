#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstring>

#define LEN 30
using namespace std;

void task1() {
    float x, y, res;
    cout << "x = ";
    cin>>x;
    cout << "y = ";
    cin>>y;
    if (x == 0 && y <= 0) {
        cerr << "Undefined value.\n"; 
    }
    else {
        res = pow(x, y);
        cout<<res<<endl;
        cout<<scientific<<res<<endl;
    }
}

void task2() {
    char str[10];
    unsigned long long sum=0UL;
    unsigned a;
    cout<<"Enter a string with numbers (length = 0(mod 10)): ";
    size_t sz;
    while(cin.get(str, 11)) {
        a = stoul(str, &sz);
        sum += a;
    }
    cout<<"Sum = "<<sum<<"\n";
}

void task3() {
    unsigned int n;
    printf("n = ");
    cin>>n;
    cout.fill('+');
    cout<<setw(6*n)<<"\n";
    cout.fill(' ');
    for (int i = 1; i <= n; i++) {
        cout<<setw(4)<<i<<"  ";
    }
    cout.fill('+');
    cout<<"\n"<<setw(6*n)<<"\n";
    cout.fill(' ');
    for (int i = 1; i <= n; i++) {
        cout<<setw(4)<<setprecision(3)<<sqrt(i)<<"  ";
    }
    cout<<"\n";
}

int* input_console(int n) {
    int* ptr = new int[n];
    cout << "Enter an array: \n";
    for (int i = 0; i < n; i++) {
        cout << "array[" << i << "]: ";
        cin >> ptr[i];
    }
    return ptr;
}

int write_file(char* filename, int array_size) {
    ofstream ostr;
    ostr.open(filename);
    if (!ostr) {
        cerr << "Error during opening file " << filename << ".\n";
        return 0;
    }
    else {
        double cur;
        for (int i = 0; i < array_size; i++) {
            cout << "array[" << i << "]: ";
            cin >> cur;
            ostr << cur << " ";
            if (ostr.bad()) {
                cerr << "Error during writing data into the file.\n";
                ostr.close();
                return 0;
            }
        }
        ostr.close();
        return 1;
    }
}

double* read_file(char*filename, int array_size) {
    ifstream istr(filename);
    if (!istr) {
        cerr << "Error during opening file " << filename << ".\n";
        return nullptr;
    }
    else {
        double* res = new double[array_size];
        for (int i = 0; i < array_size; i++) {
            istr >> res[i];
            if (istr.bad()) {
                cerr << "Error during reading from the file" << endl;
                delete[] res;
                istr.close();
                return nullptr;
            }
        }
        istr.close();
        return res;
    }
}

int powers_intofile(int* integers, double* reals, int n, char* filename) {
    ofstream ostr;
    ostr.open(filename);
    if (!ostr) {
        cerr << "Error during opening file " << filename << endl;
        return 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (fabs(reals[i]) < __DBL_EPSILON__ && integers[i] <= 0) {
                cerr << "Undefined value: (" << reals[i] << ")^(" << integers[i] << ")\n";
                ostr.close();
                return 0;
            }
            else {
                ostr << pow(reals[i], integers[i]) << endl;
                if (ostr.bad()) {
                    cerr << "Error during writing data into the file" << endl;
                    ostr.close();
                    return 0;
                }
            }
        }
        ostr.close();
        return 1;
    }
}

int task4() {
    unsigned int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    int* console = input_console(n);
    char* filename = new char[LEN];
    cout << "Enter a name of the file to read the real numbers from: ";
    cin >> filename;
    double* file = read_file(filename, n);

    char* res = new char[LEN];
    cout << "Enter a name of the file to write the result into: ";
    cin >> res;
    powers_intofile(console, file, n, res);
    delete[] console;
    delete[] file;
    delete[] filename;
    delete[] res;
    return 1;
}

int write_file2(char* filename) {
    ofstream ostr;
    ostr.open(filename);
    if (!ostr) {
        cerr << "Error during opening file " << filename << ".\n";
        return 0;
    }
    else {
        string str;
        getline(cin, str, '*');
        ostr << str;
        ostr.close();
        return 1;
    }
}

int square_roots(char* filename, char* resfile) {
    ifstream istr(filename);
    ofstream ostr(resfile);
    int cur;
    char* data = new char[LEN];
    int* res = new int[LEN];
    int counter = 0;
    if (istr) {
        while (!(istr >> data).eof()) {
            if (istr.bad()) {
                cerr << "Error during reading from the file.\n";
                istr.close();
                ostr.close();
                return 0;
            }
            else {
                res[counter] = stoul(data);
                counter++;
            }
        }
        for (int i = 0; i < counter; i++) {
            ostr << setprecision(3) << fixed << sqrt(res[counter - 1 - i]) << "\n";
        }
        istr.close();
        ostr.close();
        return 1;
    }
    else {
        cerr << "Error during opening the file.\n";
        istr.close();
        ostr.close();
        return 0;
    }
}

int task5() {
    char* from = new char[LEN];
    char* into = new char[LEN];
    cout << "Enter a name of the file to read the data from: ";
    cin >> from;
    cout << "Enter a name of the file to write the data into: ";
    cin >> into;
    square_roots(from, into);
    delete[] from;
    delete[] into;
    return 1;
}

int main() {
    task5();
}
