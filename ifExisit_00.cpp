#include <fstream>
#include <iostream>
#include <regex>
#include <string>

void extractAndStoreData(const std::string& filepath) {
    std::ifstream file(filepath);
    std::ofstream output(
        "C:\\Users\\admin\\.config\\clash\\profiles\\NumbersAndServer.txt");

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filepath << std::endl;
        return;
    }
    if (!output.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    std::string line;
    std::regex portPattern("port: (\\d+)");
    std::regex serverPattern("server: (\\S+)");
    std::smatch match;

    // while (std::getline(file, line)) {
    //     if (std::regex_search(line, match, portPattern)) {
    //         output << "Port: " << match[1].str() << std::endl;
    //     }
    //     if (std::regex_search(line, match, serverPattern)) {
    //         output << "Server: " << match[1].str() << std::endl;
    //     }
    // }
    while (std::getline(file, line)) {
        if (std::regex_search(line, match, portPattern)) {
            output << match[1].str() << std::endl;
        }
    }

    file.close();
    output.close();
    std::cout << "Numbers and server addresses extracted and stored in "
                 "NumbersAndServer.txt"
              << std::endl;
}

int main() {
    std::string filepath =
        "C:\\Users\\admin\\.config\\clash\\profiles\\file-0307.yml";

    extractAndStoreData(filepath);

    return 0;
}
