#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream outputFile("MODIFY_STRING.TXT");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    std::string original = "Peach-register-*iXjPDOVcEaqMhz-*vlZmBX-K15rV-PHq";

    size_t pos1 = original.find('*');
    size_t pos2 = original.find('*', pos1 + 1);

    if (pos1 != std::string::npos && pos2 != std::string::npos) {
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            std::string modified = original;
            modified[pos1] = c1;
            for (char c2 = '0'; c2 <= '9'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
        }

        for (char c1 = 'A'; c1 <= 'Z'; ++c1) {
            std::string modified = original;
            modified[pos1] = c1;
            for (char c2 = '0'; c2 <= '9'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
        }

        for (char c1 = '0'; c1 <= '9'; ++c1) {
            std::string modified = original;
            modified[pos1] = c1;
            for (char c2 = '0'; c2 <= '9'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
            for (char c2 = 'A'; c2 <= 'Z'; ++c2) {
                modified[pos2] = c2;
                outputFile << modified << std::endl;
            }
        }
    }

    outputFile.close();

    std::cout << "Results have been stored in MODIFY_STRING.TXT" << std::endl;

    return 0;
}
