#include <iostream>

int T, N, sum;

int main() {
    std::cin >> T;
    for (int i { 0 }; i < T; ++i) {
        sum = 0;
        std::cin >> N;

        for (int j { 1 }; j <= N; ++j) {
            sum += (j % 2 == 0 ? -1 : 1) * j;
        }

        std::cout << '#' << (i+1) << ' ' << sum << '\n';
    }
    return 0;
}