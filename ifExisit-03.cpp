#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void combineIntoOneLine(const std::string& inputFilename,
                        const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file: " << inputFilename
                  << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file: " << outputFilename
                  << std::endl;
        return;
    }

    std::ostringstream combinedContentStream;
    std::string line;

    while (std::getline(inputFile, line)) {
        combinedContentStream
            << line << " ";  // Append each line followed by a whitespace
    }

    // Write the combined content to the output file
    outputFile << combinedContentStream.str();

    inputFile.close();
    outputFile.close();

    std::cout << "Contents of \"" << inputFilename << "\" stored in \""
              << outputFilename << "\" with whitespace separation."
              << std::endl;
}

int main() {
    std::string inputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\NumbersAndServer.txt";
    std::string outputFilename =
        "C:\\Users\\admin\\.config\\clash\\profiles\\separatedBySpaces.txt";

    combineIntoOneLine(inputFilename, outputFilename);

    return 0;
}
