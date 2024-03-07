#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

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

    // Iterate over each substring
    for (const auto& substring : substrings) {
        bool found = false;
        file.clear();
        file.seekg(0, std::ios::beg);  // Reset file pointer to the beginning

        while (std::getline(file, line)) {
            // Convert the line and substring to lowercase for case-insensitive
            // comparison
            std::string lowercaseLine = line;
            std::transform(lowercaseLine.begin(), lowercaseLine.end(),
                           lowercaseLine.begin(), ::tolower);
            std::string lowercaseSubstring = substring;
            std::transform(lowercaseSubstring.begin(), lowercaseSubstring.end(),
                           lowercaseSubstring.begin(), ::tolower);

            if (lowercaseLine.find(lowercaseSubstring) != std::string::npos) {
                found = true;
                foundSubstrings.push_back(substring);
                break;  // No need to check further if substring is found
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
    std::string substringsInput;

    std::cout << "Enter space-separated substrings to search in the file: ";
    std::getline(std::cin, substringsInput);

    std::istringstream iss(substringsInput);
    std::set<std::string> substrings;
    std::string substring;
    while (iss >> substring) {
        substrings.insert(substring);
    }

    auto results = fileContainsSubstrings(filepath, substrings);
    const auto& foundSubstrings = results.first;
    const auto& notFoundSubstrings = results.second;

    std::ofstream outputFile("RESULTS-00.TXT");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    std::cout << "Substrings found in file:" << std::endl;
    outputFile << "Substrings found in file:" << std::endl;
    for (const auto& foundSubstring : foundSubstrings) {
        std::cout << foundSubstring << std::endl;
        outputFile << foundSubstring << std::endl;
    }

    std::cout << "Substrings not found in file:" << std::endl;
    outputFile << "Substrings not found in file:" << std::endl;
    for (const auto& notFoundSubstring : notFoundSubstrings) {
        std::cout << notFoundSubstring << std::endl;
        outputFile << notFoundSubstring << std::endl;
    }

    outputFile.close();

    std::cout << "Results have been stored in \"RESULTS-00.TXT\"" << std::endl;

    return 0;
}
