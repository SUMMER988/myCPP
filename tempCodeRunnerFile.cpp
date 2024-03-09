#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool fileContainsString(const std::string& filePath,
                        const std::string& searchString) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line.find(searchString) != std::string::npos) {
                return true;
            }
        }
        file.close();
    }
    return false;
}

void writeMatchingFilesToFile(const std::vector<std::string>& matchingFiles) {
    std::ofstream outputFile("D:\\00FILES\\namesOfFile.txt");
    if (outputFile.is_open()) {
        for (const auto& fileName : matchingFiles) {
            outputFile << fileName << std::endl;
        }
        outputFile.close();
        std::cout << "Names of matching files have been written to "
                     "D:\\00FILES\\namesOfFile.txt."
                  << std::endl;
    } else {
        std::cerr << "Failed to open D:\\00FILES\\namesOfFile.txt for writing."
                  << std::endl;
    }
}

int main() {
    std::string folderPath = "C:\\Users\\admin\\.config\\clash\\profiles";
    std::vector<std::string> fileNamesToSearch;

    std::string fileName;
    std::cout << "Enter file names to search for (enter nothing to stop):"
              << std::endl;
    while (std::getline(std::cin, fileName) && !fileName.empty()) {
        fileNamesToSearch.push_back(fileName);
    }

    std::vector<std::string> matchingFiles;

    DIR* dir = opendir(folderPath.c_str());
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_REG) {  // Regular file
                std::string filePath = folderPath + "\\" + entry->d_name;
                for (const auto& fileName : fileNamesToSearch) {
                    if (fileContainsString(filePath, fileName)) {
                        matchingFiles.push_back(entry->d_name);
                        break;  // No need to check this file against other
                                // search strings
                    }
                }
            }
        }
        closedir(dir);
    } else {
        std::cerr << "Failed to open directory." << std::endl;
        return 1;
    }

    std::cout << "Files containing the specified strings:" << std::endl;
    for (const auto& fileName : matchingFiles) {
        std::cout << fileName << std::endl;
    }

    writeMatchingFilesToFile(matchingFiles);

    return 0;
}
