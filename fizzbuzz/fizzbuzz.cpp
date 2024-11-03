#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Set the range to 21
    int range = 21;

    // Loop through the range
    for (int i = 1; i <= range; i++) {
        if (i % 3 == 0 && i != 1) 
            std::cout << "Fizz";
        if (i % 5 == 0 && i != 1)
            std::cout << "Buzz";
        // if (i % 3 == 0 && i % 5 == 0 && i != 1)
        //     std::cout << "FizzBuzz";
        if (i % 3 != 0 && i % 5 != 0 || i == 1)
            std::cout << i;

        // Sleep for 0.5 seconds
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Print a new line
        std::cout << std::endl;
    }
}