#include <fstream>
#include <iostream>
#include <string>

bool fileContainsString(const std::string& filepath, const std::string& str) {
    std::ifstream file(filepath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filepath << std::endl;
        return false;
    }

    while (std::getline(file, line)) {
        if (line.find(str) != std::string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int main() {
    std::string filepath =
        "C:\\Users\\admin\\.config\\clash\\profiles\\file-0307.yml";
    std::string str;

    std::cout << "Enter strings to search in the file. Press Enter with an "
                 "empty line to stop."
              << std::endl;

    while (true) {
        std::cout << "Enter a string: ";
        std::getline(std::cin, str);

        if (str.empty()) {
            break;
        }

        if (fileContainsString(filepath, str)) {
            std::cout << "File contains the string \"" << str << "\""
                      << std::endl;
        } else {
            std::cout << "File does not contain the string \"" << str << "\""
                      << std::endl;
        }
    }

    return 0;
}
