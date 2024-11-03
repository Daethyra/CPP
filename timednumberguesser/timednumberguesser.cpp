#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

int main() {
    int seed = std::rand() % 11; // Secret number
    int guess;

    // Get the start time
    auto start = std::chrono::high_resolution_clock::now();

    while (true) {
        std::cout << "Guess the number (1-10): ";
        std::cin >> guess;

        if (guess == seed) {
            std::cout << "Correct! The number was " << seed << "." << std::endl;
            return 0;
        }

        // Check if 60 seconds have elapsed
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
        if (elapsed >= 60) {
            std::cout << "Time's up! The number was " << seed << "." << std::endl;
            return 1;
        }

        std::cout << "Wrong! Try again: ";
    }
}