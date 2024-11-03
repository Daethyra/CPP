#include <iostream>
#include <cstdlib>

int main() {
    int seed = std::rand() % 11; // Secret number
    int guess;

    std::cout << "Guess the number (1-10): ";
    std::cin >> guess;

    while (guess != seed) {
        std::cout << "Wrong! Try again: ";
        std::cin >> guess;
    }

    std::cout << "Correct! The number was " << seed << "." << std::endl;
    return 0;
}
