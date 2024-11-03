#include <iostream>
#include <chrono>
#include <thread>

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}