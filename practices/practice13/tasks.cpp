#include <iostream>
#include <string>
#include <cctype>

#define npos 4294967295

std::string task1(std::string s) {
    std::string colon(":"), comma(",");
    unsigned int pos1 = s.find(colon), pos2 = s.find(comma);
    if (pos1 == npos) {return s;}
    else if (pos2 == npos) {
        pos2 = s.length();
        return s.substr(pos1 + 1, pos2 - 2);
        }
    return s.substr(pos1 + 1, pos2 - pos1 - 1);
}

std::string task2(std::string s) {
    std::string dot(".");
    unsigned int pos1 = s.find(dot), pos2 = s.rfind(dot);
    if (pos1 == npos) {
        unsigned int i = 0;
        while (s[i] == ' ' ) {i++;}
        s.replace(0, i, "");
    }
    else if (pos1 == pos2) {s.replace(0, pos1+1, "");}
    else {std::cout << s.replace(pos1, pos2 - pos1 + 1, "");}
    return s;
}

std::string task3() {
    std::string input, res("");
    std::cout << "Enter the string: ";
    getline(std::cin, input);
    unsigned int len = input.length();
    int j = 0, i;
    std::string current;
    for(int k = 0; k < len; k++) {
        i = 0;
        if (isspace(input[0])) {
            while (isspace(input[i])) {
                if (j++ == len) {break;}
                i++; j++;}
            res += input.substr(0, i);
            input.replace(0, i, "");
        }
        else {
            while (!isspace(input[i])) {
                if (j++ == len) {break;}
                i++; j++;}
            res += input.substr(0, i - 1);
            input.replace(0, i, "");
        }
        if (input.empty()) {break;}
    }
    return res;
}

double* task4(std::string s, unsigned int n, std::string delimiter) {
    double* res = new double[n];
    unsigned int counter = 0, pos;
    while(!s.empty()) {
        pos = s.find(delimiter);
        res[counter] = stod(s.substr(0, pos));
        counter++;
        s.replace(0, pos + 1, "");
        if (counter == n) {break;}
    }
    return res;
}

std::string* task5(std::string s, unsigned int n, std::string delimiter) {
    std::string* res_terms = new std::string[n];
    unsigned int counter = 0, pos;
    while(!s.empty()) {
        pos = s.find(delimiter);
        res_terms[counter] = s.substr(0, pos);
        counter++;
        s.replace(0, pos + 1, "");
        if (counter == n) {break;}
    }
    return res_terms;
}

std::string* task6(std::string s) {
    std::string delimiter(" "), current;
    unsigned int min;
    std::string* res = new std::string[s.length() + 1];
    unsigned int counter = 1, pos;
    pos = s.find(delimiter);
    current = s.substr(0, pos);
    min = current.length();
    res[0] = current;
    s.replace(0, pos + 1, "");
    while(!s.empty()) {
        pos = s.find(delimiter);
        if (pos == npos) {break;}
        current = s.substr(0, pos);
        s.replace(0, pos + 1, "");
        if (current.length() == min) {
            res[counter] = current;
            counter++;
        }
        else if (current.length() < min) {
            min = current.length();
            delete[] res;
            std::string* res = new std::string[s.length() + 1];
            res[0] = current;
            counter = 1;
        }
    }
    return res;

} 

int main() {
    std::string s("lkj lkj lkj laskdjf lkj alskdjf laskdjf laskdjf laskdjf laskdjfj");
    std::string* res = task6(s);
    for (int i = 0; i < s.length(); i++) {
        std::cout << res[i] << std::endl;
    }
}
