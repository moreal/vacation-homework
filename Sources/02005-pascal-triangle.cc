#include <iostream>
#include <array>

std::array<std::array<int, 10>, 10> floors;

void init_floors() {
    for (int i { 0 }; i < 10; ++i) {
        floors[i].fill(-1);
    }
}

const int get_element(const int floor, const int index) {
    if (index < 0 || index > floor) return 0;
    else return floors[floor][index];
}


void draw_floor(const int floor) {
    if (floor == 0) {
        floors[0][0] = 1;
        return;
    }

    for (int i { 0 }; i <= floor; ++i) {
        floors[floor][i] = get_element(floor-1, i - 1) + get_element(floor-1, i);
    }
}
void make_floors() {
    for (int i { 0 }; i < 10; ++i) {
        draw_floor(i);
    }
}

int main() {
    int T;
    std::cin >> T;

    make_floors();

    for (int i { 0 }; i < T; ++i) {    
        int N;
        std::cin >> N;

        std::cout << '#' << (i+1) << '\n';

        for (int i { 0 }; i < N; ++i) {
            for (int j { 0 }; j < i + 1; ++j) {
                std::cout << floors[i][j] << ' ';
            } std::putchar('\n');
        }
    }
    
    return 0;
}