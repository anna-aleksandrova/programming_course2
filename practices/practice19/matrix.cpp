#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <set>

template <typename T> std::list<T> input_row(size_t m) {
    std::list<T> res;
    T temp;
    for (int i = 0; i < m; i++) {
        std::cout << "m[" << i << "]: ";
        std::cin >> temp;
        res.push_back(temp);
    }
    return res;
}

template <typename T> std::vector<std::list<T>> input_matrix(size_t n, size_t m) {
    std::vector<std::list<T>> res(n);
    for (int i = 0; i < n; i++) {
        std::cout << "row[" << i << "]:\n";
        res[i] = input_row<T>(m);
    }
    return res;
}

template <typename T> T max_element(std::list<T> lst) {
    T max = *lst.begin();
    for (auto pos = lst.begin(); pos != lst.end(); pos++) {
        if (*pos > max) {max = *pos;}
    }
    return max;
}

template <typename T> std::vector<std::list<T>> swap_rows(std::vector<std::list<T>> matrix) {
    std::pair<T, int> temp;
    std::multiset<std::pair<T, int>> rows_order;
    for (int i = 0; i < matrix.size(); i++) {
        temp.first = max_element(matrix[i]);
        temp.second = i;
        rows_order.insert(temp);
    }
    std::vector<std::list<T>> res(matrix.size());
    int i = 0;
    for (auto pos = rows_order.rbegin(); pos != rows_order.rend(); pos++) {
        res[i] = matrix[pos->second];
        i++;
    }
    return res;
}

template <typename T> void show(std::vector<std::list<T>> matrix) {
    for (auto row:matrix) {
        for (auto pos = row.begin(); pos != row.end(); pos++) {std::cout << *pos << " ";}
        std::cout << std::endl;
    }  
}

int main() {
    std::vector<std::list<double>> matrix = input_matrix<double>(3, 2);
    std::vector<std::list<double>> res = swap_rows(matrix);
    show<double>(res);
}
