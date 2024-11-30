#include <iostream>
#include <set>
#include <utility>
#include <vector>

using point = std::pair<double, double>;
using segment = std::pair<std::pair<double, double>, std::pair<double, double>>;

point intersection(segment s1, segment s2) {
    point res;
    double x1 = s1.first.first;
    double x2 = s1.second.first;
    double x3 = s2.first.first;
    double x4 = s2.second.first;
    double y1 = s1.first.second;
    double y2 = s1.second.second;
    double y3 = s2.first.second;
    double y4 = s2.second.second;
    double a = (x4 - x3) * (y3 - y1) - (y4 - y3) * (x3 - x1);
    double b = (x4 - x3) * (y2 - y1) - (y4 - y3) * (x2 - x1);
    double c = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (b == 0) {res.first = __DBL_MAX__; res.second = __DBL_MAX__;}
    else {
        double alpha = a / b;
        double beta = c / b;
        res.first = x1 + alpha  * (x2 - x1);
        res.second = y1 + alpha * (y2 - y1);
    }
    return res;
}

std::set<point> intersections(std::vector<segment> segments) {
    std::set<point> res;
    for (int i = 0; i < segments.size(); i++) {
        for (int j = i; j < segments.size(); j++) {
            res.insert(intersection(segments[i], segments[j]));
        }
    }
    return res;
}

segment input() {
    segment res;
    std::cout << "Point 1: ";
    std::cin >> res.first.first >> res.first.second;
    std::cout << "Point 2: ";
    std::cin >> res.second.first >> res.second.second;
    return res;
}

void task() {
    std::vector<segment> segments;
    std::string answer;
    segment current;
    while(answer != "n") {
        current = input();
        segments.push_back(current);
        std::cout << "Continue entering[y/n]: ";
        std::cin >> answer;
    }
    std::set<point> res_in = intersections(segments);
    point res = *res_in.begin();
    std::cout << "(" << res.first << ", " << res.second << ")" << std::endl;
}

int main() {
    task();
}
