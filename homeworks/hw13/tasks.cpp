#include <iostream>

#define npos 4294967295

std::string clean(std::string s, char c) {
    while (1) {
        unsigned int pos = s.find(c);
        if (pos == npos) {break;}
        s.replace(pos, 1, "");
    }
    return s;
}

std::string task11(std::string input, char c) {
    unsigned int len = input.length();
    int j = 0, i;
    std::string current, res("");
    input += " ";
    for(int k = 0; k < len; k++) {
        i = 0;
        if (isspace(input[0])) {
            while (isspace(input[i])) {
                if (j++ == len) {break;}
                i++; j++;}
            res += clean(input.substr(0, i), c);
            input.replace(0, i, "");
        }
        else {
            while (!isspace(input[i])) {
                if (j++ == len) {break;}
                i++; j++;}
            res += clean(input.substr(0, i), c);
            input.replace(0, i, "");
        }
        if (input.empty()) {break;}
    }
    return res;
}

std::string task17(std::string s) {
    std::string articles[6] = {"A", "An", "The", "a", "an", "the"};
    std::string temp, res("");
    unsigned int pos, pos1, len;
    for (int i = 0; i < 6; i++) {
        pos = 0;
        len = articles[i].length();
        while (1) {
            pos1 = s.find(articles[i], pos);
            pos++;
            if (pos1 == npos) {break;}
            temp = tolower(s[pos1 + len + 1]);
            s.replace(pos1 + len + 1, 1, temp);
        }
    }
    return s;
}

int main() {
    std::string s("An Apple The Weather A House an Apple the Weather a House");
    std::cout << task17(s) << std::endl;
}