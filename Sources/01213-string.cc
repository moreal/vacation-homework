#include <iostream>
#include <string>
#include <algorithm>

int N;
std::string find, input;

int count() {
    std::size_t found = 0;
    int cnt { 0 };
    while ((found = input.find(find, found+1)) != std::string::npos) {
        cnt += 1;
    }
    return cnt;
}

int main() {
    for (int i { 0 }; i < 10; ++i) {
        std::cin >> N >> find >> input;
        std::cout << '#' << N << ' ' << count() << '\n';
    }
    return 0;
}