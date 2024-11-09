#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <sstream>

#define LEN 256

using namespace std;

double task1() {
    fstream f("task1.txt");
    if (!f) {
        cerr << "Error during opening the file";
        return 0;
    }
    double res = 0;
    int num = 0, prev_sign = -1;
    char current;
    while (f >> current) {
        if (isdigit(current)) {
            int d = current - '0';
            num = num * 10 + d;            
        }
        else if (current == '-') {
            res += prev_sign * num;
            num = 0;
            prev_sign = -1;
        }
        else if (current == '+') {
            res += prev_sign * num;
            num = 0;
            prev_sign = 1;
        }
        else {
            printf("Wrong format.");
        }
    }
    res += prev_sign * num;
    f.close();
    return res;
}

void task2() {
    char fname[20] = "task2.txt";
    ifstream f(fname);
    string buf;
    string Articles[] = {"der", "die", "das"};
    bool isArticle = false;
    ofstream f2("tmp.txt");
    while (f >> buf) {
        if (isArticle) {
            buf[0] = toupper(buf[0]);
        }
        f2<<buf<<" ";
        isArticle = false;
        for (int i = 0; i < 3; i++) {
            if (buf == Articles[i]) {
                isArticle = true;
                break;
            }
        }
    }
    f.close();
    f2.close();
    remove(fname);
    rename("tmp.txt", fname);
}

char* inversed(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tmp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = tmp;
    }
    return str;
}

int task3() {
    char fname[20] = "task3.txt";
    char resname[20] = "res3.txt";
    ifstream f(fname);
    ofstream res(resname);
    if (!f || !res) {
        cerr << "Error during opening the file";
        return 0;
    }
    char current;
    char* current_word = new char[LEN];
    bool word = false;
    int k = 0;
    while (f.get(current)) {
        if (word && !isalnum(current)) {
            res << inversed(current_word) << " ";
            delete[] current_word;
            current_word = new char[LEN];
            word = false;
            k = 0;
        }
        else if (isalnum(current)) {
            current_word[k] = current;
            k++;
            word = true;
        }
        else {;}
    }
    delete[] current_word;
    f.close();
    res.close();
    return 1;
}

bool checkTags(char* filename, string opening = "<td>", string closing = "</td>") {
    ifstream f1(filename);
    int open = 0;
    int closed = 0;
    string buf;
    while (!f1.eof()) {
        if (f1 >> buf) {
            if (buf == opening) {
                open++;
            }
            else if (buf == closing) {
                closed++;
            }
            else {;}
            if (closed > open) {
                return false;
            }
        }
    }
    return open == closed;
}

void task4() {
    char* filename = new char[10];
    cout << "Enter a name of the file to read the data from: ";
    cin >> filename;
    cout << checkTags(filename) << "\n";
    delete[] filename;
}

void createfile(char* fname) {
    ofstream f1(fname);
    int n;
    cout << "Enter the amount of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string surname;
        int course;
        string group;
        string marks;
        cout << "Enter surname, course, group, marks: ";
        cin >> surname >> course >> group >> marks;
        f1 << surname << " " << course << " " << group << " " << marks << "\n";
    }
    f1.close();
}

double average(string marks) {
    int temp;
    double sum = 0;
    int counter = 0;
    stringstream str(marks);
    while (str >> temp) {
        sum += temp;
        counter++;
        char coma;
        str >> coma;
    }
    return sum / counter;
}

string findstudent(char* fname) {
    ifstream f1(fname);
    string worst_student, surname, group, marks;
    double min_mark = 100, temp;
    while(!f1.eof()) {
        int course;
        f1 >> surname;
        f1 >> course;
        f1 >> group;
        f1 >> marks;
        temp = average(marks);
        if (min_mark > temp) {
            worst_student = surname;
            min_mark = temp;
        }
    }
    f1.close();
    return worst_student;
}

void task5() {
    char* filename = new char[20];
    cout << "Enter a name of the file to read the data from: ";
    cin >> filename;
    string worst_student = findstudent(filename);
    cout << worst_student << "\n";
    delete[] filename;
}

int main() {
    task5();
}
