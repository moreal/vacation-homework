#include <iostream>
#include <algorithm>
#include <string>

int T, N;
std::string input;
int max_prices;

std::string* swap_string_element(std::string* s, int indexA, int indexB) {
    char tmp = s->at(indexA);
    s->at(indexA) = s->at(indexB);
    s->at(indexB) = tmp;
    return new std::string(*s);
}

void change(std::string* s, int changes) {
    // std::cout << "DEBUG " << s << '\n';
    if (changes == 0) {
        max_prices = std::max(max_prices, std::stoi(*s));
        return;
    }

    for (int i { 0 }; i < s->size(); ++i) {
        for (int j { 0 }; j < s->size(); ++j) {
            if (i == j) continue;
            change(swap_string_element(new std::string(*s), i, j), changes-1);
        }
    }
}

int main() {
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        std::cin >> input >> N;
        // std::cout << input << '\n';
        max_prices = 0;
        change(new std::string(input), N);
        std::cout << '#' << (i+1) << ' ' << max_prices << '\n';
    }
    return 0;
}