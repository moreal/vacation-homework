#include <iostream>
#include <algorithm>
#include <string>

int T, N;
std::string input;
int max_prices;

// i_from to save repeat count
void change(int changes, int i_from) {
    if (changes == 0) {
        max_prices = std::max(max_prices, std::stoi(input));
        return;
    }

    for (int i { i_from }; i < input.size(); ++i) {
        for (int j { 0 }; j < input.size(); ++j) {
            if (i == j) continue;
            if (input[i] >= input[j]) {
                std::swap(input[i], input[j]);
                change(changes-1, i);
                std::swap(input[i], input[j]);
            }
        }
    }
}

int main() {
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        std::cin >> input >> N;
        max_prices = 0;
        change(N, 0);
        std::cout << '#' << (i+1) << ' ' << max_prices << '\n';
    }
    return 0;
}