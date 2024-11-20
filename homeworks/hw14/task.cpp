#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#define LEN 30

using namespace std;

int game(char* filename) {
    ofstream game(filename);
    if (!game) {
        cerr << "Error during opening the file " << filename;
        return 0;
    }
    int n, i, j, answer;
    string name;
    cout << "Enter the amount of players: ";
    cin >> n;
    for (int t = 0; t < n; t++) {
        cout << "Enter a name of the " << t + 1 << " player: ";
        cin >> name;
        game << name << " ";
        for (int u = 0; u < 10; u++) {
            i = rand() % 21;
            j = rand() % 21;
            cout << i << " x " << j << " = ";
            cin >> answer;
            game << i << "x" << j << "=" << answer << " ";
        }
        game << "\n";
    }
    game.close();
    return 1;
}

int check(string str) {
    int len = str.length();
    int a, b, answer, x_pos, e_pos;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'x') {
            a = stoul(str.substr(0, i));
            x_pos = i;
        }
        if (str[i] == '=') {
            b = stoul(str.substr(x_pos + 1, i - x_pos - 1));
            e_pos = i;
        }
    }
    answer = stoul(str.substr(e_pos + 1, len - e_pos - 1));
    if (a * b == answer) {
        return 1;
    }
    else {
        return 0;
    }
}

int results(char* data_name, char* res_name) {
    ifstream data(data_name);
    ofstream res(res_name);
    if (!data || !res) {
        cerr << "Error during opening the file.\n";
        return 0;
    }
    string current;
    int correct = 0, counter = 0;
    while (!(data >> current).eof()) {
        if (isalpha(current[0])) {
            if (counter == 0) {;}
            else {
                res << (double) (correct * 100) / counter << "%";
                correct = 0;
                counter = 0;
            }
            res << "\n" << current << " ";
        }
        else {
            if (check(current)) {
                correct++;
            }
            counter++;
        }
    }
    res << (double) (correct * 100.0) / counter << "%\n";
    data.close();
    res.close();
    return 1;
}

void task() {
    char* file_game = new char[LEN];
    char* file_res = new char[LEN];
    cout << "Enter a name of the file to write the process of the game into: ";
    cin >> file_game;
    cout << "Enter a name of the file to write the results of the game into: ";
    cin >> file_res;
    game(file_game);
    results(file_game, file_res);
    delete[] file_game;
    delete[] file_res;
}

int main() {
    task();
}