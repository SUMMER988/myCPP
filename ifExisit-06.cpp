#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

std::set<std::string> readSubstringsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::set<std::string> substrings;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return substrings;
    }

    std::string substring;
    while (std::getline(file, substring)) {
        substrings.insert(substring);
    }

    file.close();
    return substrings;
}

std::pair<std::vector<std::string>, std::vector<std::string>>
fileContainsSubstrings(const std::string& filename,
                       const std::set<std::string>& substrings) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> foundSubstrings;
    std::vector<std::string> notFoundSubstrings;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return std::make_pair(foundSubstrings, notFoundSubstrings);
    }

    for (const auto& substring : substrings) {
        bool found = false;
        file.clear();
        file.seekg(0, std::ios::beg);

        while (std::getline(file, line)) {
            std::string lowercaseLine = line;
            std::transform(lowercaseLine.begin(), lowercaseLine.end(),
                           lowercaseLine.begin(), ::tolower);
            std::string lowercaseSubstring = substring;
            std::transform(lowercaseSubstring.begin(), lowercaseSubstring.end(),
                           lowercaseSubstring.begin(), ::tolower);
            if (lowercaseLine.find(lowercaseSubstring) != std::string::npos) {
                found = true;
                foundSubstrings.push_back(substring);
            }
        }
        if (!found) {
            notFoundSubstrings.push_back(substring);
        }
    }

    file.close();
    return std::make_pair(foundSubstrings, notFoundSubstrings);
}

int main() {
    std::string filepath =
        "C:\\Users\\admin\\.config\\clash\\profiles\\file-0307.yml";

    std::set<std::string> substrings = readSubstringsFromFile("SUBSTRINGS.TXT");

    if (substrings.empty()) {
        return 1;
    }

    auto results = fileContainsSubstrings(filepath, substrings);
    const auto& foundSubstrings = results.first;
    const auto& notFoundSubstrings = results.second;

    std::ofstream outputFile(
        "C:\\Users\\admin\\.config\\clash\\profiles\\RESULTS_00.TXT");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file : " << std::endl;
        return 1;
    }

    std::cout << "Substrings found in file:" << std::endl;
    outputFile << "Substrings found in file:" << std::endl;
    for (const auto& FoundSubstring : foundSubstrings) {
        std::cout << FoundSubstring << std::endl;
        outputFile << FoundSubstring << std::endl;
    }

    std::cout << "Substrings not found in file:" << std::endl;
    outputFile << "Substrings not found in file:" << std::endl;
    for (const auto& notFoundSubstring : notFoundSubstrings) {
        std::cout << notFoundSubstring << std::endl;
        outputFile << notFoundSubstring << std::endl;
    }

    outputFile.close();

    std::cout << "Results have been stored in file RESULTS_00" << std::endl;

    return 0;
}
