#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void detectDuplicateContent(const std::string& filepath) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filepath << std::endl;
        return;
    }

    std::map<std::string, int>
        lineOccurrences;  // Map to store line occurrences

    std::string line;
    while (std::getline(file, line)) {
        // Increment the occurrence count for the current line
        lineOccurrences[line]++;
    }

    file.close();

    bool foundRepeatedContent = false;

    // Print each repeated line along with its occurrence count
    std::cout << "Repeated content in file: " << filepath << std::endl;
    for (const auto& pair : lineOccurrences) {
        if (pair.second > 1) {
            std::cout << "Content: " << pair.first
                      << ", Occurrences: " << pair.second << std::endl;
            foundRepeatedContent = true;
        }
    }

    if (!foundRepeatedContent) {
        std::cout << "No repeated content found." << std::endl;
    }
}

int main() {
    std::string filepath =
        "C:\\Users\\admin\\.config\\clash\\profiles\\NumbersAndServer.txt";

    detectDuplicateContent(filepath);

    return 0;
}
