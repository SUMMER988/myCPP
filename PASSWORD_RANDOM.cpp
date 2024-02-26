#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Function to generate a random password of specified length
std::string generateRandomPassword(int length) {
    // Define characters to choose from
    std::string charset =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Seed the random number generator
    srand(time(0));

    // Generate password
    std::string password;
    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charset.size()];
    }

    return password;
}

int main() {
    int length;
    std::cout << "Enter the length of the password: ";
    while (std::cin >> length) {
        std::string password = generateRandomPassword(length);
        std::cout << "Generated password: " << password << std::endl;
        std::cout << "Enter the length of the password: ";
    }

    return 0;
}
