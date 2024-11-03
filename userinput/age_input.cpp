#include <iostream>


int age;

int main() {
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (age >= 18) {
        std::cout << "You are an adult." << std::endl;
    } else {
        std::cout << "You are not an adult." << std::endl;
    }
    return 0;
}
