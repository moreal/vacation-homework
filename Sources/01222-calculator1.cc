#include <iostream>
#include <string>

int L, sum;
std::string input;

int main() {
    for (int i { 0 }; i < 10; ++i) {
        sum = 0;
        std::cin >> L >> input;

        for (const auto& c : input) {
            if (std::isdigit(c)) {
                sum += c - '0';
            }
        }
        
        std::cout << '#' << (i+1) << ' ' << sum << '\n';
    }

    return 0;
}