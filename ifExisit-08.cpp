#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
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

std::string getFileCreationDate(const std::string& filePath) {
    struct stat result;
    if (stat(filePath.c_str(), &result) == 0) {
        auto creationTime =
            std::chrono::system_clock::from_time_t(result.st_ctime);
        auto time = std::chrono::system_clock::to_time_t(creationTime);
        std::string creationDate = std::ctime(&time);
        // Remove the trailing newline character from the creation date
        creationDate.pop_back();
        return creationDate;
    }
    return "Unknown";
}

long long getNumericalDate(const std::string& creationDate) {
    // Example creationDate format: "Sat Mar 09 13:13:44 2024"
    std::tm tm;
    std::istringstream ss(creationDate);
    ss >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");
    if (ss.fail()) {
        return -1;  // Parsing failed
    }

    long long numericalDate = (tm.tm_year + 1900) * 10000000000LL +
                              (tm.tm_mon + 1) * 100000000LL +
                              tm.tm_mday * 1000000LL + tm.tm_hour * 10000LL +
                              tm.tm_min * 100LL + tm.tm_sec;
    return numericalDate;
}

void printMatchingFiles(
    const std::vector<std::pair<std::string, std::string>>& matchingFiles) {
    for (const auto& file : matchingFiles) {
        std::cout << file.first << " (" << getNumericalDate(file.second) << ")"
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

    std::vector<std::pair<std::string, std::string>> matchingFiles;

    DIR* dir = opendir(folderPath.c_str());
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_REG) {  // Regular file
                std::string filePath = folderPath + "\\" + entry->d_name;
                for (const auto& fileName : fileNamesToSearch) {
                    if (fileContainsString(filePath, fileName)) {
                        std::string creationDate =
                            getFileCreationDate(filePath);
                        matchingFiles.emplace_back(entry->d_name, creationDate);
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
    printMatchingFiles(matchingFiles);

    return 0;
}
