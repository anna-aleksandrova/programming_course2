#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#define LEN 30

using namespace std;

int write_file(char* filename) {
    ofstream ostr(filename);
    cout << "Enter the numbers to write into the file (~ to stop): ";
    string str;
    int counter = 0;
    while (1) {
        cin >> str;
        if (!str.compare("~")) {
            break;
        }
        if (counter == 0) {
            ostr << str;
        }
        else {
            ostr << ", " << str;
        }
        counter++;
    }
    ostr.close();
    return 1;
}

int task6() {
    char* filename = new char[LEN];
    char* res = new char[LEN];
    cout << "Enter a name of the file to read the data from: ";
    cin >> filename;
    cout << "Enter a name of the file to write the result into: ";
    cin >> res;
    ifstream istr(filename);
    ofstream ostr(res);
    double cur;
    string str;
    while(!istr.eof()) {
        istr >> str;
        str.pop_back();
        cur = stod(str);
        if (cur > 0) {
            ostr << "log(" << fixed << cur << ") = " << log(cur) << " = " << scientific << log(cur) << "\n";
            if (ostr.bad()) {
                cerr << "Error during writing into the file " << res;
            }
        }
        else {
            ostr << "log(" << cur << ") = None\n";
        }
    }
    delete[] filename;
    delete[] res;
    istr.close();
    ostr.close();
    return 1;
}

int main() {
    task6();
}
