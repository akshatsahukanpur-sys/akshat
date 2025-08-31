#include <iostream>
#include <limits>

int main() {
    std::cout << "Simple Calculator\n";
    bool keepGoing = true;

    while (keepGoing) {
        double a{}, b{};
        char op{};

        // Input first number
        std::cout << "\nEnter first number: ";
        while (!(std::cin >> a)) {
            std::cout << "Invalid number. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Input second number
        std::cout << "Enter second number: ";
        while (!(std::cin >> b)) {
            std::cout << "Invalid number. Try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Choose operation
        std::cout << "Choose operation (+, -, *, /): ";
        std::cin >> op;

        // Perform operation
        double result{};
        bool validOp = true;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0.0) {
                    std::cout << "Error: Division by zero is undefined.\n";
                    validOp = false;
                } else {
                    result = a / b;
                }
                break;
            default:
                std::cout << "Error: Unknown operation '" << op << "'.\n";
                validOp = false;
        }

        if (validOp) {
            std::cout << "Result: " << a << " " << op << " " << b << " = " << result << "\n";
        }

        // Ask to continue
        std::cout << "Do another calculation? (y/n): ";
        char choice{};
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') keepGoing = false;

        // clear leftover input if any
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Goodbye!\n";
    return 0;
}