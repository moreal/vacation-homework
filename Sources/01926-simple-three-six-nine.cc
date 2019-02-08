#include <iostream>
#include <string>

const int count_multiple_of_three(int number) {
    int count { 0 };
    
    do {
        switch (number % 10)
        {
            case 3:
            case 6:
            case 9:
                ++count;
                break;
        }
    } while (number /= 10);

    return count;
}

void print_number_by_rule(const int number) {
    const int count = count_multiple_of_three(number);
    if (count == 0) {
        std::cout << number << ' ';
    } else {
        std::cout << std::string(count, '-') << ' ';
    }
}

void play_game(const int N) {
    for (int i { 1 }; i <= N; ++i) {
        print_number_by_rule(i);
    }
}

int main() {
    int N;
    std::cin >> N;

    play_game(N);

    return 0;
}