#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

std::map<std::string, unsigned int> frequency(std::string filename) {
    std::map<std::string, unsigned int> res;
    std::ifstream fin(filename);
    std::string current;
    while(!fin.eof()) {
        fin >> current;
        try {int check = res.at(current);}
        catch (std::out_of_range& e) {
            res[current] = 1;
            continue;
        }
        res[current]++;
    }
    fin.close();
    return res;
}

void task1() {
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;
    std::map<std::string, unsigned int> freq = frequency(filename);
    for (auto el:freq) {
        std::cout << el.first << " : " << el.second << std::endl;
    }
}

void task2() {
    std::multiset<double> series, reduced;
    std::string answer;
    double temp;
    int i = 0;
    while (answer != "n") {
        std::cout << "element: ";
        std::cin >> temp;
        series.insert(temp);
        std::cout << "Continue entering[y/n]: ";
        std::cin >> answer;
    }
    while (series.size() != 1) {
        i = 0;
        for (auto pos = series.begin(); pos != series.end()--; pos++) {
            if (i % 2 == 1) {
                i++;
                continue;
            }
            else {
                reduced.insert(*pos + *(++pos));
                pos--;
                i++;
            }
        }
        if (series.size() % 2 == 1) {reduced.insert(*series.end());}
        series.clear();
        for (auto pos = reduced.begin(); pos != reduced.end(); pos++) {
            series.insert(*pos);
        }
        reduced.clear();
    }
    std::cout << *(series.begin()) << std::endl;
}

std::set<std::pair<double, double>> parse_file(std::string filename) {
    std::set<std::pair<double, double>> res;
    std::pair<double, double> temp;
    std::string aux;
    std::ifstream fin(filename);
    while(!fin.eof()) {
        fin >> aux;
        fin >> temp.first;
        fin >> aux;
        fin >> temp.second;
        fin >> aux;
        res.insert(temp);
    }
    fin.close();
    return res;
}

void show(std::set<std::pair<std::pair<double, double>, std::pair<double, double>>> multi) {
    for (auto pos = multi.begin(); pos != multi.end(); pos++) {
        std::cout << "point1: " << (*pos).first.first << " " << (*pos).first.second << "  point2: "  << (*pos).second.first << " " << (*pos).second.second << std::endl;
    }
    std::cout << std::endl;
}

std::set<std::pair<std::pair<double, double>, std::pair<double, double>>> generate_segments(std::string filename) {
    std::set<std::pair<double, double>> points = parse_file(filename);
    std::set<std::pair<std::pair<double, double>, std::pair<double, double>>> res;
    std::pair<std::pair<double, double>, std::pair<double, double>> temp;
    for (auto pos1 = points.begin(); pos1 != points.end(); pos1++) {
        for (auto pos2 = pos1; pos2 != points.end(); pos2++) {
            if (*pos1 == *pos2) {continue;}
            temp.first = *pos1;
            temp.second = *pos2;
            res.insert(temp);
        }
    }
    return res;
}

double norm(std::pair<std::pair<double, double>, std::pair<double, double>> segment) {
    return sqrt(pow(segment.second.first - segment.first.first, 2) + pow(segment.second.second - segment.first.second, 2));
}

bool compare(std::pair<std::pair<double, double>, std::pair<double, double>> segment1, std::pair<std::pair<double, double>, std::pair<double, double>> segment2) {
    return (norm(segment1) < norm(segment2));
}

std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> bubble_sort(std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> vect) {
    bool check = false;
    size_t size = vect.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (norm(vect[j]) > norm(vect[j+1])) {
                std::swap(vect[j], vect[j+1]);
                check = true;
            }
        }
        if (check == false) {break;}
    }
    return vect;
}

void show(std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> multi) {
    for (int i = 0; i < multi.size(); i++) {
        std::cout << "point1: " << multi[i].first.first << " " << multi[i].first.second << "  point2: "  << multi[i].second.first << " " << multi[i].second.second << std::endl;
        std::cout << "======= norm : " << norm(multi[i]) << std::endl;
    }
    std::cout << std::endl;
}

void write(std::string filename, std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> s) {
    std::ofstream fout(filename);
    for (int i = 0; i < s.size(); i++) {
        fout << "( " << s[i].first.first << ", " << s[i].first.second << " ) ( "<< s[i].second.first << ", " << s[i].second.second << " )" << std::endl;
    }
    fout.close();
}

void task3() {
    std::string filename1, filename2;
    std::cout << "Enter the filename to take the data from: ";
    std::cin >> filename1;
    std::cout << "Enter the filename to write the data into: ";
    std::cin >> filename2;
    std::set<std::pair<std::pair<double, double>, std::pair<double, double>>> segments = generate_segments(filename1);
    std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> segm(segments.begin(), segments.end());
    std::vector<std::pair<std::pair<double, double>, std::pair<double, double>>> segm_sorted = bubble_sort(segm);
    write(filename2, segm_sorted);
}

int main() {
    task3();
}
