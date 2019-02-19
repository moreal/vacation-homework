#include <iostream>
#include <algorithm>
#include <vector>

using CardNumber = char;
using Color = char;

typedef struct Card {
    CardNumber number;
    Color color;
} Card;

Card cards[9];
std::vector<int> redCards(9), blueCards(9), greenCards(9);

void get_cards_from_input() {
    for (int i { 0 }; i < 9; ++i) {
        std::cin >> cards[i].number;
    }
    for (int i { 0 }; i < 9; ++i) {
        std::cin >> cards[i].color;
    }
}

void say_result(int index, const char* message) {
    std::cout << '#' << index << ' ' << message << '\n';
}

bool check_cards(std::vector<int>& cards) {
    std::sort(cards.begin(), cards.end(), [](int a, int b) {
        return a < b;
    });

    bool success { true };

    while (cards.size()) {
        if (cards[0] == cards[1] && cards[1] == cards[2]) {
            cards.erase(cards.begin(), cards.begin() + 2);
            continue;
        }
        
        auto el1 = std::find(cards.begin(), cards.end(), cards[0] + 1 );
        auto el2 = std::find(cards.begin(), cards.end(), cards[0] + 2 );

        if (el1 != cards.end() && el2 != cards.end()) {
            int copyValue1 = *el1;
            int copyValue2 = *el2;

            cards.erase(cards.begin());
            cards.erase(std::find(cards.begin(), cards.end(), copyValue1 ));
            cards.erase(std::find(cards.begin(), cards.end(), copyValue2 ));
            continue;
        }
        
        success = false;
        break;
    }

    return success;
}

void filter_and_map_cards_by_color(Card* origins, std::vector<int>& newCards, const char color) {
    newCards.clear();
    for (int i { 0 }; i < 9; ++i) {
        if (origins[i].color == color) {
            newCards.push_back(origins[i].number);
        }
    }
}

int main() {
    int T;
    std::cin >> T;

    for (int i { 0 }; i < T; ++i) {
        get_cards_from_input();

        filter_and_map_cards_by_color(cards, redCards, 'R');
        filter_and_map_cards_by_color(cards, greenCards, 'G');
        filter_and_map_cards_by_color(cards, blueCards, 'B');

        bool success = redCards.size() % 3 == 0
            && blueCards.size() % 3 == 0
            && greenCards.size() % 3 == 0 
            && check_cards(redCards) 
            && check_cards(blueCards)
            && check_cards(greenCards);

        say_result(i+1, success ? "Win" : "Continue");
    }
}