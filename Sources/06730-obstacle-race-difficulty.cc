#include <iostream>
#include <algorithm>

int blocks[100];

int main() {
    int T;
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        int N, upMax { 0 }, downMax { 0 };
        std::cin >> N;

        for (int j { 0 }; j < N; ++j) {
            std::cin >> blocks[j];
        }

        for (int j { 0 }; j < N; ++j) {
            if (j != 0)
                upMax = std::max(upMax, blocks[j] - blocks[j-1]);
            if (j != N - 1)
                downMax = std::max(downMax, blocks[j] - blocks[j+1] );
        }

        std::cout << '#' << (i+1) << ' ' << upMax << ' ' << downMax << '\n';
    }

    return 0;
}