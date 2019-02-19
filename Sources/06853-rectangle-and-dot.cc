#include <iostream>

int T, N;
int x1, y1, x2, y2;
int innerCount, onLineCount, outerCount;
int x, y;

int main() {
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        innerCount = 0, onLineCount = 0, outerCount = 0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cin >> N;

        for (int j { 0 }; j < N; ++j) {
            std::cin >> x >> y;

            if ( x1 < x && x < x2
                && y1 < y && y < y2 ) {
                innerCount += 1;
            } else if ((x == x1 || x == x2) && (y1 <= y && y <= y2)
                || (y == y1 || y == y2) && (x1 <= x && x <= x2)) {
                onLineCount += 1;
            } else {
                outerCount += 1;
            }
        }
        
        std::cout << '#' << (i+1) << ' ' << innerCount << ' ' << onLineCount << ' ' << outerCount << '\n';
    }
}