#include <iostream>
#include <limits>
#include <random>

int main() {
    // Random number in [1,100]
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int secret = dist(gen);

    std::cout << "=== Number Guessing Game ===\n";
    std::cout << "I'm thinking of a number between 1 and 100.\n";

    int guess;
    int attempts = 0;

    while (true) {
        std::cout << "Enter your guess: ";

        // Robust input: handle non-integers
        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid integer.\n";
            continue;
        }

        ++attempts;

        if (guess < secret) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > secret) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Correct! You got it in " << attempts << " attempts.\n";
            break;
        }
    }

    return 0;
}