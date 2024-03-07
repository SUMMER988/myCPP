#include <fstream>
#include <iostream>
#include <string>

void generateCombinationsToFile(const std::string& input) {
    std::ofstream outputFile("0228_codes.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    for (char digit = '0'; digit <= '9'; ++digit) {
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            std::string result = input;
            size_t pos = result.find('*');
            if (pos != std::string::npos) {
                result[pos] = digit;
                pos = result.find('*', pos + 1);
            }
            if (pos != std::string::npos) {
                result[pos] = letter;
                outputFile << result << std::endl;
            }
        }
    }

    outputFile.close();
    std::cout << "Results saved to 0228_codes.txt" << std::endl;
}

int main() {
    std::string input;
    std::cout << "Enter a string with two '*' characters: ";
    std::cin >> input;

    generateCombinationsToFile(input);

    return 0;
}
