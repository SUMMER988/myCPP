#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Function to count the occurrences of a word in a string
int countOccurrences(const std::string& text, const std::string& word) {
    int count = 0;
    size_t pos = text.find(word, 0);
    while (pos != std::string::npos) {
        count++;
        pos = text.find(word, pos + word.size());
    }
    return count;
}

// Function to read the contents of a file, count occurrences of "success" or
// "Success", and output the count

void readFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    std::string line;
    std::string content;

    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    while (std::getline(infile, line)) {
        content += line + '\n';
    }
    infile.close();

    int count = countOccurrences(content, "success") +
                countOccurrences(content, "Success");

    std::cout << "The word 'success' or 'Success' occurs " << count
              << " times in " << filename << std::endl;
}

// Function to copy the contents of a file and paste them into the file for a
// specified number of times

void copyAndPasteFile(const std::string& filename, int numIterations) {
    std::ifstream infile(filename);
    std::string line;
    std::vector<std::string> originalData;

    while (std::getline(infile, line)) {
        originalData.push_back(line);
    }

    infile.close();

    std::ofstream outfile(filename, std::ios::app);

    for (int i = 0; i < numIterations; i++) {
        for (const auto& line : originalData) {
            outfile << line << std::endl;
        }
    }

    outfile.close();
}

int main() {
    std::string filename = "0224_Array.txt";  // Modified filename
    // int numIterations;

    // std::cout << "Enter the number of times to copy and paste the file: ";
    // std::cin >> numIterations;
    int numIterations = 1;

    copyAndPasteFile(filename, numIterations);

    std::cout << "Copied and pasted " << numIterations << " times."
              << std::endl;

    // Read and output the contents of the file
    readFromFile(filename);

    return 0;
}
