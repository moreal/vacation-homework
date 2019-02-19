#include <iostream>
#include <algorithm>

int T;
int N, M;
char problemSolved;
int firstGradesCount;

int solves[20];

int main() {
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        std::cin >> N >> M;
        for (int j { 0 }; j < N; ++j) {
            solves[j] = 0;
            for (int _ { 0 }; _ < M; ++_) {
                std::cin >> problemSolved;
                solves[j] += problemSolved - '0'; 
            }
        }

        std::sort(solves, solves+N, [](const int a, const int b) {
            return a > b;
        });

        firstGradesCount = std::count(solves, solves+N, solves[0]);
        std::cout << '#' << (i+1) << ' ' << firstGradesCount << ' ' << solves[0] << '\n';
    }

    return 0;
}