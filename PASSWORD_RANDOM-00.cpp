#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

// Function to generate a random password of specified length
std::string generateRandomPassword(int length) {
    std::string charset =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(nullptr));  // Seed the random number generator
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
        std::cout << "Enter the length of the password (or enter any "
                     "non-integer value to exit): ";
    }
    return 0;
}
