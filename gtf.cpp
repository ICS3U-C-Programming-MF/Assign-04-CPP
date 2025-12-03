// Copyright Maximiliano Fairman
// Nov 11th, 2025
// allrights reserved
// This program asks the user for two numbers.
// It then calculates and displays the
// Lowest Common Multiple of the two numbers.

#include <iostream>
#include <string>

int main() {
    // Say hello and tell the user what the program does
    std::cout << "\nHello user\n";
    std::cout << "Please input your 2 numbers.\n";
    std::cout << "To get the lowest common multiple of them.\n\n";

    std::string keep_running = "yes";  // This lets the user run the program again

    // Keep going as long as the user types "yes"
    while (keep_running == "yes") {
        int num1 = 0, num2 = 0;  // The two numbers the user will enter
        bool ok = false;         // This becomes true only when both numbers are good

        // Keep asking for numbers until the user types valid whole numbers
        while (!ok) {
            std::cout << "Enter the first whole number: ";

            // Try to read the first number
            if (!(std::cin >> num1)) {
                std::cout << "ERROR: You must ";
                std::cout << "enter whole numbers only. Try again.\n";

                // Fix bad input by clearing error and throwing away the bad text
                std::cin.clear();
                std::string throwaway;
                std::cin >> throwaway;

                continue;  // Restart the loop
            }

            std::cout << "Enter the second whole number: ";

            // Try to read the second number
            if (!(std::cin >> num2)) {
                std::cout << "ERROR: You must";
                std::cout << "enter whole numbers only. Try again.\n\n";

                std::cin.clear();
                std::string throwaway;
                std::cin >> throwaway;

                continue;  // Restart the loop
            }

            // Check if numbers are positive
            if (num1 <= 0 || num2 <= 0) {
                std::cout << "Both numbers must";
                std::cout << "be GREATER than zero. Try again.\n\n";
            } else {
                ok = true;  
            }
        }

        // CALCULATION OF LCM
        // Start with the big number and keep counting until we find a number
        // that both numbers divide evenly into.
        int lcm = (num1 > num2) ? num1 : num2;

        while (true) {
            // If lcm divides evenly by both numbers, we found our answer
            if (lcm % num1 == 0 && lcm % num2 == 0) {
                break;  
            }
            lcm++;  // Try the next number
        }

        // Tell the user the answer
        std::cout << "\nThe Lowest Common Multiple of "
                  << num1 << " and " << num2
                  << " is: " << lcm << "\n";

        // Ask if they want to repeat the program
        std::cout << "\nWould you like to calculate another LCM?\n";
        std::cout << "Enter 'yes' to continue or anything else to quit: ";
        std::cin >> keep_running;

        // If not "yes", say goodbye
        if (keep_running != "yes") {
            std::cout << "\nThank you for using the LCM Calculator!\n";
        }
    }
}
